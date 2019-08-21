/*
 * Bezier.cpp
 *
 *  Created on: 2019/08/10
 *      Author: reiii
 */
#include "Bezier.h"

Bezier::Bezier(){

}

float Bezier::Bezier3(float t, float a1, float a2, float a3, float a4){
	float rt = 1 - t;
	return t * t * t * a4 + 3 * t * t * rt * a3 + 3 * t * rt * rt * a2 + rt * rt * rt * a1;
}




