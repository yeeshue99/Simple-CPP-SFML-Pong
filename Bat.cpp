#include "Bat.h"

Bat::Bat(float startx, float starty, float sizex, float sizey, float speed, Color color) {
	position.x = startx;
	position.y = starty;

	size = sf::Vector2f(sizex, sizey);

	batShape.setSize(size);
	batShape.setPosition(position);
	batShape.setFillColor(color);

	batSpeed = speed;
}

FloatRect Bat::GetPosition() {
	return batShape.getGlobalBounds();
}

RectangleShape Bat::GetShape() {
	return batShape;
}

void Bat::MoveLeft() {
	position.x -= batSpeed;
}

void Bat::MoveRight(){
	position.x += batSpeed;
}

void Bat::Update() {
	batShape.setPosition(position);
}