#include "PhysicsWorld.h"


void PhysicsWorld::addParticle(Particle* particle) {
	this->particles.push_back(particle);
}

void PhysicsWorld::Update(float deltaTime) {
    for (Particle* particle : this->particles) {
        particle->Update(deltaTime);


        for (Particle* otherParticle : this->particles) {
            if (particle == otherParticle) {
                continue;
            }



            if (particle->circleParticle && otherParticle->circleParticle) {
                if (particle->circleCollider.checkCollision(otherParticle->circleCollider)) {
                    particle->velocity = Vector2d(-(particle->velocity.x), -(particle->velocity.y));
                    otherParticle->velocity = Vector2d(-(otherParticle->velocity.x), -(otherParticle->velocity.y));
                }
            }
            else if (particle->rectangleParticle && otherParticle->rectangleParticle) {
                if (particle->rectangleCollider.checkCollision(otherParticle->rectangleCollider)) {
                    particle->velocity = Vector2d(-(particle->velocity.x), -(particle->velocity.y));
                    otherParticle->velocity = Vector2d(-(otherParticle->velocity.x), -(otherParticle->velocity.y));
                }
            }
            else if (particle->convexParticle && otherParticle->convexParticle) {
                if (particle->convexCollider.checkCollision(otherParticle->convexCollider)) {
                    particle->velocity = Vector2d(-(particle->velocity.x), -(particle->velocity.y));
                    otherParticle->velocity = Vector2d(-(otherParticle->velocity.x), -(otherParticle->velocity.y));
                }
            }     

        }
    }
}
