#pragma once
#include "Vector2d.h"
#include <iostream>

using namespace std;
class Collider
{
public :
	float r;
	Vector2d center;

	bool checkCollision(Collider other)
	{
		return (other.center - center).getMagnitude() < (other.r + r);
	}
};

