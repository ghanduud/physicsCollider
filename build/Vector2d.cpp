#include "Vector2d.h"


Vector2d::Vector2d(float x, float y) {
	this->x = x;
	this->y = y;
}

Vector2d::Vector2d() {

}

Vector2d Vector2d::operator+(Vector2d other) {
	Vector2d v(this->x + other.x, this->y + other.y);
	return v;
}

Vector2d Vector2d::operator-(Vector2d other) {
	Vector2d v(this->x - other.x, this->y - other.y);
	return v;
}

Vector2d Vector2d::operator+=(Vector2d other) {
	Vector2d v(this->x += other.x, this->y += other.y);
	return v;
}

Vector2d Vector2d::operator-=(Vector2d other) {
	Vector2d v(this->x -= other.x, this->y -= other.y);
	return v;
}

void Vector2d::operator=(Vector2d other) {
	this->x = other.x;
	this->y = other.y;
}

bool Vector2d::operator==(Vector2d other) {
	return this->x == other.x && this->y == other.y;
}

Vector2d Vector2d::operator*(float a) {
	return Vector2d(this->x * a, this->y * a);
	
}


Vector2d Vector2d::operator*=(float a) {
	Vector2d v(this->x *= a, this->y *= a);
	return v;
}


float Vector2d::Dot(Vector2d other) {
	return (this->x * other.x) + (this->y * other.y);
}


float Vector2d::getMagnitude() {
	return sqrt((this->x * this->x) + (this->y * this->y));
}

Vector2d Vector2d::getNormalized() {
	float m = this->getMagnitude();
	return Vector2d(this->x / m, this->y / m);
}

void Vector2d::normalize() {
	float mag = getMagnitude();
	if (mag == 0) return;
	this->x /= mag;
	this->y /= mag;
}
