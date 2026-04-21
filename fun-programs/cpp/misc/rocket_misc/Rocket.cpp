#include "Rocket.h"

const double g = 9.81;

Rocket::Rocket(double m, double f, double t) : mass(m), fuelMass(f), thrust(t), velocity(0), altitude(0) {}

void Rocket::update(double dt) {
    double totalMass = mass + fuelMass;
    double accelaration = (thrust / totalMass) - g;

    velocity += accelaration*dt;
    altitude += velocity*dt;

    if (fuelMass > 0) {
        fuelMass -= dt*0.5;
        if (fuelMass < 0) {
            fuelMass = 0;
        }
    }
}

double Rocket::getAltitude() const { return altitude; }
double Rocket::getVelocity() const { return velocity; }