#include "Vector2d.h"

int Vector2d::instancesCount = 0;

Vector2d::Vector2d(float x, float y) : x(x), y(y) {
    ++instancesCount;
}

Vector2d::Vector2d(float x0, float y0, float x1, float y1) : x(x1 - x0), y(y1 - y0) {
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

// update lesson_25
float Vector2d::dotProduct(const Vector2d& other) const {
    return x * other.x + y * other.y;
}

Vector2d Vector2d::negate() const {
    return Vector2d(-x, -y);
}

VectorRelativeState Vector2d::getRelativeState(const Vector2d& other) const {
    float dotProduct = this->dotProduct(other);
    float magnitude1 = this->operator()();
    float magnitude2 = other.operator()();
    float cosAngle = dotProduct / (magnitude1 * magnitude2);

    if (x == other.x && y == other.y) {
        return VectorRelativeState::Identical;
    } else if (cosAngle == 1.0f) {
        return VectorRelativeState::CoDirected;
    } else if (cosAngle == -1.0f) {
        return VectorRelativeState::OppositeDirected;
    } else if (cosAngle > 0.0f && cosAngle < 1.0f) {
        return VectorRelativeState::AcuteAngle;
    } else if (cosAngle < 0.0f && cosAngle > -1.0f) {
        return VectorRelativeState::ObtuseAngle;
    } else if (cosAngle == 0.0f) {
        return VectorRelativeState::RightAngle;
    }

    // Default return value
    return VectorRelativeState::Identical;
}

void Vector2d::scale(float fact_x, float fact_y) {
    x *= fact_x;
    y *= fact_y;
}
