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
	float p;	// �p�����[�^ P����
	float i;	// �p�����[�^ I����
	float d;	// �p�����[�^ D����
	float sumsub;	// �ݐ�
	float before;	// �O��̒l
	float beforeI;	// 	target_sub �̑O��̒l
};

#endif /* PID_PID_H_ */
