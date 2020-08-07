#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball {
private:
	Vector2f position;
	Vector2f size;
	Vector2f velocity = Vector2f(0.1f, 0.1f);
	RectangleShape ballShape;

public:
	Ball(float startx, float starty, float sizex, float sizey, Color color);
	FloatRect GetPosition();
	RectangleShape GetShape();

	float GetxVelocity();
	float GetyVelocity();

	void ReboundSide();
	void ReboundBat();
	void HitBottom();
	void Update();
};