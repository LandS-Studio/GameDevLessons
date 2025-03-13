#include <iostream>
#include "Vector2d.h"

int main() {
    Vector2d v1(1.0, 2.0);
    Vector2d v2(2.0, 3.0);

    float dot = v1.dotProduct(v2);
    std::cout << "Dot product: " << dot << std::endl;

    Vector2d negate = v1.negate();
    std::cout << "Negate: " << negate << std::endl;

    VectorRelativeState state = v1.getRelativeState(v2);
    std::cout << "Relative state: " << static_cast<int>(state) << std::endl;

    v1.scale(2.0, 3.0);
    std::cout << "Scale: " << v1 << std::endl;
    
    return 0;
}
