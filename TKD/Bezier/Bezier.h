/*
 * Bezier.h
 *
 *  Created on: 2019/08/10
 *      Author: reiii
 */

#ifndef BEZIER_H_
#define BEZIER_H_
#include "LowlayerHandel.hpp"
class Bezier{
public:
	Bezier();
	float Bezier3(float t, float a1, float a2, float a3, float a4);
};

#endif /* BEZIER_H_ */
