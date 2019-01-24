#include "CalcuPmeasure.h"

extern int iSize, iRank, QubitNum, halfNum;

bool CalcuPmeasure::integerToBinary(size_t num, stringstream &ssRet, int ret_len)
{
    for (int i = ret_len - 1; i > -1; i--)
    {
        ssRet << ((num >> i) & 1);
    }
    return true;
}

void CalcuPmeasure::getAvgBinary(long long num, size_t QubitNum)
{
    size_t half_qubit = QubitNum / 2;
    long long lower_mask = (1 << half_qubit) - 1;
    lowPosition = (num & lower_mask);
    highPosition = (num - lowPosition) >> half_qubit;
}

void CalcuPmeasure::calcuPmeasure(QList Qcircuit, vector<map<int, QNode *>> splitQlistVector)
{
    MPI_Status status;
    if (splitQlistVector.size() > iSize / 2)
    {
        vector<complex<double>> lastResultState(pmeasure_num.size(), 0);
        stringstream ssRet;
        long long avg = splitQlistVector.size() / iSize;
        vector<vector<QStat>> calculateMap_vector;
        for (long long j = 0; j < avg; j++)
        {
            auto qListMap = splitQlistVector[iRank * avg + j];

            vector<QStat> calculateMap;
            for (auto iter = qListMap.begin(); iter != qListMap.end(); iter++)
            {
                QNode *sub = iter->second;
                QuantumGateParam *pQuantumProParam = new QuantumGateParam();
                pQuantumProParam->setQBitNum(QubitNum / 2);
                QuantumGates *pQGate = new CPUQuantumGates();
                pQGate->initState(pQuantumProParam);
                Qcircuit.TraverseAll(sub, pQuantumProParam, pQGate);
                calculateMap.emplace_back(pQGate->getQState());

                delete (pQuantumProParam);
                delete (pQGate);
            }

            calculateMap_vector.emplace_back(calculateMap);
        }

        vector<complex<double>> addResult_vector(pmeasure_num.size(), 0);
        for (int y = 0; y < pmeasure_num.size(); y++)
        {

            complex<double> addResult(0, 0);
            getAvgBinary(y, QubitNum);
            for (int i = 0; i < calculateMap_vector.size(); i++)
            {
                complex<double> multiResult(1, 0);
                if (calculateMap_vector[i].size() > 1)
                {
                    multiResult = calculateMap_vector[i][0][lowPosition] * calculateMap_vector[i][1][highPosition];
                }
                else
                {
                    multiResult = calculateMap_vector[i][0][lowPosition] * (highPosition == 0 ? 1.0 : 0.0);
                }

                addResult = addResult + multiResult;
            }
            addResult_vector[y] = addResult;
        }

        MPI_Barrier(MPI_COMM_WORLD);
        MPI_Reduce(&addResult_vector[0], &lastResultState[0], pmeasure_num.size(), MPI_C_DOUBLE_COMPLEX, MPI_SUM, 0, MPI_COMM_WORLD);
        MPI_Barrier(MPI_COMM_WORLD);
        if (iRank == 0)
        {
            FILE *fp = fopen("result.txt", "w+");
            for (int i = 0; i < lastResultState.size(); i++)
            {

                stringstream ss;
                integerToBinary(i, ss, QubitNum);
                double pmeasure_value = lastResultState[i].real() * lastResultState[i].real() + lastResultState[i].imag() * lastResultState[i].imag();
                fprintf(fp, "%s: %e\r\n", ss.str().c_str(), pmeasure_value);
            }
            fclose(fp);
        }
    }
    else
    {
        QuantumGateParam *pQuantumProParam = new QuantumGateParam();
        pQuantumProParam->setQBitNum(QubitNum / 2);
        QuantumGates *pQGate = new CPUQuantumGates();
        pQGate->initState(pQuantumProParam);
        int stateSize = pQGate->getQStateSize();
        complex<double> highPos(1, 0);
        complex<double> lowPos(1, 0);
        complex<double> multiResult;
        vector<complex<double>> lastResultState(1000);
        bool hasRun = false;
        for (int i = 0; i < splitQlistVector.size(); i++)
        {
            auto qListMap = splitQlistVector[i];
            for (auto iter = qListMap.begin(); iter != qListMap.end(); iter++)
            {
                int j = iter->first;

                if (iRank == i * 2 + j)
                {
                    hasRun = true;
                    QNode *sub = iter->second;
                    Qcircuit.TraverseAll(sub, pQuantumProParam, pQGate);
                }
            }
        }
        QStat mvQuantumStat = pQGate->getQState();
        QStat destState(stateSize, 0);
        vector<complex<double>> allStates(pmeasure_num.size());

        if (iRank % 2 == 1)
        {
            if (hasRun)
            {
                MPI_Sendrecv(&mvQuantumStat[0], stateSize, MPI_C_DOUBLE_COMPLEX, iRank - 1, 1,
                             &destState[0], stateSize, MPI_C_DOUBLE_COMPLEX, iRank - 1, 1, MPI_COMM_WORLD, &status);
            }
            else
            {
                QStat temp(stateSize, 1);
                temp[0] = 1;
                MPI_Sendrecv(&temp[0], stateSize, MPI_C_DOUBLE_COMPLEX, iRank - 1, 1,
                             &destState[0], stateSize, MPI_C_DOUBLE_COMPLEX, iRank - 1, 1, MPI_COMM_WORLD, &status);
            }
        }
        else
        {

            MPI_Sendrecv(&mvQuantumStat[0], stateSize, MPI_C_DOUBLE_COMPLEX, iRank + 1, 1,
                         &destState[0], stateSize, MPI_C_DOUBLE_COMPLEX, iRank + 1, 1, MPI_COMM_WORLD, &status);

            for (int i = 0; i < pmeasure_num.size(); i++)
            {
                highPos = mvQuantumStat[lowPosition];
                lowPos = destState[highPosition];
                multiResult = highPos * lowPos;
                allStates[i] = multiResult;
            }
        }

        if (iRank % 2 == 0)
        {
            MPI_Reduce(&allStates[0], &lastResultState[0], 1000, MPI_C_DOUBLE_COMPLEX, MPI_SUM, 0, MPI_COMM_WORLD);
        }
        else
        {
            memset(&allStates[0], 0, sizeof(complex<double>) * pmeasure_num.size());
            MPI_Reduce(&multiResult, &lastResultState, 1, MPI_C_DOUBLE_COMPLEX, MPI_SUM, 0, MPI_COMM_WORLD);
        }

        if (iRank == 0)
        {
            FILE *fp = fopen("result.txt", "w+");
            for (int i = 0; i < lastResultState.size(); i++)
            {
                stringstream ss;
                integerToBinary(i, ss, QubitNum);
                double pmeasure_value = lastResultState[i].real() * lastResultState[i].real() + lastResultState[i].imag() * lastResultState[i].imag();
                fprintf(fp, "%s: %e\r\n", ss.str().c_str(), pmeasure_value);
            }

            fclose(fp);
        }
    }
}

void CalcuPmeasure::setPmeasure_Num(vector<size_t> pmeasure_num_vector)
{
    this->pmeasure_num = pmeasure_num_vector;
}

vector<size_t> CalcuPmeasure::getPmeasure_Num()
{
    return pmeasure_num;
}