#include "NumericalSchemes.h"
#include <algorithm>  // std::max
#include <cmath>      // std::abs

namespace NumericalSchemes {

    StateVector  NumericalSchemes::getRusanov(Cellule Gauche, Cellule Droite, double gamma) {
        StateVector F_interface ;

        //Récupération des vitesses du son (gauche et droite) "Ci"
        double  c_g = Gauche.getSoundSpeed(gamma);
        double  c_d = Droite.getSoundSpeed(gamma);

        //Récupération des vitesses  (gauche et droite) "Ui"
        double u_g = Gauche.getFluidVelocity();
        double u_d = Droite.getFluidVelocity();

        // Récupération des flux des cellules (gauche et droite) "Fi"
        StateVector F_g = Gauche.getFlux(gamma);
        StateVector F_d = Droite.getFlux(gamma);

        // Calcul de Smax
        double S_max = std::max(std::abs(u_g) + c_g , std::abs(u_d) + c_d);


        // Calcul du flux à l'interface
        F_interface.rho = 0.5 * (F_d.rho + F_g.rho) - 0.5 * S_max * (Droite.U.rho - Gauche.U.rho);
        F_interface.rho_u = 0.5 * (F_d.rho_u + F_g.rho_u) - 0.5 * S_max * (Droite.U.rho_u - Gauche.U.rho_u);
        F_interface.rho_e = 0.5 * (F_d.rho_e + F_g.rho_e) - 0.5 * S_max * (Droite.U.rho_e - Gauche.U.rho_e);

        return F_interface;
    }
}
