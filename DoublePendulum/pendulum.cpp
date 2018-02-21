#include "pendulum.h"
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
	g = 1.f;
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
	g = 1.f;
}

void pendulum::calculateNewPos(float delta)
{
	if (pow(x - centerX, 2) + pow(y - centerY, 2) > length * length)
	{

	}
	vx += g;

	x += vx;
	y += vy;
}

void pendulum::moveCenter(float dx, float dy)
{
	centerX += dx;
	centerY += dy;
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
