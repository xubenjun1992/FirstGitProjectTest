/*****************************************************************************************************************
Copyright:
Author:Dou Menghan
Date:2017-11-23
Description:instruction class
*****************************************************************************************************************/
#ifndef _INSTRUCTION_H
#define _INSTRUCTION_H
#include "../QRunesParser/QParamStruct.h"
#include "../QRunesParser/LinkedListController.h"
#include "QuantumGateParameter.h"
#include "QuantumGates.h"
#include <sstream>


/*****************************************************************************************************************
Instruction:the parent of instruction class
*****************************************************************************************************************/
class Instruction
{
public:
    Instruction() {};
    ~Instruction() {};

    /*************************************************************************************************************
    Name:        getInstruction
    Description: add instruction to Ring Memory
    Argin:       pQInstructionNode  quantum Instruction node
    pQuantumProParam   quantum program param
    pQGate             quantum gate pointer
    Argout:      pQuantumProParam   quantum program param
    return:      true or false
    *************************************************************************************************************/
    virtual bool getInstruction(QNode * pQInstructionNode, QuantumGateParam *pQuantumProParam, QuantumGates * pQGate) = 0;

public:
    int mType;                                                          /* instruction type                     */
};

/*****************************************************************************************************************
Hadamard:Hadamard instruction
*****************************************************************************************************************/
class Hadamard :public Instruction
{
public:
    inline Hadamard()
    {
        mType = HADAMARD_GATE;                                          /* set instruction type                 */
    }
    ~Hadamard();

    /*************************************************************************************************************
    Name:        getInstruction
    Description: add instruction to Ring Memory
    Argin:       pQInstructionNode  quantum Instruction node
    pQuantumProParam   quantum program param
    pQGate             quantum gate pointer
    Argout:      pQuantumProParam   quantum program param
    return:      true or false
    *************************************************************************************************************/
    bool getInstruction(QNode * pQInstructionNode, QuantumGateParam *pQuantumProParam, QuantumGates * pQGate);

};

/*****************************************************************************************************************
RX:RX instruction
*****************************************************************************************************************/
class RX : public Instruction
{
public:
    inline RX()
    {
        mType = RX_GATE;                                                /* set instruction type                 */
    }
    ~RX();

    /*************************************************************************************************************
    Name:        getInstruction
    Description: add instruction to Ring Memory
    Argin:       pQInstructionNode  quantum Instruction node
    pQuantumProParam   quantum program param
    pQGate             quantum gate pointer
    Argout:      pQuantumProParam   quantum program param
    return:      true or false
    *************************************************************************************************************/
    bool getInstruction(QNode * pQInstructionNode, QuantumGateParam *pQuantumProParam, QuantumGates * pQGate);
};

/*****************************************************************************************************************
RY:RY instruction
*****************************************************************************************************************/
class RY : public Instruction
{
public:
    inline RY()
    {
        mType = RY_GATE;                                                /* set instruction type                 */
    }
    ~RY();

    /*************************************************************************************************************
    Name:        getInstruction
    Description: add instruction to Ring Memory
    Argin:       pQInstructionNode  quantum Instruction node
    pQuantumProParam   quantum program param
    pQGate             quantum gate pointer
    Argout:      pQuantumProParam   quantum program param
    return:      true or false
    *************************************************************************************************************/
    bool getInstruction(QNode * pQInstructionNode, QuantumGateParam *pQuantumProParam, QuantumGates * pQGate);
};

/*****************************************************************************************************************
RZ:RZ instruction
*****************************************************************************************************************/
class RZ : public Instruction
{
public:
    inline RZ()
    {
        mType = RZ_GATE;                                                /* set instruction type                 */
    }
    ~RZ() {};

    /*************************************************************************************************************
    Name:        getInstruction
    Description: add instruction to Ring Memory
    Argin:       pQInstructionNode  quantum Instruction node
    pQuantumProParam   quantum program param
    pQGate             quantum gate pointer
    Argout:      pQuantumProParam   quantum program param
    return:      true or false
    *************************************************************************************************************/
    bool getInstruction(QNode * pQInstructionNode, QuantumGateParam *pQuantumProParam, QuantumGates * pQGate);
};

/*****************************************************************************************************************
CNOT:CNOT instruction
*****************************************************************************************************************/
class CNOT : public Instruction
{
public:
    inline CNOT()
    {
        mType = CNOT_GATE;                                              /* set instruction type                 */
    }
    ~CNOT() {};

    /*************************************************************************************************************
    Name:        getInstruction
    Description: add instruction to Ring Memory
    Argin:       pQInstructionNode  quantum Instruction node
    pQuantumProParam   quantum program param
    pQGate             quantum gate pointer
    Argout:      pQuantumProParam   quantum program param
    return:      true or false
    *************************************************************************************************************/
    bool getInstruction(QNode * pQInstructionNode, QuantumGateParam *pQuantumProParam, QuantumGates * pQGate);
};

/*****************************************************************************************************************
NOT:NOT instruction
*****************************************************************************************************************/
class NOT : public Instruction
{
public:
    inline NOT()
    {
        mType = NOT_GATE;                                               /* set instruction type                 */
    }
    ~NOT() {};

    /*************************************************************************************************************
    Name:        getInstruction
    Description: add instruction to Ring Memory
    Argin:       pQInstructionNode  quantum Instruction node
    pQuantumProParam   quantum program param
    pQGate             quantum gate pointer
    Argout:      pQuantumProParam   quantum program param
    return:      true or false
    *************************************************************************************************************/
    bool getInstruction(QNode * pQInstructionNode, QuantumGateParam *pQuantumProParam, QuantumGates * pQGate);
};

/*****************************************************************************************************************
TOFFOLI:TOFFOLI instruction
*****************************************************************************************************************/
class TOFFOLI : public Instruction
{
public:
    inline TOFFOLI()
    {
        mType = TOFFOLI_GATE;                                           /* set instruction type                 */
    }
    ~TOFFOLI() {};

    /*************************************************************************************************************
    Name:        getInstruction
    Description: add instruction to Ring Memory
    Argin:       pQInstructionNode  quantum Instruction node
    pQuantumProParam   quantum program param
    pQGate             quantum gate pointer
    Argout:      pQuantumProParam   quantum program param
    return:      true or false
    *************************************************************************************************************/
    bool getInstruction(QNode * pQInstructionNode, QuantumGateParam *pQuantumProParam, QuantumGates * pQGate);
};

/*****************************************************************************************************************
CR:CR instruction
*****************************************************************************************************************/
class CR : public Instruction
{
public:
    inline CR()
    {
        mType = CR_GATE;                                                /* set instruction type                 */
    }
    ~CR() {};

    /*************************************************************************************************************
    Name:        getInstruction
    Description: add instruction to Ring Memory
    Argin:       pQInstructionNode  quantum Instruction node
    pQuantumProParam   quantum program param
    pQGate             quantum gate pointer
    Argout:      pQuantumProParam   quantum program param
    return:      true or false
    *************************************************************************************************************/
    bool getInstruction(QNode * pQInstructionNode, QuantumGateParam *pQuantumProParam, QuantumGates * pQGate);
};

/*****************************************************************************************************************
iSWAP:iSWAP instruction
*****************************************************************************************************************/
class iSWAP : public Instruction
{
public:
    inline iSWAP()
    {
        mType = ISWAP_GATE;                                             /* set instruction type                 */
    }
    ~iSWAP() {};

    /*************************************************************************************************************
    Name:        getInstruction
    Description: add instruction to Ring Memory
    Argin:       pQInstructionNode  quantum Instruction node
    pQuantumProParam   quantum program param
    pQGate             quantum gate pointer
    Argout:      pQuantumProParam   quantum program param
    return:      true or false
    *************************************************************************************************************/
    bool getInstruction(QNode * pQInstructionNode, QuantumGateParam *pQuantumProParam, QuantumGates * pQGate);
};

/*****************************************************************************************************************
iSWAP:iSWAP instruction
*****************************************************************************************************************/
class sqiSWAP : public Instruction
{
public:
    inline sqiSWAP()
    {
        mType = SQISWAP_GATE;                                           /* set instruction type                 */
    }
    ~sqiSWAP() {};

    /*************************************************************************************************************
    Name:        getInstruction
    Description: add instruction to Ring Memory
    Argin:       pQInstructionNode  quantum Instruction node
    pQuantumProParam   quantum program param
    pQGate             quantum gate pointer
    Argout:      pQuantumProParam   quantum program param
    return:      true or false
    *************************************************************************************************************/
    bool getInstruction(QNode * pQInstructionNode, QuantumGateParam *pQuantumProParam, QuantumGates * pQGate);
};

/*****************************************************************************************************************
controlSwap:controlSwap instruction
*****************************************************************************************************************/
class controlSwap : public Instruction
{
public:
    inline controlSwap()
    {
        mType = -1;
    }
    ~controlSwap() {};

    /*************************************************************************************************************
    Name:        getInstruction
    Description: add instruction to Ring Memory
    Argin:       pQInstructionNode  quantum Instruction node
    pQuantumProParam   quantum program param
    pQGate             quantum gate pointer
    Argout:      pQuantumProParam   quantum program param
    return:      true or false
    *************************************************************************************************************/
    bool getInstruction(QNode * pQInstructionNode, QuantumGateParam *pQuantumProParam, QuantumGates * pQGate);
};

/*****************************************************************************************************************
qubitMeasure:qubitMeasure instruction
*****************************************************************************************************************/
class qubitMeasure : public Instruction
{
public:
    qubitMeasure()
    {
        mType = MEASURE_GATE;                                           /* set instruction type                 */
    };
    ~qubitMeasure() {};

    /*************************************************************************************************************
    Name:        getInstruction
    Description: add instruction to Ring Memory
    Argin:       pQInstructionNode  quantum Instruction node
    pQuantumProParam   quantum program param
    pQGate             quantum gate pointer
    Argout:      pQuantumProParam   quantum program param
    return:      true or false
    *************************************************************************************************************/
    bool getInstruction(QNode * pQInstructionNode, QuantumGateParam *pQuantumProParam, QuantumGates * pQGate);
};

/*****************************************************************************************************************
unitarySingleQubit:unitarySingleQubit instruction
*****************************************************************************************************************/
class unitarySingleQubit : public Instruction
{
public:
    unitarySingleQubit() {};
    ~unitarySingleQubit() {};

    /*************************************************************************************************************
    Name:        getInstruction
    Description: add instruction to Ring Memory
    Argin:       pQInstructionNode  quantum Instruction node
    pQuantumProParam   quantum program param
    pQGate             quantum gate pointer
    Argout:      pQuantumProParam   quantum program param
    return:      true or false
    *************************************************************************************************************/
    bool getInstruction(QNode * pQInstructionNode, QuantumGateParam *pQuantumProParam, QuantumGates * pQGate);
};

/*****************************************************************************************************************
endProgram:endProgram instruction
*****************************************************************************************************************/
class endProgram : public Instruction
{
public:

    endProgram()
    {
        mType = END;                                                    /* set instruction type                 */
    }
    ~endProgram() {};

    /*************************************************************************************************************
    Name:        getInstruction
    Description: add instruction to Ring Memory
    Argin:       pQInstructionNode  quantum Instruction node
    pQuantumProParam   quantum program param
    pQGate             quantum gate pointer
    Argout:      pQuantumProParam   quantum program param
    return:      true or false
    *************************************************************************************************************/
    bool getInstruction(QNode * pQInstructionNode, QuantumGateParam *pQuantumProParam, QuantumGates * pQGate);
};

/*****************************************************************************************************************
pMeasure:pMeasure instruction
*****************************************************************************************************************/
class pMeasure : public Instruction
{
public:

    pMeasure()
    {
        mType = PMEASURE_GATE;                                          /* set instruction type                 */
    }
    ~pMeasure() {};

    /*************************************************************************************************************
    Name:        getInstruction
    Description: add instruction to Ring Memory
    Argin:       pQInstructionNode  quantum Instruction node
    pQuantumProParam   quantum program param
    pQGate             quantum gate pointer
    Argout:      pQuantumProParam   quantum program param
    return:      true or false
    *************************************************************************************************************/
    bool getInstruction(QNode * pQInstructionNode, QuantumGateParam *pQuantumProParam, QuantumGates * pQGate);
};

/*****************************************************************************************************************
reset:reset instruction
*****************************************************************************************************************/
class reset : public Instruction
{
public:

    reset()
    {
        mType = RESET_GATE;                                             /* set instruction type                 */
    }
    ~reset() {};

    /*************************************************************************************************************
    Name:        getInstruction
    Description: add instruction to Ring Memory
    Argin:       pQInstructionNode  quantum Instruction node
    pQuantumProParam   quantum program param
    pQGate             quantum gate pointer
    Argout:      pQuantumProParam   quantum program param
    return:      true or false
    *************************************************************************************************************/
    bool getInstruction(QNode * pQInstructionNode, QuantumGateParam *pQuantumProParam, QuantumGates * pQGate);
};


class Z : public Instruction
{
public:

    Z()
    {
        mType = Z_GATE;                                             /* set instruction type                 */
    }
    ~Z() {};

    /*************************************************************************************************************
    Name:        getInstruction
    Description: add instruction to Ring Memory
    Argin:       pQInstructionNode  quantum Instruction node
    pQuantumProParam   quantum program param
    pQGate             quantum gate pointer
    Argout:      pQuantumProParam   quantum program param
    return:      true or false
    *************************************************************************************************************/
    bool getInstruction(QNode * pQInstructionNode, QuantumGateParam *pQuantumProParam, QuantumGates * pQGate);
};


class P0 : public Instruction
{
public:

    P0()
    {
        mType = P0_GATE;                                             /* set instruction type                 */
    }
    ~P0() {};

    /*************************************************************************************************************
    Name:        getInstruction
    Description: add instruction to Ring Memory
    Argin:       pQInstructionNode  quantum Instruction node
    pQuantumProParam   quantum program param
    pQGate             quantum gate pointer
    Argout:      pQuantumProParam   quantum program param
    return:      true or false
    *************************************************************************************************************/
    bool getInstruction(QNode * pQInstructionNode, QuantumGateParam *pQuantumProParam, QuantumGates * pQGate);
};



class P1 : public Instruction
{
public:

    P1()
    {
        mType = P1_GATE;                                             /* set instruction type                 */
    }
    ~P1() {};

    /*************************************************************************************************************
    Name:        getInstruction
    Description: add instruction to Ring Memory
    Argin:       pQInstructionNode  quantum Instruction node
    pQuantumProParam   quantum program param
    pQGate             quantum gate pointer
    Argout:      pQuantumProParam   quantum program param
    return:      true or false
    *************************************************************************************************************/
    bool getInstruction(QNode * pQInstructionNode, QuantumGateParam *pQuantumProParam, QuantumGates * pQGate);
};


class X1 : public Instruction
{
public:
    inline X1()
    {
        mType = X1_GATE;                                                /* set instruction type                 */
    }
    ~X1(){};

    /*************************************************************************************************************
    Name:        getInstruction
    Description: add instruction to Ring Memory
    Argin:       pQInstructionNode  quantum Instruction node
                 pQuantumProParam   quantum program param
                 pQGate             quantum gate pointer
    Argout:      pQuantumProParam   quantum program param
    return:      true or false
    *************************************************************************************************************/
    bool getInstruction(QNode * pQInstructionNode, QuantumGateParam *pQuantumProParam, QuantumGates * pQGate);
};

/*****************************************************************************************************************
  Y1:Y1 instruction
*****************************************************************************************************************/
class Y1 : public Instruction
{
public:
    inline Y1()
    {
        mType = Y1_GATE;                                                /* set instruction type                 */
    }
    ~Y1(){};

    /*************************************************************************************************************
    Name:        getInstruction
    Description: add instruction to Ring Memory
    Argin:       pQInstructionNode  quantum Instruction node
                 pQuantumProParam   quantum program param
                 pQGate             quantum gate pointer
    Argout:      pQuantumProParam   quantum program param
    return:      true or false
    *************************************************************************************************************/
    bool getInstruction(QNode * pQInstructionNode, QuantumGateParam *pQuantumProParam, QuantumGates * pQGate);
};

/*****************************************************************************************************************
  Z1:Z1 instruction
*****************************************************************************************************************/
class Z1 : public Instruction
{
public:
    inline Z1()
    {
        mType = Z1_GATE;                                                /* set instruction type                 */
    }
    ~Z1(){};

    /*************************************************************************************************************
    Name:        getInstruction
    Description: add instruction to Ring Memory
    Argin:       pQInstructionNode  quantum Instruction node
                 pQuantumProParam   quantum program param
                 pQGate             quantum gate pointer
    Argout:      pQuantumProParam   quantum program param
    return:      true or false
    *************************************************************************************************************/
    bool getInstruction(QNode * pQInstructionNode, QuantumGateParam *pQuantumProParam, QuantumGates * pQGate);
};

/*****************************************************************************************************************
  T:T instruction
*****************************************************************************************************************/
class T : public Instruction
{
public:
    inline T()
    {
        mType = T_GATE;                                                /* set instruction type                 */
    }
    ~T(){};

    /*************************************************************************************************************
    Name:        getInstruction
    Description: add instruction to Ring Memory
    Argin:       pQInstructionNode  quantum Instruction node
                 pQuantumProParam   quantum program param
                 pQGate             quantum gate pointer
    Argout:      pQuantumProParam   quantum program param
    return:      true or false
    *************************************************************************************************************/
    bool getInstruction(QNode * pQInstructionNode, QuantumGateParam *pQuantumProParam, QuantumGates * pQGate);
};

/*****************************************************************************************************************
  S:S instruction
*****************************************************************************************************************/
class S : public Instruction
{
public:
    inline S()
    {
        mType = S_GATE;                                                /* set instruction type                 */
    }
    ~S(){};

    /*************************************************************************************************************
    Name:        getInstruction
    Description: add instruction to Ring Memory
    Argin:       pQInstructionNode  quantum Instruction node
                 pQuantumProParam   quantum program param
                 pQGate             quantum gate pointer
    Argout:      pQuantumProParam   quantum program param
    return:      true or false
    *************************************************************************************************************/
    bool getInstruction(QNode * pQInstructionNode, QuantumGateParam *pQuantumProParam, QuantumGates * pQGate);
};


/*****************************************************************************************************************
  Y:Y instruction
*****************************************************************************************************************/
class Y : public Instruction
{
public:
    inline Y()
    {
        mType = Y_GATE;                                                /* set instruction type                 */
    }
    ~Y(){};

    /*************************************************************************************************************
    Name:        getInstruction
    Description: add instruction to Ring Memory
    Argin:       pQInstructionNode  quantum Instruction node
                 pQuantumProParam   quantum program param
                 pQGate             quantum gate pointer
    Argout:      pQuantumProParam   quantum program param
    return:      true or false
    *************************************************************************************************************/
    bool getInstruction(QNode * pQInstructionNode, QuantumGateParam *pQuantumProParam, QuantumGates * pQGate);
};


/*****************************************************************************************************************
  CU:CU instruction
*****************************************************************************************************************/
class CU : public Instruction
{
public:
    inline CU()
    {
        mType = CU_GATE;                                                /* set instruction type                 */
    }
    ~CU(){};

    /*************************************************************************************************************
    Name:        getInstruction
    Description: add instruction to Ring Memory
    Argin:       pQInstructionNode  quantum Instruction node
                 pQuantumProParam   quantum program param
                 pQGate             quantum gate pointer
    Argout:      pQuantumProParam   quantum program param
    return:      true or false
    *************************************************************************************************************/
    bool getInstruction(QNode * pQInstructionNode, QuantumGateParam *pQuantumProParam, QuantumGates * pQGate);
};

/*****************************************************************************************************************
  CZ:CZ instruction
*****************************************************************************************************************/
class CZ : public Instruction
{
public:
    inline CZ()
    {
        mType = CZ_GATE;                                                /* set instruction type                 */
    }
    ~CZ(){};

    /*************************************************************************************************************
    Name:        getInstruction
    Description: add instruction to Ring Memory
    Argin:       pQInstructionNode  quantum Instruction node
                 pQuantumProParam   quantum program param
                 pQGate             quantum gate pointer
    Argout:      pQuantumProParam   quantum program param
    return:      true or false
    *************************************************************************************************************/
    bool getInstruction(QNode * pQInstructionNode, QuantumGateParam *pQuantumProParam, QuantumGates * pQGate);
};
#endif
