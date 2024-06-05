#include <SFML/Graphics.hpp>

// Disable MSVC analysis warnings for the box2d include
#pragma warning(push)
#pragma warning(disable: 26495 26813)
#include "box2d/box2d.h"
#pragma warning(pop)

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode(1000, 1000), "Box2D");

    // Define the gravity vector
    b2Vec2 gravity(0.0f, -10.0f);

    // Construct a world object, which will hold and simulate the rigid bodies.
    // Use dynamic allocation as this is a big object, and allocating it on the
    // stack causes compiler warning on function stack usage
    auto world = std::make_unique<b2World>(gravity);

    // Define the ground body
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);

    // Call the body factory which allocates memory for the ground body
    // from a pool and creates the ground box shape (also from a pool).
    // The body is also added to the world
    b2Body* groundBody = world->CreateBody(&groundBodyDef);

    // Define the ground box shape
    b2PolygonShape groundBox;

    // The extents are the half-widths of the box
    groundBox.SetAsBox(50.0f, 10.0f);

    // Add the ground fixture to the ground body
    groundBody->CreateFixture(&groundBox, 0.0f);

    // Define the dynamic body. We set its position and call the body factory
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 4.0f);
    b2Body* body = world->CreateBody(&bodyDef);

    // Define another box shape for our dynamic body
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);

    // Define the dynamic body fixture
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;

    // Set the box density to be non-zero, so it will be dynamic
    fixtureDef.density = 1.0f;

    // Override the default friction
    fixtureDef.friction = 0.3f;

    // Add the shape to the body
    body->CreateFixture(&fixtureDef);

    // Prepare for simulation. Typically we use a time step of 1/60 of a
    // second (60Hz) and 10 iterations. This provides a high quality simulation
    // in most game scenarios
    float timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    b2Vec2 position = body->GetPosition();
    float angle = body->GetAngle();

    // Create SFML object for the graphical representation of the box.
    // Note: In real code, the various box2d entities above and the SFML object
    // for graphical representation should be both encapsulated in a class that
    // represents the whole object.
    // Note that we use 1:40 scale here, as box2d should be handled in single
    // pixel resolution
    auto rect = sf::RectangleShape({ 40.f, 40.f });
    rect.setFillColor(sf::Color::Green);

    auto worldStepCounter = 60;

    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        window.clear();

        if (worldStepCounter--)
        {
            // First, cause the world to be updated to the next step
            world->Step(timeStep, velocityIterations, positionIterations);

            // Then, get the new position and angle from box2d object ...
            position = body->GetPosition();
            // (box2d numbers are not in pixels, so we need some scaling here)
            position *= 100.f;
            angle = body->GetAngle();

            // ... and update the SFML object with this info
            // Note: again, in real code, this data flow should be part of a
            // proper member function of the class representation the whole
            // object, not handled by main/controller or any similar class
            rect.setPosition(position.x, position.y);
            rect.setRotation(angle);
        }
        window.draw(rect);
        window.display();

        for (auto event = sf::Event {}; window.pollEvent(event); )
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }
    }
}
