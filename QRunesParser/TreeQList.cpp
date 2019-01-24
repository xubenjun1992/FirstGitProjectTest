#include "TreeQList.h"

extern int halfNum;

TreeQList::TreeQList()
{
}

bool TreeQList::judgeLinkListHaveKey(QList *qList)
{
	bool containCZ = false;
	QNode *node = qList->qList.head->next;
	while (node != NULL)
	{
		auto keyCodeMap = keyCode.find(node->gateSpecifier);
		if (keyCodeMap != keyCode.end())
		{
			DoubleGateNode *pDouble = (DoubleGateNode *)node;
			if ((pDouble->opQubit1 < halfNum && pDouble->opQubit2 >= halfNum) || (pDouble->opQubit1 >= halfNum && pDouble->opQubit2 < halfNum))
			{
				containCZ = true;
				break;
			}
			else
			{
				containCZ = false;
			}
		}

		node = node->next;
	}
	return containCZ;
}

void TreeQList::splitQlist(QList *qlist)
{
	QNode *qNode = qlist->qList.head->next;
	GateType_t *gateType = GateType_t::GetInstance();
	auto gate_type = gateType->getGateType();
	auto subQlist1 = new subQList;
	auto node1 = new QNode();
	node1->next = nullptr;
	node1->prev = nullptr;
	auto node2 = new QNode();
	node2->next = nullptr;
	node2->prev = nullptr;
	auto subQlist2 = new subQList;
	subQlist1->head = node1;
	subQlist1->cursor = node1;
	subQlist2->head = node2;
	subQlist2->cursor = node2;
	while (qNode != NULL)
	{
		auto iter = gate_type.find(qNode->gateSpecifier);
		switch (iter->second)
		{
		case 1:
		{
			auto node = new SingleGateNode;
			auto single_node = (SingleGateNode *)qNode;
			node->opQubit = single_node->opQubit;
			node->isDagger = single_node->isDagger;
			node->gateSpecifier = single_node->gateSpecifier;

			for (auto aiter : single_node->controlList)
			{
				node->controlList.push_back(aiter);
			}
			node->next = nullptr;
			if (single_node->opQubit < halfNum)
			{
				node->prev = subQlist1->cursor;
				subQlist1->cursor->next = node;
				subQlist1->cursor = node;
			}
			else
			{
				node->prev = subQlist2->cursor;
				subQlist2->cursor->next = node;
				subQlist2->cursor = node;
				node->opQubit = node->opQubit - halfNum;
			}
		}
		break;
		case 2:
		{
			auto node = new DoubleGateNode;
			auto double_node = (DoubleGateNode *)qNode;
			node->opQubit1 = double_node->opQubit1;
			node->opQubit2 = double_node->opQubit2;
			node->isDagger = double_node->isDagger;
			node->gateSpecifier = double_node->gateSpecifier;

			for (auto aiter : double_node->controlList)
			{
				node->controlList.push_back(aiter);
			}

			node->next = nullptr;
			if (double_node->opQubit2 <= halfNum - 1)
			{
				node->prev = subQlist1->cursor;
				subQlist1->cursor->next = node;
				subQlist1->cursor = node;
			}
			else if (double_node->opQubit2 > halfNum - 1 && double_node->opQubit1 > halfNum - 1)
			{
				node->prev = subQlist2->cursor;
				subQlist2->cursor->next = node;
				subQlist2->cursor = node;
				node->opQubit1 = node->opQubit1 - halfNum;
				node->opQubit2 = node->opQubit2 - halfNum;
			}
			else if (double_node->opQubit2 >= halfNum && double_node->opQubit1 < halfNum && double_node->gateSpecifier != 19)
			{
				throw exception();
			}
		}
		break;
		case 3:
		{
			auto node = new TripleGateNode;
			auto triple_node = (TripleGateNode *)qNode;
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
			if (triple_node->opQubit3 <= halfNum - 1)
			{
				subQlist1->cursor->next = node;
				subQlist1->cursor = node;
			}
			else if (triple_node->opQubit1 > halfNum - 1 && triple_node->opQubit2 > halfNum - 1 && triple_node->opQubit3 > halfNum - 1)
			{
				subQlist2->cursor->next = node;
				subQlist2->cursor = node;
			}
		}
		break;
		case 4:
		{
			auto node = new SingleAngleGateNode;
			auto singleAngle_node = (SingleAngleGateNode *)qNode;
			node->opQubit = singleAngle_node->opQubit;
			node->isDagger = singleAngle_node->isDagger;
			node->gateSpecifier = singleAngle_node->gateSpecifier;
			node->angle = singleAngle_node->angle;

			for (auto aiter : singleAngle_node->controlList)
			{
				node->controlList.push_back(aiter);
			}
			node->next = nullptr;
			if (singleAngle_node->opQubit <= halfNum - 1)
			{
				node->prev = subQlist1->cursor;
				subQlist1->cursor->next = node;
				subQlist1->cursor = node;
			}
			else
			{
				node->prev = subQlist2->cursor;
				subQlist2->cursor->next = node;
				subQlist2->cursor = node;
				node->opQubit = node->opQubit - halfNum;
			}
		}
		break;
		case 5:
		{
			auto node = new DoubleAngleGateNode;
			auto doubleAngle_node = (DoubleAngleGateNode *)qNode;
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
			if (doubleAngle_node->opQubit2 <= halfNum - 1)
			{
				node->prev = subQlist1->cursor;
				subQlist1->cursor->next = node;
				subQlist1->cursor = node;
			}
			else if (doubleAngle_node->opQubit2 > halfNum - 1 && doubleAngle_node->opQubit1 > halfNum - 1)
			{
				node->prev = subQlist2->cursor;
				subQlist2->cursor->next = node;
				subQlist2->cursor = node;
				node->opQubit1 = node->opQubit1 - halfNum;
				node->opQubit2 = node->opQubit2 - halfNum;
			}
		}
		break;

		default:
			break;
		}

		qNode = qNode->next;
	}
	map<int, QNode *> subQListMap;
	if (subQlist1->head->next != NULL)
	{
		subQListMap.insert({0, subQlist1->head->next});
	}

	if (subQlist2->head->next != NULL)
	{
		subQListMap.insert({1, subQlist2->head->next});
	}
	splitQlistVector.push_back(subQListMap);
}

void TreeQList::createQList(QList *qList)
{
	QList *leftQList = new QList(*qList);
	QList *rightQList = new QList(*qList);
	auto ptQNode = qList->qList.head->next;
	auto ptQNodeLeft = leftQList->qList.head->next;
	auto ptQNodeRight = rightQList->qList.head->next;
	while (ptQNode != NULL)
	{
		auto keyCodeMap = keyCode.find(ptQNode->gateSpecifier);
		if (keyCodeMap != keyCode.end())
		{
			DoubleGateNode *pDouble = (DoubleGateNode *)ptQNode;

			if ((pDouble->opQubit1 < halfNum && pDouble->opQubit2 >= halfNum) || (pDouble->opQubit1 >= halfNum && pDouble->opQubit2 < halfNum))
			{
				SingleGateNode *newGateNodeLeft = new SingleGateNode();

				//first
				newGateNodeLeft->gateSpecifier = P0_GATE;
				newGateNodeLeft->opQubit = pDouble->opQubit1;
				newGateNodeLeft->prev = ptQNodeLeft->prev;
				ptQNodeLeft->prev->next = newGateNodeLeft;
				newGateNodeLeft->next = ptQNodeLeft->next;
				if (nullptr == ptQNodeLeft->next)
				{
					ptQNodeLeft->prev = newGateNodeLeft;
				}
				else
				{
					ptQNodeLeft->next->prev = newGateNodeLeft;
				}

				SingleGateNode *newGateNodeRight = new SingleGateNode();
				SingleGateNode *newGateNodeZ = new SingleGateNode();
				newGateNodeRight->gateSpecifier = P1_GATE;
				newGateNodeRight->opQubit = pDouble->opQubit1;
				newGateNodeRight->prev = ptQNodeRight->prev;
				ptQNodeRight->prev->next = newGateNodeRight;
				newGateNodeRight->next = newGateNodeZ;

				for (auto iter = keyCode.begin(); iter != keyCode.end(); iter++)
				{
					if (ptQNode->gateSpecifier == iter->first)
					{
						newGateNodeZ->gateSpecifier = iter->second;
						break;
					}
				}

				newGateNodeZ->opQubit = pDouble->opQubit2;
				newGateNodeZ->prev = newGateNodeRight;
				newGateNodeZ->next = ptQNodeRight->next;
				if (ptQNodeRight->next == NULL)
				{
					ptQNodeRight->prev = newGateNodeZ;
				}
				else
				{
					ptQNodeRight->next->prev = newGateNodeZ;
				}

				createQList(leftQList);
				createQList(rightQList);
				if (!judgeLinkListHaveKey(leftQList))
				{
					splitQlist(leftQList);
				}

				if (!judgeLinkListHaveKey(rightQList))
				{
					splitQlist(rightQList);
				}

				delete (leftQList);
				delete (rightQList);
				break;
			}
		}
		ptQNode = ptQNode->next;
		ptQNodeLeft = ptQNodeLeft->next;
		ptQNodeRight = ptQNodeRight->next;
	}
}

vector<map<int, QNode *>> TreeQList::getSplitQlistVector()
{
	return splitQlistVector;
}

map<int, int> TreeQList::getKeyCode()
{
	return keyCode;
}

void TreeQList::setKeyCode(map<int, int> keyCodeMap)
{
	for (auto keyMap = keyCodeMap.begin(); keyMap != keyCodeMap.end(); keyMap++)
	{
		this->keyCode.insert({keyMap->first, keyMap->second});
	}
}