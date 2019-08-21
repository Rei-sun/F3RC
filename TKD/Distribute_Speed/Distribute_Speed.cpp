/*
 * model.cpp
 *
 *  Created on: 2019/08/02
 *      Author: reiii
 */

#include "Distribute_Speed/Distribute_Speed.h"
#include <math.h>

Distribute_Speed::Distribute_Speed(){

}

void Distribute_Speed::distribute_speed(float theta, float x, float y, float r) {
	Wheel_1 =  x * cos(theta) + y * sin(theta) + L * r;
	Wheel_2 =  x * cos(theta + 2/3*M_PI) + y * sin(theta + 2/3*M_PI) + L * r;
	Wheel_3 =  x * cos(theta + 1/3*M_PI) + y * sin(theta + 1/3*M_PI) + L * r;
}
