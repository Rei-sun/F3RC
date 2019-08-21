/*
 * PID.cpp
 *
 *  Created on: 2019/08/02
 *      Author: reiii
 */

#include "PID.h"

PID::PID() {
	// TODO Auto-generated constructor stub

}

PID::~PID() {
	// TODO Auto-generated destructor stub
}

// PID
void PID::SetParam(float Kp, float Ki, float Kd){
	p = Kp;
	i = Ki;
	d = Kd;
}

float PID::OutputPID(float now, float target){
	float out = 0;	// ���^�[���l
	float target_sub = target - now;	// ���ݒl - �ڕW�l

	sumsub += target_sub*0.01;	// 0.01��10ms

	// �ڕW�l������ target_sub �̕������ς�邩��ݐς����Z�b�g����L�b�J�P�ɂȂ�
	if (beforeI * target_sub < 0){
		sumsub = 0;
	}

	out = p*target_sub + i*sumsub - d*(now - before)/0.01;	// 0.01��10ms

	before = now;
	beforeI = target_sub;
	return out;
}
