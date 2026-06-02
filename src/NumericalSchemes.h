#include "Cellule.h"
#include "StateVector.h"


namespace NumericalSchemes {

    // Schema numéro 1 : RUSANOV
    StateVector getRusanov (Cellule Gauche, Cellule Droite, double gamma) ;

    // Schema numéro 2 : HLLC (ordre 1)
    StateVector getHLLC (Cellule Gauche, Cellule Droite, double gamma) ;

    // Schema numéro 3 : MUSCL + HLLC (ordre 2)
    StateVector getHLLC_MUSCL (Cellule Gauche, Cellule Droite, double gamma) ;

    // Schema numéro 4 : MUSCL + HLLC + Runge-Kutta d'ordre 3 (SSP-RK3)
    StateVector getHLLC_MUSCK_RK (Cellule Gauche, Cellule Droite, double gamma) ;


}