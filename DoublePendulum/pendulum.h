#pragma once

class pendulum
{
private:
	float centerX, centerY, length, radius, x, y, vx, vy, g;
public:
	pendulum();
	pendulum(float centerX, float centerY, float length, float radius, float x, float y);
	void calculateNewPos();
	void moveCenter(float x, float y);
	float getX();
	float getY();
	float getCenterX();
	float getCenterY();
	float getRadius();
};