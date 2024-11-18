#pragma once
#include "Vector2d.h"
#include "Collider.h"
#include "AABBCollider.h"
#include "SATCollider.h"
#include <SFML/Graphics.hpp>
#include <stdexcept>

class Particle {
public:
    Vector2d postion;
    Vector2d velocity;
    Vector2d acceleration;
    Vector2d forces;

    float mass;
    float drag;


    
    sf::CircleShape* circleParticle = nullptr;
    sf::RectangleShape* rectangleParticle = nullptr;
    sf::ConvexShape* convexParticle = nullptr;

    Collider circleCollider;
    AABBCollider rectangleCollider;
    SATCollider convexCollider;

    Particle(Vector2d postion, sf::Shape* shape, float mass = 1, float drag = 0.3f) {
        if (mass <= 0) {
            throw std::invalid_argument("Mass must be greater than zero.");
        }

        // Initialize default values
        this->postion = postion;
        this->velocity = Vector2d(0, 0);
        this->acceleration = Vector2d(0, 0);
        this->forces = Vector2d(0, 0);
        this->mass = mass;
        this->drag = drag;


        if (auto circle = dynamic_cast<sf::CircleShape*>(shape)) {

            this->circleParticle = circle;
            this->circleCollider.center = postion;
            this->circleCollider.r = circle->getRadius();
        }
        else if (auto rect = dynamic_cast<sf::RectangleShape*>(shape)) {
            this->rectangleParticle = rect;
            this->rectangleCollider.ul = Vector2d(rect->getPosition().x - 15.f, rect->getPosition().y - 15.f);
            this->rectangleCollider.lr = Vector2d(rect->getPosition().x + 15.f, rect->getPosition().y + 15.f);
            this->rectangleCollider.position = postion;
        }
        else if (auto convex = dynamic_cast<sf::ConvexShape*>(shape)) {

            this->convexParticle = convex;
            for (size_t i = 0; i < convex->getPointCount(); ++i) {
                this->convexCollider.points.push_back(Vector2d(convex->getPoint(i).x, convex->getPoint(i).y));
            }
            this->rectangleCollider.position = this->postion;
        }
    }


    void Particle::Update(float dt) {

        acceleration = Vector2d(forces.x / mass, forces.y / mass);


        velocity += acceleration * dt;


        velocity *= (1.0f - drag * dt);


        postion += velocity * dt;

        if (circleParticle) {

            circleParticle->setPosition(postion.x, postion.y);


            circleCollider.center = postion;
        }
        else if (rectangleParticle) {
            rectangleParticle->setPosition(postion.x, postion.y);
            rectangleCollider.updatePosition(postion);
        }
        else if (convexParticle) {

            this->convexParticle->setPosition(postion.x, postion.y);


            this->convexCollider.updatePosition(this->postion);
        }


        forces = Vector2d(0, 0);
    }

    void addForce(Vector2d force) {
        this->forces += force;
    }
};
