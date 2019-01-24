#ifndef _SINGLETON_FOR_TYPE_H
#define _SINGLETON_FOR_TYPE_H
#include "QParamStruct.h"
#include <map>
using namespace std;


class GateType_t
{
public:
	static GateType_t * GetInstance();
	map<int, int> getGateType();
private:
	GateType_t();
	static GateType_t* m_pInstance;
	map<int, int> gateType;

	class CGarbo  
	{
	public:
		~CGarbo()
		{
			if (GateType_t::m_pInstance)
				delete GateType_t::m_pInstance;
		}
	};
	static CGarbo ms_Garbo;
};

#endif
