/******************************************************************************
Copyright (c) 2017-2018 Origin Quantum Computing Co., Ltd.. All Rights Reserved.


 
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at 

 	http://www.apache.org/licenses/LICENSE-2.0 
 
Unless required by applicable law or agreed to in writing, software

distributed under the License is distributed on an "AS IS" BASIS,

WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.

See the License for the specific language
governing permissions and 
limitations under the License.
************************************************************************/
#include "LinkedListController.h"
#include <algorithm>
#include <iostream>
#include "parser.h"
#include "QuantumInstructionGet.h"
#include "SingletonForType.h"
#include "CPUQuantumGates.h"

extern "C"
{
	void yyerror(const char *s);
};
/**************************************************
 * constructor
 **************************************************/
QList::QList()
{
	/* empty */
}

QList::QList(const QList &obj)
{
	qList = obj.qList;
}

/*************************************************
* class     QList
* clear all contents in linkedlist
***************************************************/
void QList::listClear()
{
	this->qList.subListClear();
}

/**************************************************
 * class:       QList
 * name:        nodeInsert
 * visible:     no
 * arg:         QNode* (newly created note)
 * return:      n/a
 **************************************************/
void QList::nodeInsert(QNode *newGateNode)
{
	// if it is not a measure node, assign the controlList to it
	if (newGateNode->gateSpecifier != MEASURE_GATE)
	{
		((GateNode *)newGateNode)->controlList.assign(this->controlList.begin(), this->controlList.end());
	}
	// if true, that means handling the root list
	if (daggerStack.empty())
	{
		newGateNode->prev = this->qList.cursor;
		this->qList.cursor->next = newGateNode;
		this->qList.cursor = newGateNode;
	}
	else
	{
		if (newGateNode->gateSpecifier != MEASURE_GATE &&
			newGateNode->gateSpecifier != PMEASURE_GATE)
		{
			((GateNode *)newGateNode)->isDagger =
				daggerStack.top()->daggerLevel % 2 == 0 ? true : false;
		}
		newGateNode->prev = daggerStack.top()->cursor;
		daggerStack.top()->cursor->next = newGateNode;
		daggerStack.top()->cursor = newGateNode;
	}
}

/*************************************************
 * class:    QList
 * name      gateInsert
 * overload  1/3
 * visible   yes
 * arg       int gateSpecifier, int operand
 * return   
 **************************************************/
bool QList::gateInsert(int gateSpecifier, int operand)
{
	SingleGateNode *newGateNode = new SingleGateNode();
	if (newGateNode == NULL)
	{
		return false;
	}
	// init the parameters
	newGateNode->gateSpecifier = gateSpecifier;
	newGateNode->next = NULL;
	newGateNode->opQubit = operand;
	if (controlStack.size() > 0)
	{
		if (count(controlList.begin(), controlList.end(), operand) > 0)
		{
			yyerror(DUPLICATE_CONTROLLER_ERROR);
		}
	}
	nodeInsert(newGateNode);
	return true;
}

/*************************************************
* class:    QList
* name      gateInsert
* overload  2/3
* visible   yes
* arg       int gateSpecifier, int operand1, int operand2
* return
***************************************************/
bool QList::gateInsert(int gateSpecifier, int operand1, int operand2)
{
	DoubleGateNode *newGateNode = new DoubleGateNode();
	if (newGateNode == NULL)
	{
		return false;
	}

	// init the parameters
	newGateNode->gateSpecifier = gateSpecifier;
	newGateNode->next = NULL;
	newGateNode->opQubit1 = operand1;
	newGateNode->opQubit2 = operand2;
	if (controlStack.size() > 0)
	{
		if (count(controlList.begin(), controlList.end(), operand1) > 0 || count(controlList.begin(), controlList.end(), operand2) > 0)
		{
			yyerror(DUPLICATE_CONTROLLER_ERROR);
		}
	}
	nodeInsert(newGateNode);
	return true;
}

/*************************************************
* class:    QList
* name      gateInsert
* overload  3/3
* visible   yes
* arg       int gateSpecifier, int operand1, int operand2, int operand3
* return
***************************************************/
bool QList::gateInsert(int gateSpecifier, int operand1, int operand2, int operand3)
{
	TripleGateNode *newGateNode = new TripleGateNode();
	if (newGateNode == NULL)
	{
		return false;
	}

	// init the parameters
	newGateNode->gateSpecifier = gateSpecifier;
	newGateNode->next = NULL;
	newGateNode->opQubit1 = operand1;
	newGateNode->opQubit2 = operand2;
	newGateNode->opQubit3 = operand3;
	if (controlStack.size() > 0)
	{
		if (count(controlList.begin(), controlList.end(), operand1) > 0 || count(controlList.begin(), controlList.end(), operand2) > 0 || count(controlList.begin(), controlList.end(), operand3) > 0)
		{
			yyerror(DUPLICATE_CONTROLLER_ERROR);
		}
	}
	nodeInsert(newGateNode);
	return true;
}

/*************************************************
* class:    QList
* name      angleGateInsert
* overload  1/2
* visible   yes
* arg       int gateSpecifier, int operand, double angle
* return
***************************************************/
bool QList::angleGateInsert(int gateSpecifier, int operand, double angle)
{
	SingleAngleGateNode *newGateNode = new SingleAngleGateNode();
	if (newGateNode == NULL)
	{
		return false;
	}

	// init the parameters
	newGateNode->gateSpecifier = gateSpecifier;
	newGateNode->next = NULL;
	newGateNode->opQubit = operand;
	newGateNode->angle = angle;
	if (controlStack.size() > 0)
	{
		if (count(controlList.begin(), controlList.end(), operand) > 0)
		{
			yyerror(DUPLICATE_CONTROLLER_ERROR);
		}
	}
	nodeInsert(newGateNode);
	return true;
}

/*************************************************
* class:    QList
* name      angleGateInsert
* overload  2/2
* visible   yes
* arg       int gateSpecifier, int operand1, int operand2, double angle
* return    errmsg
***************************************************/
bool QList::angleGateInsert(int gateSpecifier, int operand1, int operand2, double angle)
{
	DoubleAngleGateNode *newGateNode = new DoubleAngleGateNode();
	if (newGateNode == NULL)
	{
		return false;
	}

	// init the parameters
	newGateNode->gateSpecifier = gateSpecifier;
	newGateNode->next = NULL;
	newGateNode->opQubit1 = operand1;
	newGateNode->opQubit2 = operand2;
	newGateNode->angle = angle;
	if (controlStack.size() > 0)
	{
		if (count(controlList.begin(), controlList.end(), operand1) > 0 || count(controlList.begin(), controlList.end(), operand2) > 0)
		{
			yyerror(DUPLICATE_CONTROLLER_ERROR);
		}
	}
	nodeInsert(newGateNode);
	return true;
}

/*************************************************
* class     QList
* name      measureInsert
* visible   yes
* arg       int gateSpecifier, int operand, int creg
* return    errmsg
***************************************************/
bool QList::measureInsert(int gateSpecifier, int operand, int creg)
{
	MeasureNode *newGateNode = new MeasureNode();
	if (newGateNode == NULL)
	{
		return false;
	}

	newGateNode->gateSpecifier = gateSpecifier;
	newGateNode->next = NULL;
	newGateNode->opQubit = operand;
	newGateNode->creg = creg;

	if (this->daggerStack.size() != 0 || this->controlList.size() != 0)
	{
		return false;
	}
	else
	{
		if (this->qList.cursor->next == NULL)
		{
			this->qList.cursor->next = newGateNode;
			this->qList.cursor = newGateNode;
			return true;
		}
		else
		{
			return false;
		}
	}
}

/*************************************************
* class     QList
* name      pmeasureInsert
* visible   yes
* arg       vector<int> vecint_pmeasure_list
* return    errmsg
***************************************************/
bool QList::pmeasureInsert(vector<int> vecint_pmeasure_list)
{
	pMeasureNode *newGateNode = new pMeasureNode();
	if (newGateNode == NULL)
	{
		return false;
	}

	newGateNode->gateSpecifier = PMEASURE_GATE;
	newGateNode->next = NULL;
	newGateNode->vecint_pmeasure_list.assign(vecint_pmeasure_list.begin(),
											 vecint_pmeasure_list.end());

	if (this->daggerStack.size() != 0 || this->controlList.size() != 0)
	{
		return false;
	}
	else
	{
		if (this->qList.cursor->next == NULL)
		{
			this->qList.cursor->next = newGateNode;
			this->qList.cursor = newGateNode;
			return true;
		}
		else
		{
			return false;
		}
	}
}

/*************************************************
* class     QList
* name      daggerInsert
* visible   yes
* arg       n/a
* return    n/a
***************************************************/
void QList::daggerInsert()
{
	//  if true, that means handling the root list
	if (this->daggerStack.empty())
	{
		subQList *newQList = new subQList(1);
		daggerStack.push(newQList);
	}
	else
	{
		subQList *newQList = new subQList(this->daggerStack.top()->daggerLevel);
		daggerStack.push(newQList);
	}
}

/*************************************************
* class     QList
* name      daggerDelete
* visible   yes
* arg       n/a
* return    errmsg
***************************************************/
bool QList::daggerDelete()
{
	using std::cout;

	// if true, that means handling the root list, so enddagger is illegal
	if (daggerStack.empty())
		return false;

	subQList *topQList = this->daggerStack.top();
	daggerStack.pop();

	// if true, that means handling the root list
	if (daggerStack.empty())
	{
		topQList->Reverse();
		this->qList.Merge(topQList);
	}
	else
	{
		// if true, dagger -> reverse
		// if not,  dagger dagger -> do nothing
		if (topQList->daggerLevel % 2 == 1)
		{
			topQList->Reverse();
		}
		daggerStack.top()->Merge(topQList);
	}
	return true;
}

/*************************************************
* class     QList
* name      ControlInsert
* visible   yes
* arg       int
* return    errmsg
***************************************************/
// bool QList::ControlInsert(int operand)
// {
//     // if there is duplicate control operand, that's illegal
//     if (std::count(controlList.begin(), controlList.end(), operand) >= 1)

//     {
// 		yyerror(DUPLICATE_CONTROLLER_ERROR);
//         return false;
//     }
//     else
//     {
//         controlList.push_back(operand);
//         return true;
//     }
// }

bool QList::ControlInsert1(vector<size_t> controll_list_vector)
{
	set<size_t> set;
	for (int i = 0; i < controll_list_vector.size(); i++)
	{
		set.insert(controll_list_vector[i]);
	}

	if (set.size() < controll_list_vector.size())
	{
		yyerror(DUPLICATE_CONTROLLER_ERROR);
		return false;
	}
	else
	{
		for (int i = 0; i < controlList.size(); i++)
		{
			if (count(controll_list_vector.begin(), controll_list_vector.end(), controlList[i]) > 1)
			{
				yyerror(DUPLICATE_CONTROLLER_ERROR);
				return false;
			}
		}

		controlList.insert(controlList.end(), controll_list_vector.begin(), controll_list_vector.end());
		controlStack.push(controll_list_vector);
		return true;
	}
}

/*************************************************
* class     QList
* name      ControlDelete
* visible   yes
* arg       int
* return    errmsg
***************************************************/
// bool QList::ControlDelete(int operand)
// {
//     // if there not existed, that's illegal
//     if (std::count(controlList.begin(), controlList.end(), operand) == 0)
//     {
//         return false;
//     }
//     else
//     {
//         // iterator traverse. when finded, delete and break the loop
//         for (vector<size_t>::iterator iter = controlList.begin(); iter != controlList.end(); iter++)
//         {
//             if ((*iter) == operand)
//             {
//                 controlList.erase(iter);
//                 break;
//             }
//         }
//     }
//     return true;
// }

bool QList::ControlDelete1(vector<size_t> controll_list_vector)
{
	// if there not existed, that's illegal
	set<size_t> set;
	for (int i = 0; i < controll_list_vector.size(); i++)
	{
		set.insert(controll_list_vector[i]);
	}

	if (set.size() < controll_list_vector.size())
	{
		yyerror(DUPLICATE_CONTROLLER_ERROR);
	}
	if (controlStack.empty())
	{
		yyerror(DUPLICATE_CONTROLLER_ERROR);
		return false;
	}

	if (controlStack.top() != controll_list_vector)
	{
		yyerror(DUPLICATE_CONTROLLER_ERROR);
		return false;
	}

	controlStack.pop();

	vector<size_t> lastVectorList; //中间变量

	sort(controlList.begin(), controlList.end());
	sort(controll_list_vector.begin(), controll_list_vector.end());
	set_difference(controlList.begin(), controlList.end(),
				   controll_list_vector.begin(), controll_list_vector.end(),
				   back_inserter(lastVectorList));

	controlList = lastVectorList;
	return true;
}

/*************************************************
* class     QList
* name      TraverseAll
* visible   yes
* arg       int
* return    n/a
* note      only for test. do a traverse and output opQubit
***************************************************/
void QList::TraverseAll(QNode *sub, QuantumGateParam *pQuantumProParam, QuantumGates *pQGate)
{
	QuantumInstructionGet *pQuantumInstructionGet = QuantumInstructionGet::getInstance();
	while (sub != NULL)
	{
		if (!pQuantumInstructionGet->transmit(sub, pQuantumProParam, pQGate))
		{
			break;
		}
		sub = sub->next;
	}
}

/*************************************************
* class     subQList
* default constructor
* overload  1/2
***************************************************/
subQList::subQList()
{
	QNode *headNode = new QNode();
	headNode->gateSpecifier = START;
	headNode->next = NULL;
	head = headNode;
	cursor = head;
	daggerLevel = 0;
}

/*************************************************
* class     subQList
* constructor
* arg       size_t oldDaggerLevel
* overload  2/2
* note      only call when creating a new stack
***************************************************/
subQList::subQList(size_t oldDaggerLevel)
{
	QNode *headNode = new QNode();
	headNode->gateSpecifier = START;
	headNode->next = NULL;
	head = headNode;
	cursor = head;
	daggerLevel = oldDaggerLevel + 1;
}

/*************************************************
* class     subQList
* clear all contents in linkedlist
***************************************************/
void subQList::subListClear()
{
	QNode *thisNode = this->head;
	QNode *nextNode = NULL;
	while (NULL != thisNode)
	{
		nextNode = thisNode->next;
		delete (thisNode);
		thisNode = nextNode;
	}
}

/*************************************************
* class     subQList
* name      Reverse
* visible   yes
* arg       n/a
* return    n/a
* note      Rerverse the linked list
***************************************************/
void subQList::Reverse()
{
	this->head->next = ReverseNode(this->head->next);
}

/*************************************************
* class     subQList
* name      Reverse
* visible   no
* arg       QNode* (first node after head)
* return    QNode* (first node of new list)
***************************************************/
QNode *subQList::ReverseNode(QNode *firstNode)
{
	QNode *newh = NULL;
	for (QNode *p = firstNode; p;)
	{
		QNode *tmp = p->next;
		p->next = newh;
		newh = p;
		p = tmp;
	}
	return newh;
}

/*************************************************
* class     subQList
* name      Merge
* visible   yes
* arg       subQList* (another subQList)
* return    n/a
* note      Merge with another subQList
***************************************************/
void subQList::Merge(subQList *origin)
{
	cursor->next = origin->head->next;

	while (cursor->next != NULL)
	{
		cursor = cursor->next;
	}
}

/*************************************************
* class     subQList
* name      getSize
* visible   yes
* arg       n/a
* return    element number of this list
* note      Only for test
***************************************************/
int subQList::getSize()
{
	QNode *temp = head->next;
	int i = 0;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return i;
}

subQList::subQList(const subQList &b)
{
	if (nullptr == b.head->next)
	{
		throw exception();
	}
	GateType_t *gateType = GateType_t::GetInstance();
	auto gate_type = gateType->getGateType();
	QNode *ptNode = b.head->next;
	auto node = new QNode;
	node->next = nullptr;
	head = node;
	cursor = node;
	// if (iter == gate_type.end())
	// {
	// 	cout << "not support this gate type" << endl;
	// 	return;
	// }
	while (nullptr != ptNode)
	{
		auto iter = gate_type.find(ptNode->gateSpecifier);
		switch (iter->second)
		{
		case 1:
		{
			auto node = new SingleGateNode;
			auto single_node = (SingleGateNode *)ptNode;
			node->opQubit = single_node->opQubit;
			node->isDagger = single_node->isDagger;
			node->gateSpecifier = single_node->gateSpecifier;

			for (auto aiter : single_node->controlList)
			{
				node->controlList.push_back(aiter);
			}
			node->next = nullptr;
			cursor->next = node;
			cursor = node;
		}
		break;
		case 2:
		{
			auto node = new DoubleGateNode;
			auto double_node = (DoubleGateNode *)ptNode;
			node->opQubit1 = double_node->opQubit1;
			node->opQubit2 = double_node->opQubit2;
			node->isDagger = double_node->isDagger;
			node->gateSpecifier = double_node->gateSpecifier;

			for (auto aiter : double_node->controlList)
			{
				node->controlList.push_back(aiter);
			}
			node->next = nullptr;
			cursor->next = node;
			cursor = node;
		}
		break;
		case 3:
		{
			auto node = new TripleGateNode;
			auto triple_node = (TripleGateNode *)ptNode;
			node->opQubit1 = triple_node->opQubit1;
			node->opQubit2 = triple_node->opQubit2;
			node->opQubit3 = triple_node->opQubit3;
			node->isDagger = triple_node->isDagger;
			node->gateSpecifier = triple_node->gateSpecifier;

			for (auto aiter : triple_node->controlList)
			{
				node->controlList.push_back(aiter);
			}
			node->next = nullptr;
			cursor->next = node;
			cursor = node;
		}
		break;
		case 4:
		{
			auto node = new SingleAngleGateNode;
			auto singleAngle_node = (SingleAngleGateNode *)ptNode;
			node->opQubit = singleAngle_node->opQubit;
			node->isDagger = singleAngle_node->isDagger;
			node->gateSpecifier = singleAngle_node->gateSpecifier;
			node->angle = singleAngle_node->angle;

			for (auto aiter : singleAngle_node->controlList)
			{
				node->controlList.push_back(aiter);
			}
			node->next = nullptr;
			cursor->next = node;
			cursor = node;
		}
		break;
		case 5:
		{
			auto node = new DoubleAngleGateNode;
			auto doubleAngle_node = (DoubleAngleGateNode *)ptNode;
			node->opQubit1 = doubleAngle_node->opQubit1;
			node->opQubit2 = doubleAngle_node->opQubit2;
			node->isDagger = doubleAngle_node->isDagger;
			node->gateSpecifier = doubleAngle_node->gateSpecifier;
			node->angle = doubleAngle_node->angle;

			for (auto aiter : doubleAngle_node->controlList)
			{
				node->controlList.push_back(aiter);
			}
			node->next = nullptr;
			cursor->next = node;
			cursor = node;
		}
		break;

		default:
			break;
		}

		ptNode = ptNode->next;
	}
}

subQList &subQList::operator=(const subQList &b)
{
	if (nullptr == b.head->next)
	{
		return *this;
	}
	GateType_t *gateType = GateType_t::GetInstance();
	auto gate_type = gateType->getGateType();
	QNode *ptNode = b.head->next;
	auto node = new QNode;
	node->next = nullptr;
	node->prev = nullptr;
	head = node;
	cursor = node;
	// if (iter == gate_type.end())
	// {
	// 	cout << "not support this gate type" << endl;
	// 	return;
	// }
	while (nullptr != ptNode)
	{
		auto iter = gate_type.find(ptNode->gateSpecifier);
		switch (iter->second)
		{
		case 1:
		{
			auto node = new SingleGateNode;
			auto single_node = (SingleGateNode *)ptNode;
			node->opQubit = single_node->opQubit;
			node->isDagger = single_node->isDagger;
			node->gateSpecifier = single_node->gateSpecifier;

			for (auto aiter : single_node->controlList)
			{
				node->controlList.push_back(aiter);
			}
			node->next = nullptr;
			node->prev = cursor;
			cursor->next = node;
			cursor = node;
		}
		break;
		case 2:
		{
			auto node = new DoubleGateNode;
			auto double_node = (DoubleGateNode *)ptNode;
			node->opQubit1 = double_node->opQubit1;
			node->opQubit2 = double_node->opQubit2;
			node->isDagger = double_node->isDagger;
			node->gateSpecifier = double_node->gateSpecifier;

			for (auto aiter : double_node->controlList)
			{
				node->controlList.push_back(aiter);
			}
			node->next = nullptr;
			node->prev = cursor;
			cursor->next = node;
			cursor = node;
		}
		break;
		case 3:
		{
			auto node = new TripleGateNode;
			auto triple_node = (TripleGateNode *)ptNode;
			node->opQubit1 = triple_node->opQubit1;
			node->opQubit2 = triple_node->opQubit2;
			node->opQubit3 = triple_node->opQubit3;
			node->isDagger = triple_node->isDagger;
			node->gateSpecifier = triple_node->gateSpecifier;

			for (auto aiter : triple_node->controlList)
			{
				node->controlList.push_back(aiter);
			}
			node->next = nullptr;
			node->prev = cursor;
			cursor->next = node;
			cursor = node;
		}
		break;
		case 4:
		{
			auto node = new SingleAngleGateNode;
			auto singleAngle_node = (SingleAngleGateNode *)ptNode;
			node->opQubit = singleAngle_node->opQubit;
			node->isDagger = singleAngle_node->isDagger;
			node->gateSpecifier = singleAngle_node->gateSpecifier;
			node->angle = singleAngle_node->angle;

			for (auto aiter : singleAngle_node->controlList)
			{
				node->controlList.push_back(aiter);
			}
			node->next = nullptr;
			cursor->next = node;
			cursor = node;
		}
		break;
		case 5:
		{
			auto node = new DoubleAngleGateNode;
			auto doubleAngle_node = (DoubleAngleGateNode *)ptNode;
			node->opQubit1 = doubleAngle_node->opQubit1;
			node->opQubit2 = doubleAngle_node->opQubit2;
			node->isDagger = doubleAngle_node->isDagger;
			node->gateSpecifier = doubleAngle_node->gateSpecifier;
			node->angle = doubleAngle_node->angle;

			for (auto aiter : doubleAngle_node->controlList)
			{
				node->controlList.push_back(aiter);
			}
			node->next = nullptr;
			node->prev = cursor;
			cursor->next = node;
			cursor = node;
		}
		break;

		default:
			break;
		}

		ptNode = ptNode->next;
	}
	return *this;
}

void QList::TraverseAll_T(GateType_t *gateType, subQList *sub, int iRank)
{
	cout << "rank: " + to_string(iRank) + "\n";
	QNode *ptQNode = sub->head->next;
	map<int, int> gate_type = gateType->getGateType();

	while (ptQNode != NULL)
	{

		auto iter = gate_type.find(ptQNode->gateSpecifier);
		if (gate_type.end() == iter)
		{
			cout << "not support this gate type" << endl;
			return;
		}

		switch (iter->second)
		{
		case 1:
		{
			SingleGateNode *sptQNode = (SingleGateNode *)ptQNode;
			std::cout << "GATE rank: " + to_string(iRank) + " " + to_string(sptQNode->opQubit) + " " + to_string(iter->first) + "\n";
			for (int i = 0; i < sptQNode->controlList.size(); i++)
			{
				cout << sptQNode->controlList[i] << endl;
			}
		}
		break;
		case 2:
		{
			DoubleGateNode *sptQNode = (DoubleGateNode *)ptQNode;
			std::cout << "GATE rank: " + to_string(iRank) + " " + to_string(sptQNode->opQubit1) + " " + to_string(sptQNode->opQubit2) + " " + to_string(iter->first) + "\n";
		}
		break;
		case 3:
		{
			TripleGateNode *sptQNode = (TripleGateNode *)ptQNode;
			std::cout << sptQNode->opQubit1 << " " << sptQNode->opQubit2 << sptQNode->opQubit3
					  << (sptQNode->isDagger == true ? 1 : -1) << " " << std::endl;
		}
		break;
		case 4:
		{
			SingleAngleGateNode *sptQNode = (SingleAngleGateNode *)ptQNode;
			std::cout << "GATE rank: " + to_string(iRank) + " " + to_string(sptQNode->opQubit) + " " + to_string(sptQNode->angle) + "\n";
		}
		break;
		case 5:
		{
			DoubleAngleGateNode *sptQNode = (DoubleAngleGateNode *)ptQNode;
			std::cout << sptQNode->opQubit1 << " " << sptQNode->opQubit2 << sptQNode->angle
					  << (sptQNode->isDagger == true ? 1 : -1) << " " << std::endl;
		}
		break;
		case 6:
		{
			pMeasureNode *sptQNode = (pMeasureNode *)ptQNode;
			for (int i = 0; i < sptQNode->vecint_pmeasure_list.size(); i++)
			{
				cout << sptQNode->vecint_pmeasure_list[i] << endl;
			}
		}
		break;
		case 7:
		{
			MeasureNode *sptQNode = (MeasureNode *)ptQNode;
			std::cout << sptQNode->opQubit << " " << sptQNode->creg << std::endl;
		}
		break;
		default:
			break;
		}

		ptQNode = ptQNode->next;
	}
}
