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
	Distribute_Speed Model;		// �O�փI���j�̏o�͔z���̃N���X
	PID PID_X;					// PID X���p
	PID PID_Y;					// PID Y���p
	PID PID_R;					// PID ��]���p
	LowlayerHandelTypedef *hlow;
	void move(float target_x, float target_y, float target_r);
};

#endif /* MOVE_MOVE_H_ */
