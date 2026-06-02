#pragma once
#include "StateVector.h"

struct Cellule {
    StateVector U ;
    double x;
    double dx;
    double dAdx;
    double A;

    double getPressure (double gamma) const;
    double getTemperature (double gamma, double r) const;

    double getSoundSpeed (double gamma) const;
    double getFluidVelocity () const;
    double getMach (double gamma) const;

    StateVector getFlux (double gamma) const;
    StateVector getSource(double gamma) const;
};
