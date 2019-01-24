/*****************************************************************************************************************
Copyright:
Author:Dou Menghan
Date:2017-11-10
Description:the Parent of quantum logic gates class
*****************************************************************************************************************/
#ifndef _QUANTUM_GATE_H
#define _QUANTUM_GATE_H
#include <iostream>
#include <stdio.h>
#include <vector>
#include <complex>
#include <map>
#include "QuantumGateParameter.h"
#include "QError.h"
using std::complex;
using std::map;
using std::pair;
using std::size_t;
using std::string;
using std::vector;

typedef complex<double> COMPLEX;
typedef vector<size_t> Qnum;
typedef vector<complex<double>> QStat;

/*****************************************************************************************************************
QuantumGates:quantum gate
*****************************************************************************************************************/
class QuantumGates
{

  public:
    QuantumGates();
    virtual ~QuantumGates() = 0;
    double randGenerator();
    virtual size_t getQStateSize() = 0;
    /*************************************************************************************************************
    Name:        getQState
    Description: get quantum state
    Argin:       pQuantumProParam      quantum program param.
    Argout:      sState                state string
    return:      quantum error
    *************************************************************************************************************/
    virtual QStat getQState() = 0;

    /*************************************************************************************************************
    Name:        Hadamard
    Description: Hadamard gate,the matrix is:[1/sqrt(2),1/sqrt(2);1/sqrt(2),-1/sqrt(2)]
    Argin:       qn          qubit number that the Hadamard gate operates on.
    error_rate  the errorrate of the gate
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/
    virtual QError Hadamard(size_t qn, double error_rate) = 0;

    /*************************************************************************************************************
    Name:        Reset
    Description: reset bit gate
    Argin:       qn          qubit number that the Hadamard gate operates on.
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/
    virtual QError Reset(size_t qn) = 0;

    /*************************************************************************************************************
    Name:        pMeasure
    Description: pMeasure gate
    Argin:       qnum        qubit bit number vector
    mResult     reuslt vector
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/
    virtual QError pMeasure(Qnum &qnum, vector<pair<size_t, double>> &mResult) = 0;

    /*************************************************************************************************************
    Name:        Hadamard
    Description: Hadamard gate,the matrix is:[1/sqrt(2),1/sqrt(2);1/sqrt(2),-1/sqrt(2)]
    Argin:       qn                 qubit number that the Hadamard gate operates on.
    error_rate         the errorrate of the gate
    vControlBit        control bit vector
    stQuantumBitNumber quantum bit number
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/
    virtual QError Hadamard(size_t qn,
                            double error_rate,
                            Qnum vControlBit,
                            size_t stQuantumBitNumber) = 0;

    /*************************************************************************************************************
    Name:        Hadamard
    Description: Hadamard gate,the matrix is:[1/sqrt(2),1/sqrt(2);1/sqrt(2),-1/sqrt(2)]
    Argin:       qn                 qubit number that the Hadamard gate operates on.
    error_rate         the errorrate of the gate
    vControlBit        control bit vector
    stQuantumBitNumber quantum bit number
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/

    virtual QError Z(size_t qn, double error_rate) = 0;

    virtual QError Z(size_t qn,
                     double error_rate,
                     Qnum vControlBit,
                     size_t stQuantumBitNumber) = 0;

    virtual QError P0(size_t qn, double error_rate) = 0;

    virtual QError P0(size_t qn,
                      double error_rate,
                      Qnum vControlBit,
                      size_t stQuantumBitNumber) = 0;

    virtual QError P1(size_t qn, double error_rate) = 0;

    virtual QError P1(size_t qn,
                      double error_rate,
                      Qnum vControlBit,
                      size_t stQuantumBitNumber) = 0;
    /*************************************************************************************************************
    Name:        RX
    Description: RX gate,quantum state rotates �� by x axis.The matric is:
    [cos(��/2),-i*sin(��/2);i*sin(��/2),cos(��/2)]
    Argin:       qn                 qubit number that the Hadamard gate operates on.
    theta              rotation angle
    error_rate         the errorrate of the gate
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/
    // virtual QError RX(size_t qn, double theta, double error_rate) = 0;

    /*************************************************************************************************************
    Name:        RX
    Description: RX dagger gate,quantum state rotates �� by x axis.The matric is:
    [cos(��/2),-i*sin(��/2);i*sin(��/2),cos(��/2)]
    Argin:       qn          qubit number that the Hadamard gate operates on.
    theta       rotation angle
    error_rate  the errorrate of the gate
    iDagger     is dagger
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/
    virtual QError RX(size_t qn, double theta, double error_rate, int iDagger) = 0;

    /*************************************************************************************************************
    Name:        RX
    Description: controled-RX gate
    Argin:       qn                 qubit number that the Hadamard gate operates on.
    theta              rotation angle
    error_rate         the errorrate of the gate
    vControlBitNumber  control bit number
    stQuantumBitNumber quantum bit number
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/
    /*virtual QError RX(size_t  qn,
    double  theta,
    double  error_rate,
    Qnum    vControlBitNumber,
    size_t  stQuantumBitNumber) = 0;*/

    /*************************************************************************************************************
    Name:        RX
    Description: controled-RX dagger gate
    Argin:       qn                 qubit number that the Hadamard gate operates on.
    theta              rotation angle
    error_rate         the errorrate of the gate
    vControlBitNumber  control bit number
    stQuantumBitNumber quantum bit number
    iDagger            is dagger
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/
    virtual QError RX(size_t qn,
                      double theta,
                      double error_rate,
                      Qnum vControlBitNumber,
                      size_t stQuantumBitNumber,
                      int iDagger) = 0;

    /*************************************************************************************************************
    Name:        RY
    Description: RY gate,quantum state rotates �� by y axis.The matric is
    [cos(��/2),-sin(��/2);sin(��/2),cos(��/2)]
    Argin:       qn          qubit number that the Hadamard gate operates on.
    theta       rotation angle
    error_rate  the errorrate of the gate
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/
    virtual QError RY(size_t qn, double theta, double error_rate, int iDagger) = 0;

    /*************************************************************************************************************
    Name:        RY
    Description: RY control gate
    Argin:       qn                 qubit number that the Hadamard gate operates on.
    theta              rotation angle
    error_rate         the errorrate of the gate
    vControlBit        control bit vector
    stQuantumBitNumber quantum bit number
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/
    virtual QError RY(size_t qn,
                      double theta,
                      double error_rate,
                      Qnum vControlBit,
                      size_t stQuantumBitNumber,
                      int iDagger) = 0;

    /*************************************************************************************************************
    Name:        RZ
    Description: RZ gate,quantum state rotates �� by z axis.The matric is
    [1 0;0 exp(i*��)]
    Argin:       qn          qubit number that the Hadamard gate operates on.
    theta       rotation angle
    error_rate  the errorrate of the gate
    iDagger     is dagger
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/
    virtual QError RZ(size_t qn,
                      double theta,
                      double error_rate,
                      int iDagger) = 0;

    /*************************************************************************************************************
    Name:        RZ
    Description: RZ control gate
    Argin:       qn                 qubit number that the Hadamard gate operates on.
    theta              rotation angle
    error_rate         the errorrate of the gate
    vControlBitNumber  control bit number
    stQuantumBitNumber quantum bit number
    iDagger            is dagger
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/
    virtual QError RZ(size_t qn,
                      double theta,
                      double error_rate,
                      Qnum vControlBitNumber,
                      size_t stQuantumBitNumber,
                      int iDagger) = 0;

    /*************************************************************************************************************
    Name:        CNOT
    Description: CNOT gate,when control qubit is |0>,goal qubit does flip,
    when control qubit is |1>,goal qubit flips.the matric is:
    [1 0 0 0;0 1 0 0;0 0 0 1;0 0 1 0]
    Argin:       qn_1        control qubit number
    qn_2        goal qubit number
    error_rate  the errorrate of the gate
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/
    virtual QError CNOT(size_t qn_1, size_t qn_2, double error_rate) = 0;

    /*************************************************************************************************************
    Name:        CNOT
    Description: CNOT control gate
    Argin:       qn_1               control qubit number
    qn_2               goal qubit number
    error_rate         the errorrate of the gate
    vControlBitNumber  control bit number
    stQuantumBitNumber quantum bit number
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/
    virtual QError CNOT(size_t qn_1,
                        size_t qn_2,
                        double error_rate,
                        Qnum vControlBitNumber,
                        int stQuantumBitNumber) = 0;

    /*************************************************************************************************************
    Name:        CR
    Description: CR gate,when control qubit is |0>,goal qubit does not rotate,
    when control qubit is |1>,goal qubit rotate �� by z axis.the matric is:
    [1 0 0 0;0 1 0 0;0 0 1 0;0 0 0 exp(i*��)]
    Argin:       qn_1        control qubit number
    qn_2        goal qubit number
    theta       roration angle
    error_rate  the errorrate of the gate
    iDagger     is dagger
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/
    virtual QError CR(size_t qn_1, size_t qn_2, double theta, double error_rate, int iDagger) = 0;

    /*************************************************************************************************************
    Name:        iSWAP
    Description: iSWAP gate,both qubits swap and rotate �� by z-axis,the matric is:
    [1 0 0 0;0 0 -i 0;0 -i 0 0;0 0 0 1]
    Argin:       qn_1        first qubit number
    qn_2        second qubit number
    error_rate  the errorrate of the gate
    iDagger     is dagger
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/
    virtual QError iSWAP(size_t qn_1,
                         size_t qn_2,
                         double error_rate,
                         int iDagger) = 0;

    /*************************************************************************************************************
    Name:        iSWAP
    Description: iSWAP gate,both qubits swap and rotate �� by z-axis,the matric is:
    [1 0 0 0;0 0 -i 0;0 -i 0 0;0 0 0 1]
    Argin:       qn_1        first qubit number
    qn_2        second qubit number
    error_rate  the errorrate of the gate
    vControlBitNumber  control bit number
    stQuantumBitNumber quantum bit number
    iDagger     is dagger
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/
    virtual QError iSWAP(size_t qn_1,
                         size_t qn_2,
                         double error_rate,
                         Qnum vControlBitNumber,
                         int stQuantumBitNumber,
                         int iDagger) = 0;

    /*************************************************************************************************************
    Name:        sqiSWAP
    Description: sqiSWAP gate,both qubits swap and rotate �� by z-axis,the matrix is:
    [1 0 0 0;0 1/sqrt(2) -i/sqrt(2) 0;0 -i/sqrt(2) 1/sqrt(2) 0;0 0 0 1]
    Argin:       qn_1        first qubit number
    qn_2        second qubit number
    error_rate  the errorrate of the gate
    iDagger     is dagger
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/
    virtual QError sqiSWAP(size_t qn_1,
                           size_t qn_2,
                           double error_rate,
                           int iDagger) = 0;

    /*************************************************************************************************************
    Name:        sqiSWAP
    Description: sqiSWAP gate,both qubits swap and rotate �� by z-axis,the matrix is:
    [1 0 0 0;0 1/sqrt(2) -i/sqrt(2) 0;0 -i/sqrt(2) 1/sqrt(2) 0;0 0 0 1]
    Argin:       qn_1        first qubit number
    qn_2        second qubit number
    error_rate  the errorrate of the gate
    vControlBitNumber  control bit number
    stQuantumBitNumber quantum bit number
    iDagger     is dagger
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/
    virtual QError sqiSWAP(size_t qn_1,
                           size_t qn_2,
                           double error_rate,
                           Qnum vControlBitNumber,
                           int stQuantumBitNumber,
                           int iDagger) = 0;

    /*************************************************************************************************************
    Name:        controlSwap
    Description: c-swap gate
    Argin:       qn_1        control qubit number
    qn_2        1st swap qubit number
    qn_3        2nd swap qubit number
    error_rate  the errorrate of the gate
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/
    virtual QError controlSwap(size_t qn_1, size_t qn_2, size_t qn_3, double error_rate) = 0;

    /*************************************************************************************************************
    Name:        qubitMeasure
    Description: measure qubit and the state collapsed
    Argin:       qn    qubit number of the measurement
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/
    virtual int qubitMeasure(size_t qn) = 0;

    /*************************************************************************************************************
    Name:        unitarySingleQubitGate
    Description: unitary single qubit gate
    Argin:       qn          target qubit number
    matrix      matrix of the gate
    error_rate  the errorrate of the gate
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/
    virtual QError unitarySingleQubitGate(size_t qn, void *matrix, double error_rate) = 0;

    /*************************************************************************************************************
    Name:        initState
    Description: initialize the quantum state
    Argin:       stNumber  Quantum number
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/
    virtual QError initState(QuantumGateParam *pQuantumProParam) = 0;

    /*************************************************************************************************************
    Name:        compareCalculationUnitType
    Description: compare calculation unit type
    Argin:       sCalculationUnitType   external calculation unit type
    Argout:      None
    return:      comparison results
    *************************************************************************************************************/
    virtual bool compareCalculationUnitType(string &sCalculationUnitType) = 0;

    /*************************************************************************************************************
    Name:    NOT
    Description: NOT gate,invert the state.The matrix is
    [0 1;1 0]
    Argin:       qn                 qubit number that the Hadamard gate operates on.
    error_rate         the errorrate of the gate
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/
    virtual QError NOT(size_t qn, double error_rate) = 0;

    /*************************************************************************************************************
    Name:    NOT
    Description: NOT gate,invert the state.The matrix is
    [0 1;1 0]
    Argin:       qn                 qubit number that the Hadamard gate operates on.
    error_rate         the errorrate of the gate
    vControlBit        control bit vector
    stQuantumBitNumber quantum bit number
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/
    virtual QError NOT(size_t qn,
                       double error_rate,
                       Qnum vControlBit,
                       int stQuantumBitNumber) = 0;

    /*************************************************************************************************************
    Name:        toffoli
    Description: toffoli dagger gate,the same as toffoli gate
    Argin:       stControlBit1       first control qubit
    stControlBit2       the second control qubit
    stQuantumBit        target qubit
    errorRate           the errorrate of the gate
    stQuantumBitNumber  quantum bit number
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/
    virtual QError toffoli(size_t stControlBit1,
                           size_t stControlBit2,
                           size_t stQuantumBit,
                           double errorRate,
                           int stQuantumBitNumber) = 0;

    /*************************************************************************************************************
    Name:        destroyState
    Description: dwstroy quantum state
    Argin:       stQNum      the number of quantum bit.
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/
    virtual QError destroyState(size_t stQNum) { return qErrorNone; };

    /*************************************************************************************************************
    Name:        endGate
    Description: end gate
    Argin:       pQuantumProParam       quantum program param pointer
    pQGate                 quantum gate
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/
    virtual QError endGate(QuantumGateParam *pQuantumProParam, QuantumGates *pQGate) = 0;

    virtual QError CZ(size_t qn_1,
                      size_t qn_2,
                      double error_rate,
                      int iDagger) = 0;


  protected:
    string sCalculationUnitType = "GPU";
    /*************************************************************************************************************
    Name:        randGenerator
    Description: 16807 random number generator
    Argin:       None
    Argout:      None
    return:      random number in the region of [0,1]
    *************************************************************************************************************/
    //double randGenerator();

    /*************************************************************************************************************
    Name:        matReverse
    Description: change the position of the qubits in 2-qubit gate
    Argin:       (*mat)[4]       pointer of the origin 2D array
    (*mat_rev)[4]   pointer of the changed 2D array
    Argout:      2D array
    return:      quantum error
    *************************************************************************************************************/
    virtual QError matReverse(COMPLEX (*)[4], COMPLEX (*)[4]) = 0;
};

#endif
