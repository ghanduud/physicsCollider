#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../build/Particle.h"
#include "../build/Renderer.h"
#include "../build/PhysicsWorld.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Circle Collision", sf::Style::Default);
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    sf::Clock clock;
    sf::Time timePerFrame = sf::seconds(1.f / 60.f);

    Renderer r;
    PhysicsWorld pw;


    sf::CircleShape c1(30.f);
    c1.setFillColor(sf::Color::Red);
    c1.setOrigin(30.f, 30.f);
    r.AddDrawable(&c1);


    Particle p1(Vector2d(0, 300), &c1);
    p1.addForce(Vector2d(800, 0));
    pw.addParticle(&p1);


    sf::CircleShape c2(30.f);
    c2.setFillColor(sf::Color::Green);
    c2.setOrigin(30.f, 30.f);  
    r.AddDrawable(&c2);


    Particle p2(Vector2d(700, 300), &c2);
    p2.addForce(Vector2d(-800, 0));  
    pw.addParticle(&p2);



    sf::RectangleShape rect1(Vector2f(30,30));
    rect1.setOrigin(Vector2f(15, 15));
    r.AddDrawable(&rect1);

    Particle p3(Vector2d(0, 100), &rect1);
    p3.addForce(Vector2d(800, 0)); 
    pw.addParticle(&p3);


    sf::RectangleShape rect2(Vector2f(30, 30));
    rect2.setOrigin(Vector2f(15, 15));
    r.AddDrawable(&rect2);

    Particle p4(Vector2d(700, 100), &rect2);
    p4.addForce(Vector2d(-800, 0));  
    pw.addParticle(&p4);


    sf::ConvexShape convex1;
    convex1.setPointCount(5); 
    convex1.setPoint(0, sf::Vector2f(0.f, 0.f));
    convex1.setPoint(1, sf::Vector2f(50.f, 10.f));
    convex1.setPoint(2, sf::Vector2f(40.f, 50.f));
    convex1.setPoint(3, sf::Vector2f(10.f, 70.f));
    convex1.setPoint(4, sf::Vector2f(-20.f, 30.f));
    convex1.setFillColor(sf::Color::Blue);
    convex1.setOrigin(25.f, 35.f); 
    r.AddDrawable(&convex1);

    Particle p5(Vector2d(0, 500), &convex1);
    p5.addForce(Vector2d(800, 0));
    pw.addParticle(&p5);


    sf::ConvexShape convex2;
    convex2.setPointCount(4); 
    convex2.setPoint(0, sf::Vector2f(0.f, 0.f));
    convex2.setPoint(1, sf::Vector2f(50.f, 20.f));
    convex2.setPoint(2, sf::Vector2f(30.f, 70.f));
    convex2.setPoint(3, sf::Vector2f(-20.f, 50.f));
    convex2.setFillColor(sf::Color::Yellow);
    convex2.setOrigin(15.f, 35.f);
    r.AddDrawable(&convex2);

    Particle p6(Vector2d(700, 500), &convex2);
    p6.addForce(Vector2d(-800, 0));
    pw.addParticle(&p6);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }


        pw.Update(0.2);

 
        r.Render(window);
    }

    return 0;
}
