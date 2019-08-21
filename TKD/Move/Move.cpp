/*
 * Move.cpp
 *
 *  Created on: 2019/08/16
 *      Author: reiii
 */

#include <Move/Move.h>
#include "localization/localization.hpp"
#include "LowlayerHandel.hpp"

Move::Move(LowlayerHandelTypedef *hlow){
	this->hlow = hlow;
	this->hlow->loca.Setshitf_X(0.3);   	//機体中心とのずれ_x(m)
	this->hlow->loca.Setshift_y(0.3);   	//機体中心とのずれ_y(m)
	this->hlow->loca.SetDiameter(0.035);  	//エンコーダタイヤ直径(m)
	this->hlow->loca.SetRotaryPulse(2048); 	//パルス
}

Move::~Move() {
	// TODO Auto-generated destructor stub
}

void Move::move(float target_x, float target_y, float target_r){
	float now_X = hlow->loca.GetX();
	float now_Y = hlow->loca.GetY();
	float now_R = hlow->loca.GetYaw();
	float goal_X = PID_X.OutputPID(now_X, target_x);
	float goal_Y = PID_X.OutputPID(now_Y, target_y);
	float goal_R = PID_X.OutputPID(now_R, target_r);
	Model.distribute_speed(now_R, goal_X, goal_Y, goal_R);
	hlow->M1.SetDuty(Model.Wheel_1);
	hlow->M2.SetDuty(Model.Wheel_2);
	hlow->M3.SetDuty(Model.Wheel_3);
}
