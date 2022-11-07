#include "Direction.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <cstdlib>
#include <random>

Direction operator+(const Direction& a, const Direction& b)
{
	return Direction(a.x + b.x, a.y + b.y);
}

Direction operator-(const Direction& a, const Direction& b)
{
	return Direction(a.x - b.x, a.y - b.y);
}

Direction operator*(const Direction& a, const Direction& b)
{
	return Direction(a.x * b.x, a.y * b.y);
}

Direction Direction::operator/(const double& del)
{
	return Direction(this->x / del, this->y / del);
}

void Direction::randomizeDirection()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(-M_PI_4, M_PI_4);
	std::uniform_int_distribution<> randSign(0, 1);
	int sign = randSign(gen) ? 1 : -1;
	double angle = dis(gen);
	x = cos(angle) * sign;
	y = sin(angle);
}

void Direction::setX(const double& x)
{
	this->x = x;
}

void Direction::setY(const double& y)
{
	this->y = y;
}

double Direction::getX()
{
	return x;
}

double Direction::getY()
{
	return y;
}
