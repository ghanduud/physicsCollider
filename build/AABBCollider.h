#pragma once
#include "Vector2d.h"

class AABBCollider {
public:
    Vector2d ul;   
    Vector2d lr;     
    Vector2d position;



    void updatePosition(Vector2d newPosition) {
        Vector2d offset = newPosition - position;
        ul += offset;
        lr += offset;
        position = newPosition;
    }


    bool checkCollision(AABBCollider other) {
        return !(lr.x < other.ul.x ||
            ul.x > other.lr.x ||
            lr.y < other.ul.y ||
            ul.y > other.lr.y);
    }
};
