/*
 * MoveSet.h
 *
 *  Created on: 2019/08/16
 *      Author: reiii
 */

#ifndef MOVESET_MOVESET_H_
#define MOVESET_MOVESET_H_
#include "Bezier/Bezier.h"
#include "Move/Move.h"
#include "LowlayerHandel.hpp"

class MoveSet {
	LowlayerHandelTypedef *hlow;	// Library
	Bezier bezier_X;		// �x�W�F�Ȑ��̃N���X X���p
	Bezier bezier_Y;		// �x�W�F�Ȑ��̃N���X Y���p
	Move move;				// �~�܂�񂶂�˂���
public:
	MoveSet(LowlayerHandelTypedef *hlow):move(hlow){
		this->hlow = hlow;
		initial_move = true;
	}
	virtual ~MoveSet();

	bool initial_move;		// aaaa

	void move_zero();
	int move_gakubuti(float dt);
	int move_kyoyu(float dt);
	int move_middle(float dt);
	int move_frontOfgoal(float dt);
	int move_goal(float dt);
};

#endif /* MOVESET_MOVESET_H_ */
