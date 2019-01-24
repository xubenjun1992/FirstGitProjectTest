/*****************************************************************************************************************
Copyright:
Author:Dou Menghan
Date:2017-11-10
Description:x86 quantum logic gates class
*****************************************************************************************************************/
#ifndef _X86_QUANTUM_GATE_H
#define _X86_QUANTUM_GATE_H

#include "QuantumGates.h"
#include <stdio.h>
#include <iostream>

using std::string;
using std::vector;
class CPUQuantumGates : public QuantumGates
{
public:
  QStat mvQuantumStat;

  CPUQuantumGates();

  ~CPUQuantumGates();
  void destoryGPU(){};

  size_t getQStateSize();

  /*************************************************************************************************************
    Name:        getQState
    Description: get quantum state
    Argin:       pQuantumProParam      quantum program param.
    Argout:      sState                state string
    return:      quantum error
    *************************************************************************************************************/
  QStat getQState();

  /*************************************************************************************************************
    Name:        Hadamard
    Description: Hadamard gate,the matrix is:[1/sqrt(2),1/sqrt(2);1/sqrt(2),-1/sqrt(2)]
    Argin:       psi         reference of vector<complex<double>> which contains quantum state information.
                 qn           qubit number that the Hadamard gate operates on.
                 error_rate   the errorrate of the gate
    Argout:      psi         quantum state after the gate
    return:      quantum error
    *************************************************************************************************************/
  QError Hadamard(size_t qn, double error_rate);

  QError Z(size_t qn, double error_rate);

  QError Z(size_t qn, double error_rate, Qnum vControlBit, size_t stQuantumBitNumber);

  QError P0(size_t qn, double error_rate);

  QError P0(size_t qn, double error_rate, Qnum vControlBit, size_t stQuantumBitNumber);

  QError P1(size_t qn, double error_rate);

  QError P1(size_t qn, double error_rate, Qnum vControlBit, size_t stQuantumBitNumber);
  /*************************************************************************************************************
    Name:        Reset
    Description: reset bit gate
    Argin:       qn          qubit number that the Hadamard gate operates on.
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/
  QError Reset(size_t qn);

  /*************************************************************************************************************
    Name:        pMeasure
    Description: pMeasure gate
    Argin:       qnum        qubit bit number vector
                 mResult     reuslt vector
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/
  QError pMeasure(Qnum &qnum, vector<pair<size_t, double>> &mResult);

  /*************************************************************************************************************
    Name:        Hadamard
    Description: controled-Hadamard gate
    Argin:       psi                reference of vector<complex<double>> which contains quantum state information.
                 qn                 qubit number that the Hadamard gate operates on.
                 error_rate         the errorrate of the gate
                 vControlBit        control bit vector
                 stQuantumBitNumber quantum bit number
    Argout:      psi                quantum state after the gate
    return:      quantum error
    *************************************************************************************************************/
  QError Hadamard(size_t qn, double error_rate, Qnum vControlBit, size_t stQuantumBitNumber);

  /*************************************************************************************************************
    Name:        RX
    Description: RX gate,quantum state rotates �� by x axis.The matric is:
                 [cos(��/2),-i*sin(��/2);i*sin(��/2),cos(��/2)]
    Argin:       psi         reference of vector<complex<double>> which contains quantum state information.
                 qn          qubit number that the Hadamard gate operates on.
                 theta       rotation angle
                 error_rate  the errorrate of the gate
    Argout:      psi         quantum state after the gate
    return:      quantum error
    *************************************************************************************************************/
  QError RX(size_t qn, double theta, double error_rate = 0);

  /*************************************************************************************************************
    Name:        RX
    Description: RX dagger gate,quantum state rotates �� by x axis.The matric is:
                 [cos(��/2),-i*sin(��/2);i*sin(��/2),cos(��/2)]
    Argin:       psi         reference of vector<complex<double>> which contains quantum state information.
                 qn          qubit number that the Hadamard gate operates on.
                 theta       rotation angle
                 error_rate  the errorrate of the gate
                 iDagger     is dagger
    Argout:      psi         quantum state after the gate
    return:      quantum error
    *************************************************************************************************************/
  QError RX(size_t qn, double theta, double error_rate, int iDagger);

  /*************************************************************************************************************
    Name:        RX
    Description: controled-RX gate
    Argin:       psi                reference of vector<complex<double>> which contains quantum state information.
                 qn                 qubit number that the Hadamard gate operates on.
                 theta              rotation angle
                 error_rate         the errorrate of the gate
                 vControlBitNumber  control bit number
                 stQuantumBitNumber quantum bit number
    Argout:      psi                quantum state after the gate
    return:      quantum error
    *************************************************************************************************************/
  QError RX(size_t qn,
            double theta,
            double error_rate,
            Qnum vControlBitNumber,
            size_t stQuantumBitNumber);

  /*************************************************************************************************************
    Name:        RX
    Description: controled-RX dagger gate
    Argin:       psi                reference of vector<complex<double>> which contains quantum state information.
                 qn                 qubit number that the Hadamard gate operates on.
                 theta              rotation angle
                 error_rate         the errorrate of the gate
                 vControlBitNumber  control bit number
                 stQuantumBitNumber quantum bit number
                 iDagger            is dagger
    Argout:      psi                quantum state after the gate
    return:      quantum error
    *************************************************************************************************************/
  QError RX(size_t qn,
            double theta,
            double error_rate,
            Qnum vControlBitNumber,
            size_t stQuantumBitNumber,
            int iDagger);

  /*************************************************************************************************************
    Name:        RY
    Description: RY gate,quantum state rotates �� by y axis.The matric is
                 [cos(��/2),-sin(��/2);sin(��/2),cos(��/2)]
    Argin:       psi         reference of vector<complex<double>> which contains quantum state information.
                 qn          qubit number that the Hadamard gate operates on.
                 theta       rotation angle
                 error_rate  the errorrate of the gate
    Argout:      psi         quantum state after the gate
    return:      quantum error
    *************************************************************************************************************/
  QError RY(size_t qn, double theta, double error_rate, int iDagger);

  /*************************************************************************************************************
    Name:        RY
    Description: RY control gate
    Argin:       psi                reference of vector<complex<double>> which contains quantum state information.
                 qn                 qubit number that the Hadamard gate operates on.
                 theta              rotation angle
                 error_rate         the errorrate of the gate
                 vControlBit        control bit vector
                 stQuantumBitNumber quantum bit number
    Argout:      psi                quantum state after the gate
    return:      quantum error
    *************************************************************************************************************/
  QError RY(size_t qn,
            double theta,
            double error_rate,
            Qnum vControlBit,
            size_t stQuantumBitNumber,
            int iDagger);

  /*************************************************************************************************************
    Name:        RZ
    Description: RZ gate,quantum state rotates �� by z axis.The matric is
                 [1 0;0 exp(i*��)]
    Argin:       psi         reference of vector<complex<double>> which contains quantum state information.
                 qn          qubit number that the Hadamard gate operates on.
                 theta       rotation angle
                 error_rate  the errorrate of the gate
                 iDagger     is dagger
    Argout:      psi         quantum state after the gate
    return:      quantum error
    *************************************************************************************************************/
  QError RZ(size_t qn, double theta, double error_rate, int iDagger);

  /*************************************************************************************************************
    Name:        RZ
    Description: RZ gate
    Argin:       psi                reference of vector<complex<double>> which contains quantum state information.
                 qn                 qubit number that the Hadamard gate operates on.
                 theta              rotation angle
                 error_rate         the errorrate of the gate
                 vControlBitNumber  control bit number
                 stQuantumBitNumber quantum bit number
                 iDagger            is dagger
    Argout:      psi                quantum state after the gate
    return:      quantum error
    *************************************************************************************************************/
  QError RZ(size_t qn,
            double heta,
            double error_rate,
            Qnum vControlBitNumber,
            size_t stQuantumBitNumber,
            int iDagger);

  /*************************************************************************************************************
    Name:        CNOT
    Description: CNOT gate,when control qubit is |0>,goal qubit does flip,
                 when control qubit is |1>,goal qubit flips.the matric is:
                 [1 0 0 0;0 1 0 0;0 0 0 1;0 0 1 0]
    Argin:       psi         reference of vector<complex<double>> which contains quantum state information.
                 qn_1        control qubit number
                 qn_2        goal qubit number
                 error_rate  the errorrate of the gate
    Argout:      psi         quantum state after the gate
    return:      quantum error
    *************************************************************************************************************/
  QError CNOT(size_t qn_1, size_t qn_2, double error_rate = 0);

  /*************************************************************************************************************
    Name:        CNOT
    Description: CNOT control gate
    Argin:       psi                reference of vector<complex<double>> which contains quantum state information.
                 qn_1               control qubit number
                 qn_2               goal qubit number
                 error_rate         the errorrate of the gate
                 vControlBitNumber  control bit number
                 stQuantumBitNumber quantum bit number
    Argout:      psi                quantum state after the gate
    return:      quantum error
    *************************************************************************************************************/
  QError CNOT(size_t qn_1,
              size_t qn_2,
              double error_rate,
              Qnum vControlBitNumber,
              int stQuantumBitNumber);

  /*************************************************************************************************************
    Name:        CR
    Description: CR gate,when control qubit is |0>,goal qubit does not rotate,
                 when control qubit is |1>,goal qubit rotate �� by z axis.the matric is:
                 [1 0 0 0;0 1 0 0;0 0 1 0;0 0 0 exp(i*��)]
    Argin:       psi         reference of vector<complex<double>> which contains quantum state information.
                 qn_1        control qubit number
                 qn_2        goal qubit number
                 theta       roration angle
                 error_rate  the errorrate of the gate
                 iDagger     is dagger
    Argout:      psi         quantum state after the gate
    return:      quantum error
    *************************************************************************************************************/
  QError CR(size_t qn_1,
            size_t qn_2,
            double theta,
            double error_rate,
            int iDagger);

  /*************************************************************************************************************
    Name:        iSWAP
    Description: iSWAP gate,both qubits swap and rotate �� by z-axis,the matric is:
    [1 0 0 0;0 0 -i 0;0 -i 0 0;0 0 0 1]
    Argin:       psi         reference of vector<complex<double>> which contains quantum state information.
                 qn_1        first qubit number
                 qn_2        second qubit number
                 error_rate  the errorrate of the gate
                 iDagger     is dagger
    Argout:      psi         quantum state after the gate
    return:      quantum error
    *************************************************************************************************************/
  QError iSWAP(size_t qn_1,
               size_t qn_2,
               double error_rate,
               int iDagger);

  /*************************************************************************************************************
    Name:        iSWAP
    Description: iSWAP gate,both qubits swap and rotate �� by z-axis,the matric is:
    [1 0 0 0;0 0 -i 0;0 -i 0 0;0 0 0 1]
    Argin:       psi         reference of vector<complex<double>> which contains quantum state information.
                 qn_1               first qubit number
                 qn_2               second qubit number
                 error_rate         the errorrate of the gate
                 vControlBitNumber  control bit number
                 stQuantumBitNumber quantum bit number
                 iDagger            is dagger
    Argout:      psi                quantum state after the gate
    return:      quantum error
    *************************************************************************************************************/
  QError iSWAP(size_t qn_1,
               size_t qn_2,
               double error_rate,
               Qnum vControlBitNumber,
               int stQuantumBitNumber,
               int iDagger);

  /*************************************************************************************************************
    Name:        sqiSWAP
    Description: sqiSWAP gate,both qubits swap and rotate �� by z-axis,the matrix is:
                 [1 0 0 0;0 1/sqrt(2) -i/sqrt(2) 0;0 -i/sqrt(2) 1/sqrt(2) 0;0 0 0 1]
    Argin:       psi         reference of vector<complex<double>> which contains quantum state information.
                 qn_1        first qubit number
                 qn_2        second qubit number
                 error_rate  the errorrate of the gate
                 iDagger     is dagger
    Argout:      psi         quantum state after the gate
    return:      quantum error
    *************************************************************************************************************/
  QError sqiSWAP(size_t qn_1,
                 size_t qn_2,
                 double error_rate,
                 int iDagger);

  /*************************************************************************************************************
    Name:        sqiSWAP
    Description: sqiSWAP gate,both qubits swap and rotate �� by z-axis,the matrix is:
                 [1 0 0 0;0 1/sqrt(2) -i/sqrt(2) 0;0 -i/sqrt(2) 1/sqrt(2) 0;0 0 0 1]
    Argin:       psi                reference of vector<complex<double>> which contains quantum state information.
                 qn_1               first qubit number
                 qn_2               second qubit number
                 error_rate         the errorrate of the gate
                 vControlBitNumber  control bit number
                 stQuantumBitNumber quantum bit number
                 iDagger            is dagger
    Argout:      psi                quantum state after the gate
    return:      quantum error
    *************************************************************************************************************/
  QError sqiSWAP(size_t qn_1,
                 size_t qn_2,
                 double error_rate,
                 Qnum vControlBitNumber,
                 int stQuantumBitNumber,
                 int iDagger);

  /*************************************************************************************************************
    Name:        controlSwap
    Description: c-swap gate
    Argin:       psi         reference of vector<complex<double>> which contains quantum state information.
                 qn_1        control qubit number
                 qn_2        1st swap qubit number
                 qn_3        2nd swap qubit number
                 error_rate  the errorrate of the gate
    Argout:      psi         quantum state after the gate
    return:      quantum error
    *************************************************************************************************************/
  QError controlSwap(size_t qn_1, size_t qn_2, size_t qn_3, double error_rate = 0);

  /*************************************************************************************************************
    Name:        qubitMeasure
    Description: measure qubit and the state collapsed
    Argin:       psi   reference of vector<complex<double>> which contains quantum state information.
                 qn    qubit number of the measurement
    Argout:      psi   the state after measurement
    return:      quantum error
    *************************************************************************************************************/
  int qubitMeasure(size_t qn);

  /*************************************************************************************************************
    Name:        unitarySingleQubitGate
    Description: unitary single qubit gate
    Argin:       psi         reference of vector<complex<double>> which contains quantum state information.
                 qn          target qubit number
                 matrix      matrix of the gate
                 error_rate  the errorrate of the gate
    Argout:      psi         the state after measurement
    return:      quantum error
    *************************************************************************************************************/
  QError unitarySingleQubitGate(size_t qn, void *matrix, double error_rate = 0);

  /*************************************************************************************************************
    Name:        initState
    Description: initialize the quantum state
    Argin:       psi       reference of vector<complex<double>> which contains quantum state information.
                 stNumber  Quantum number
    Argout:      psi       the state after measurement
    return:      quantum error
    *************************************************************************************************************/
  QError initState(QuantumGateParam *pQuantumProParam);

  /*************************************************************************************************************
    Name:        matReverse
    Description: change the position of the qubits in 2-qubit gate
    Argin:       (*mat)[4]       pointer of the origin 2D array
                 (*mat_rev)[4]   pointer of the changed 2D array
    Argout:      2D array
    return:      quantum error
    *************************************************************************************************************/
  QError matReverse(COMPLEX (*)[4], COMPLEX (*)[4]);

  /*************************************************************************************************************
    Name:        compareCalculationUnitType
    Description: compare calculation unit type
    Argin:       sCalculationUnitType   external calculation unit type
    Argout:      None
    return:      comparison results
    *************************************************************************************************************/
  bool compareCalculationUnitType(string &sCalculationUnitType);

  /*********************************************************************************************************
    Name:    NOT
    Description: NOT gate,invert the state.The matrix is
                 [0 1;1 0]
    Argin:       psi                reference of vector<complex<double>> which contains quantum state information.
                 qn                 qubit number that the Hadamard gate operates on.
                 error_rate         the errorrate of the gate
    Argout:      psi                quantum state after the gate
    return:      quantum error
    *************************************************************************************************************/
  QError NOT(size_t qn, double error_rate);

  /*************************************************************************************************************
    Name:    NOT
    Description: NOT gate,invert the state.The matrix is
                 [0 1;1 0]
    Argin:       psi                reference of vector<complex<double>> which contains quantum state information.
                 qn                 qubit number that the Hadamard gate operates on.
                 error_rate         the errorrate of the gate
                 vControlBit        control bit vector
                 stQuantumBitNumber quantum bit number
    Argout:      psi                quantum state after the gate
    return:      quantum error
    *************************************************************************************************************/
  QError NOT(size_t qn,
             double error_rate,
             Qnum vControlBit,
             int stQuantumBitNumber);

  /*************************************************************************************************************
    Name:        toffoli
    Description: toffoli dagger gate,the same as toffoli gate
    Argin:       psi                 reference of vector<complex<double>> which contains quantum state information.
                 stControlBit1       first control qubit
                 stControlBit2       the second control qubit
                 stQuantumBit        target qubit
                 errorRate           the errorrate of the gate
                 stQuantumBitNumber  quantum bit number
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/
  QError toffoli(size_t stControlBit1,
                 size_t stControlBit2,
                 size_t stQuantumBit,
                 double errorRate,
                 int stQuantumBitNumber);

  /*************************************************************************************************************
    Name:        endGate
    Description: end gate
    Argin:       pQuantumProParam       quantum program param pointer
                 pQGate                 quantum gate
    Argout:      None
    return:      quantum error
    *************************************************************************************************************/
  QError endGate(QuantumGateParam *pQuantumProParam, QuantumGates *pQGate);

  QError CZ(size_t qn_1,
            size_t qn_2,
            double error_rate,
            int iDagger);

  QError CZ(size_t qn_1,
            size_t qn_2,
            double error_rate,
            Qnum vControlBitNumber,
            int stQuantumBitNumber,
            int iDagger);

protected:
  string sCalculationUnitType = "X86";
};

#endif
