#pragma once

class pendulum
{
private:
	float center, length, radius, x, y, vx, vy;
public:
	pendulum();
	pendulum(float center, float length, float radius, float x, float y);
	void calculateNewPos(float delta);
	void moveCenter(float dx, float dy);
	float getX();
	float getY();
	float getCenter();
	float getRadius();
};