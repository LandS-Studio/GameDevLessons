#include "Vector2d.h"

int Vector2d::instancesCount = 0;

Vector2d::Vector2d(float x, float y) : x(x), y(y) {
    ++instancesCount;
}

Vector2d& Vector2d::operator=(const Vector2d& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

float& Vector2d::operator[](std::size_t idx) {
    if (idx == 0) return x;
    if (idx == 1) return y;
    std::cout << "Invalid index" << std::endl;
}

void Vector2d::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
}

float Vector2d::operator()() const {
    return sqrt(x * x + y * y);
}

std::ostream& operator<<(std::ostream& out, const Vector2d& vector) {
    out << "{" << vector.x << "; " << vector.y << "}";
    return out;
}

std::istream& operator>>(std::istream& in, Vector2d& vector) {
    std::cout << "Enter 'x': ";
    in >> vector.x;
    std::cout << "Enter 'y': ";
    in >> vector.y;
    return in;
}

Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector) {
    return Vector2d(leftVector.x + rightVector.x, leftVector.y + rightVector.y);
}

Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector) {
    return Vector2d(leftVector.x - rightVector.x, leftVector.y - rightVector.y);
}

int Vector2d::getInstancesCount() {
    return instancesCount;
}