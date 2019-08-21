/*
 * MoveSet.cpp
 *
 *  Created on: 2019/08/16
 *      Author: reiii
 */

#include <MoveSet/MoveSet.h>
#include "Bezier/Bezier.h"
#include "LowlayerHandel.hpp"
#include "Move/Move.h"

#define ElapseT(t, d)	t / (200.0 * d)	// 1000ms / 5ms

MoveSet::~MoveSet() {
	// TODO Auto-generated destructor stub
}

void MoveSet::move_zero(){
	if(initial_move){
		move.PID_X.SetParam(0,0,0);
		move.PID_Y.SetParam(0,0,0);
		move.PID_R.SetParam(0,0,0);
		initial_move = false;
	}
	move.move(0, 0, 0);
}

int MoveSet::move_gakubuti(float dt){
	if(initial_move){
		move.PID_X.SetParam(0,0,0);
		move.PID_Y.SetParam(0,0,0);
		move.PID_R.SetParam(0,0,0);
		initial_move = false;
	}
	float t = ElapseT(dt, 5);	//
	if(t >= 1){
		t = 1;
		initial_move = true;
	}
	float tx = bezier_X.Bezier3(t, 2756.f, 2756.f, 2560.f, 2560.f);
	float ty = bezier_Y.Bezier3(t, 244.f, 244.f, 244.f, 3684.f);
	move.move(tx, ty, 0);

	return (int)t;
}

int MoveSet::move_kyoyu(float dt){
	if(initial_move){
		move.PID_X.SetParam(0,0,0);
		move.PID_Y.SetParam(0,0,0);
		move.PID_R.SetParam(0,0,0);
		initial_move = false;
	}
	float t = ElapseT(dt, 5);	// 5•b
	if(t >= 1){
		t = 1;
		initial_move = true;
	}
	float tx = bezier_X.Bezier3(t, 2560.f, 2560.f, 3000.f, 1600.f);
	float ty = bezier_Y.Bezier3(t, 3684.f, 244.f, 244.f, 244.f);
	move.move(tx, ty, 0);

	return (int)t;
}

int MoveSet::move_middle(float dt){
	if(initial_move){
		move.PID_X.SetParam(0,0,0);
		move.PID_Y.SetParam(0,0,0);
		move.PID_R.SetParam(0,0,0);
		initial_move = false;
	}
	float t = ElapseT(dt, 5);	// 5•b
	if(t >= 1){
		t = 1;
		initial_move = true;
	}
	float tx = bezier_X.Bezier3(t, 1600.f, 3500.f, 2400.f, 2556.f);
	float ty = bezier_Y.Bezier3(t, 244.f, 244.f, 1200.f, 2800.f);
	move.move(tx, ty, 0);

	return (int)t;
}

int MoveSet::move_frontOfgoal(float dt){
	if(initial_move){
		move.PID_X.SetParam(0,0,0);
		move.PID_Y.SetParam(0,0,0);
		move.PID_R.SetParam(0,0,0);
		initial_move = false;
	}
	float t = ElapseT(dt, 5);	// 5•b
	if(t >= 1){
		t = 1;
		initial_move = true;
	}
	float tx = bezier_X.Bezier3(t, 2556.f, 2556.f, 1300.f, 1300.f);
	float ty = bezier_Y.Bezier3(t, 2800.f, 4400.f, 2800.f, 4400.f);
	move.move(tx, ty, 0);

	return (int)t;
}

int MoveSet::move_goal(float dt){
	if(initial_move){
		move.PID_X.SetParam(0,0,0);
		move.PID_Y.SetParam(0,0,0);
		move.PID_R.SetParam(0,0,0);
		initial_move = false;
	}
	float t = ElapseT(dt, 5);	// 5•b
	if(t >= 1){
		t = 1;
		initial_move = true;
	}
	float tx = bezier_X.Bezier3(t, 1300.f, 1300.f, 2600.f, 2600.f);
	float ty = 4400.f;
	move.move(tx, ty, 0);

	return (int)t;
}
