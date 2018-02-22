#include "pendulum.h"
#define _USE_MATH_DEFINES
#include <cmath>

pendulum::pendulum()
{
	centerX = 0.f;
	centerY = 0.f;
	length = 50.f;
	radius = 10.f;
	x = 0.f;
	y = 0.f;
	vx = 0.f;
	vy = 0.f;
	g = .1f;
}

pendulum::pendulum(float centerX, float centerY, float length, float radius, float x, float y)
{
	pendulum::centerX = centerX;
	pendulum::centerY = centerY;
	pendulum::length = length;
	pendulum::radius = radius;
	pendulum::x = x;
	pendulum::y = y;
	vx = 0;
	vy = 0;
	g = .1f;
}

void pendulum::calculateNewPos()
{
	vy += g;
	float v = length - sqrtf(powf(x - centerX, 2) + powf(y - centerY, 2)) - sqrtf(vx * vx + vy * vy);
	float angle = atan((centerY - y) / (x - centerX));
	angle = x - centerX > 0 ? angle : angle + M_PI;
	vx += v * cos(angle);
	vy -= v * sin(angle);

	x += vx;
	y += vy;
}

void pendulum::moveCenter(float x, float y)
{
	centerX = x;
	centerY = y;
}

float pendulum::getX()
{
	return x;
}

float pendulum::getY()
{
	return y;
}

float pendulum::getCenterX()
{
	return centerX;
}

float pendulum::getCenterY()
{
	return centerY;
}

float pendulum::getRadius()
{
	return radius;
}
