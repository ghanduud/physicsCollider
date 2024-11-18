#pragma once
#include "Vector2d.h"
#include <vector>
#include <algorithm> // For std::max and std::min

class SATCollider {
public:
    Vector2d position;
    std::vector<Vector2d> points;


    void updatePosition(Vector2d newPosition) {
        Vector2d offset = newPosition - position;
        position = newPosition;

        for (auto& point : points) {
            point += offset;
        }
    }

    bool checkCollision( SATCollider& other) {

        auto normals = getNormals();
        auto otherNormals = other.getNormals();
        normals.insert(normals.end(), otherNormals.begin(), otherNormals.end());


        for (const auto& normal : normals) {
            Vector2d projectionA = projectShape(normal);
            Vector2d projectionB = other.projectShape(normal);


            if (projectionA.y < projectionB.x || projectionB.y < projectionA.x) {
                return false; 
            }
        }
        return true; 
    }

    std::vector<Vector2d> getNormals() {
        std::vector<Vector2d> normals;

        for (size_t i = 0; i < this->points.size(); ++i) {
            Vector2d p1 = points[i];
            Vector2d p2 = points[(i + 1) % points.size()];

            Vector2d edge = p2 - p1;
            Vector2d normal(-edge.y, edge.x);
            normals.push_back(normal.getNormalized());
        }

        return normals;
    }

Vector2d SATCollider::projectShape(Vector2d axis) {
    if (points.empty()) {
        return Vector2d(0,0);
    }

    float min = points[0].Dot(axis);
    float max = min;

    for (size_t i = 1; i < points.size(); ++i) {
        float projection = points[i].Dot(axis);
        if (projection < min) {
            min = projection;
        }
        if (projection > max) {
            max = projection;
        }
    }

    return Vector2d(min, max);
}

};
