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
	float out = 0;	// リターン値
	float target_sub = target - now;	// 現在値 - 目標値

	sumsub += target_sub*0.01;	// 0.01は10ms

	// 目標値を境に target_sub の符号が変わるから累積をリセットするキッカケになる
	if (beforeI * target_sub < 0){
		sumsub = 0;
	}

	out = p*target_sub + i*sumsub - d*(now - before)/0.01;	// 0.01は10ms

	before = now;
	beforeI = target_sub;
	return out;
}
