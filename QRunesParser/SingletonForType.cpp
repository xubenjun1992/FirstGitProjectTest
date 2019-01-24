#include "SingletonForType.h"
#include <map>
using namespace std;

GateType_t* GateType_t::m_pInstance = NULL;
GateType_t::CGarbo GateType_t::ms_Garbo;
GateType_t::GateType_t()
{
	//1�����ţ�2��˫�ţ�3�����ţ�4���Ƕȵ��ţ�5���Ƕ�˫��
	gateType.insert({ HADAMARD_GATE, 1 });
	gateType.insert(make_pair(RX_GATE, 4));
	gateType.insert(make_pair(RY_GATE, 4));
	gateType.insert(make_pair(RZ_GATE, 4));
	gateType.insert(make_pair(NOT_GATE, 2));
	gateType.insert(make_pair(TOFFOLI_GATE, 3));
	gateType.insert(make_pair(CR_GATE, 2));
	gateType.insert(make_pair(ISWAP_GATE, 2));
	gateType.insert(make_pair(SQISWAP_GATE, 2));
	gateType.insert(make_pair(CNOT_GATE, 2));
	gateType.insert(make_pair(CZ_GATE, 2));
	gateType.insert(make_pair(Y_GATE, 1));
	gateType.insert(make_pair(Z_GATE, 1));
	gateType.insert(make_pair(T_GATE, 1));
	gateType.insert(make_pair(X1_GATE, 1));
	gateType.insert(make_pair(Y1_GATE, 1));
	gateType.insert(make_pair(Z1_GATE, 1));
	gateType.insert(make_pair(S_GATE, 1));
	gateType.insert(make_pair(CU_GATE, 2));
	gateType.insert(make_pair(CPHASE_GATE, 2));
	gateType.insert(make_pair(PMEASURE_GATE, 6));
	gateType.insert(make_pair(P0_GATE, 1));
	gateType.insert(make_pair(P1_GATE, 1));
	//		gateType.insert(make_pair("MEASURE_GATE", 1));
	//		gateType.insert(make_pair("MEASURE_GATE", 1));
}

GateType_t * GateType_t::GetInstance()
{
	if (nullptr == m_pInstance)
	{
		m_pInstance = new GateType_t();
	}

	return m_pInstance;
}

map<int, int> GateType_t::getGateType()
{
	return gateType;
}


