#pragma once

class Rocket {
    public:
        Rocket(double mass, double fuelMass, double thrust);

        void update(double dt);
        double getAltitude() const;
        double getVelocity() const;
    
        private:
            double mass;
            double fuelMass;
            double thrust;
            double velocity;
            double altitude;
};
