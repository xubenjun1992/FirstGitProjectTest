#include "LinkedListController.h"
#include "QuantumGates.h"
#include "SingletonForType.h"
#include <math.h>
#include <numeric>
#include <algorithm>

class TreeQList
{
  public:
    TreeQList();

    /*************************************************************************************************************
    Name:        createQList
    Description: get the partition line of the line
    Argin:       qList
    Argout:      splitQlistVector
    return:      void
    *************************************************************************************************************/
    void createQList(QList *qList);

    /*************************************************************************************************************
    Name:        judgeLinkListHaveKey
    Description: Determine whether there are keywords in the line
    Argin:       qList
    Argout:      splitQlistVector
    return:      bool
    *************************************************************************************************************/
    bool judgeLinkListHaveKey(QList *qList);

    /*************************************************************************************************************
    Name:        splitQlist
    Description: Re-dividing the generated lines
    Argin:       qList
    Argout:      splitQlistVector
    return:      void
    *************************************************************************************************************/
    void splitQlist(QList *qList);

    vector<map<int, QNode *>> getSplitQlistVector();

    map<int, int> getKeyCode();

    void setKeyCode(map<int, int> keyCodeMap);

  private:
    map<int, int> keyCode;
    vector<map<int, QNode *>> splitQlistVector;
};