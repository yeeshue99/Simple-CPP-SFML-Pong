#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bat {
private:
	Vector2f position;
	Vector2f size;
	RectangleShape batShape;

	float batSpeed;

public:
	Bat(float startx, float starty, float sizex, float sizey, float speed, Color color);
	FloatRect GetPosition();
	RectangleShape GetShape();

	void MoveLeft();
	void MoveRight();
	void Update();

};