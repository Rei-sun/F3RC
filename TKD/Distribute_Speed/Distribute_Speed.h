/*
 * model.h
 *
 *  Created on: 2019/08/02
 *      Author: reiii
 */

#ifndef DISTRIBUTE_SPEED_DISTRIBUTE_SPEED_H_
#define DISTRIBUTE_SPEED_DISTRIBUTE_SPEED_H_

class Distribute_Speed {
public:
	Distribute_Speed();
	void distribute_speed(float now_angle, float x, float y, float r);
	float Wheel_1;
	float Wheel_2;
	float Wheel_3;
	float L;
};

#endif /* DISTRIBUTE_SPEED_DISTRIBUTE_SPEED_H_ */
