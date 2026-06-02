#include <cmath>
#include "Cellule.h"

double Cellule::getPressure(double gamma) const {
    double p = p = (gamma -1 )*(U.rho_e - (U.rho_u * U.rho_u)/(2*U.rho)) ;
    return p ;
}

double Cellule::getTemperature (double gamma, double r) const {
    double p = Cellule::getPressure(gamma) ;
    double T = p / (U.rho*r);
    return T ;
}

double Cellule::getSoundSpeed(double gamma) const {
    double p = getPressure(gamma);
    double a = std::sqrt((gamma * p) / U.rho);
    return a ;
}

double Cellule::getFluidVelocity() const {
    return U.rho_u / U.rho;
}

double Cellule::getMach(double gamma) const {
    double m = Cellule::getFluidVelocity() / Cellule::getSoundSpeed(gamma)  ;
    return m ;
}

StateVector Cellule::getFlux(double gamma) const {
    double p = getPressure(gamma);
    double u = getFluidVelocity();

    StateVector F ;

    // Calcul du vecteur Flux
    F.rho   = U.rho_u  ;            // flux massique
    F.rho_u = U.rho_u * u + p ;     // flux de quantité de mouvement
    F.rho_e = (U.rho_e + p)*u  ;    // flux d'energie

    return F ;                      // retourner le vecteur Flux F
}

StateVector Cellule::getSource(double gamma) const {
    double p = getPressure(gamma);
    StateVector S ;

    S.rho   = 0  ;              // pas de source sur la conservation de la masse
    S.rho_u = p /A * dAdx ;     //source géometrique de la scd loi de NEWTON
    S.rho_e = 0;                // pas de source sur la conservation d'energie

    return S ;                  // retourne le vecteur source S
}
