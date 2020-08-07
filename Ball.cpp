#include "Ball.h"

Ball::Ball(float startx, float starty, float sizex, float sizey, Color color) {
	position.x = startx;
	position.y = starty;

	size = sf::Vector2f(sizex, sizey);
	ballShape.setSize(size);
	ballShape.setPosition(position);
	ballShape.setFillColor(color);
}
FloatRect Ball::GetPosition() {
	return ballShape.getGlobalBounds();
}
RectangleShape Ball::GetShape() {
	return ballShape;
}

float Ball::GetxVelocity() {
	return velocity.x;
}
float Ball::GetyVelocity() {
	return velocity.y;
}

void Ball::ReboundSide() {
	velocity.x = -velocity.x;
}
void Ball::ReboundBat() {
	position.y -= velocity.y * 30;
	if (velocity.y > 0) {
		velocity.y += 0.05f;
	}
	if (velocity.y < 0) {
		velocity.y -= 0.05f;
	}

	velocity.y = -velocity.y;

}
void Ball::HitBottom() {
	position.x = 500;
	position.y = 1;
	velocity.y = 0.1f;
}
void Ball::Update() {
	position.x += velocity.x;
	position.y += velocity.y;

	ballShape.setPosition(position);
}