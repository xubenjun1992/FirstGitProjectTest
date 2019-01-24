#include <iostream>
#include <fstream>
#include <map>
#include <mpi.h>
#include <string.h>
#include <vector>
#include "LinkedListController.h"
#include "QuantumGates.h"
#include "CPUQuantumGates.h"
#include "QParamStruct.h"

using namespace std;

class CalcuPmeasure
{
  public:
    /*************************************************************************************************************
    Name:        integerToBinary
    Description: get binary
    Argin:       num  ssRet ret_len
    Argout:      ssRet
    return:      bool
    *************************************************************************************************************/
    bool integerToBinary(size_t num, stringstream &ssRet, int ret_len);

    /*************************************************************************************************************
    Name:        getAvgBinary
    Description: get half of the binary integer of the current number
    Argin:       num  QubitNum
    Argout:      lowPosition highPosition
    return:      void
    *************************************************************************************************************/
    void getAvgBinary(long long num, size_t QubitNum);

    /*************************************************************************************************************
    Name:        calcuPmeasure
    Description: Pmeasure for calculating the median of a set
    Argin:       num  QubitNum
    Argout:      lowPosition highPosition
    return:      void
    *************************************************************************************************************/
    void calcuPmeasure(QList Qcircuit, vector<map<int, QNode *>> splitVector);

    long long getLowPosition();

    long long getHighPosition();

    void setPmeasure_Num(vector<size_t> pmeasure_num_vector);

    vector<size_t> getPmeasure_Num();

  private:
    long long lowPosition;
    long long highPosition;
    vector<size_t> pmeasure_num;
};
