#include <iostream>
#include <fstream>
#include "./QRunesParser/LinkedListController.h"
#include "./QRunesParser/QRunesParserAPI.h"
#include "./QRunesParser/QParamStruct.h"
#include <map>
#include "./QRunesParser/SingletonForType.h"
#include "./QRunesParser/QuantumGates.h"
#include "./QRunesParser/CPUQuantumGates.h"
#include <mpi.h>
#include <string.h>
#include "./QRunesParser/TreeQList.h"
#include "time.h"
#include "./QRunesParser/CalcuPmeasure.h"

#define PMEASURE_NUM 256

using namespace std;

int iSize, iRank;
int QubitNum;
int halfNum;

int main()
{
	QList Qcircuit;
	string s1 = "./QRunes";
	MPI_Init(nullptr, nullptr);
	MPI_Comm_size(MPI_COMM_WORLD, &iSize);
	MPI_Comm_rank(MPI_COMM_WORLD, &iRank);
	QubitNum = QRunesParser(s1, Qcircuit, iRank);
	cout << QubitNum << endl;
	if (QubitNum < 0 || QubitNum % 2 != 0)
	{
		throw exception();
	}

	halfNum = QubitNum / 2;
	map<int,int> keyMap;
	keyMap.insert({19,23});
	keyMap.insert({11,5});
	TreeQList treeQList;
	treeQList.setKeyCode(keyMap);
	treeQList.createQList(&Qcircuit);
	vector<map<int, QNode *>> splitQlistVector = treeQList.getSplitQlistVector();
	cout << splitQlistVector.size() << endl;
	CalcuPmeasure calcuPmeasure;
	vector<size_t> pmeasure_num_vec;
	for(size_t i = 0; i < 1000000; i++)
	{
		pmeasure_num_vec.emplace_back(rand());
	}
	calcuPmeasure.setPmeasure_Num(pmeasure_num_vec);
	calcuPmeasure.calcuPmeasure(Qcircuit,splitQlistVector);

	MPI_Finalize();

	return 0;
}
