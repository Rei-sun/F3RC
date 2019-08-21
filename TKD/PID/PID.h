/*
 * PID.h
 *
 *  Created on: 2019/08/02
 *      Author: reiii
 */

#ifndef PID_PID_H_
#define PID_PID_H_

class PID {
public:
	PID();
	virtual ~PID();
	void SetParam(float p,float i, float d);
	float OutputPID(float target, float now);
private:
	float p;	// パラメータ P制御
	float i;	// パラメータ I制御
	float d;	// パラメータ D制御
	float sumsub;	// 累積
	float before;	// 前回の値
	float beforeI;	// 	target_sub の前回の値
};

#endif /* PID_PID_H_ */
