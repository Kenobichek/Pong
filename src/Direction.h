#pragma once

class Direction
{
public:
	Direction() {};
	Direction(const double& x, const double& y) : x(x), y(y) {};

	void randomizeDirection();
	void setX(const double& x);
	void setY(const double& y);
	double getX();
	double getY();

	friend Direction operator+(const Direction& a, const Direction& b);
	friend Direction operator-(const Direction& a, const Direction& b);
	friend Direction operator*(const Direction& a, const Direction& b);
	Direction operator/(const double& del);

private:
	double x = 0;
	double y = 0;
};