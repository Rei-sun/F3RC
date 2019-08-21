/*
 * Move.h
 *
 *  Created on: 2019/08/16
 *      Author: reiii
 */

#ifndef MOVE_MOVE_H_
#define MOVE_MOVE_H_

#include "PID/PID.h"
#include "Distribute_Speed/Distribute_Speed.h"
#include "localization/localization.hpp"
#include "LowlayerHandel.hpp"

class Move {
public:
	Move(LowlayerHandelTypedef *hlow);
	virtual ~Move();
	Distribute_Speed Model;		// 三輪オムニの出力配分のクラス
	PID PID_X;					// PID X軸用
	PID PID_Y;					// PID Y軸用
	PID PID_R;					// PID 回転軸用
	LowlayerHandelTypedef *hlow;
	void move(float target_x, float target_y, float target_r);
};

#endif /* MOVE_MOVE_H_ */
