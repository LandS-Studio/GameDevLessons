#pragma once
#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>

enum class VectorRelativeState {
    Identical,
    CoDirected,
    OppositeDirected,
    AcuteAngle,
    ObtuseAngle,
    RightAngle
};

class Vector2d {
public:
    Vector2d(float x = 0.0, float y = 0.0);

    // update lesson_25
    Vector2d(float x0, float y0, float x1, float y1);

    Vector2d& operator=(const Vector2d& other);
    
    float& operator[](std::size_t idx);
    void operator*=(float scalar);
    float operator()() const;
    
    friend std::ostream& operator<<(std::ostream& out, const Vector2d& vector);
    friend std::istream& operator>>(std::istream& in, Vector2d& vector);
    friend Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector);
    friend Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector);

    static int getInstancesCount();

    // update lesson_25
    float dotProduct(const Vector2d& other) const;
    Vector2d negate() const;
    VectorRelativeState getRelativeState(const Vector2d& other) const;
    void scale(float fact_x, float fact_y);

private:
    float x, y;
    static int instancesCount;
};

#endif