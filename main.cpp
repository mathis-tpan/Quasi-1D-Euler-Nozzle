#include "src/Domaine.h"

int main() {
    // 1. Paramètres de la simulation
    int N = 250;
    double L = 3.0;
    double gamma = 1.4;
    double r = 287.0;
    double t_max = 0.03;

    // définir le domaine 1D de notre cas
    Domaine maTuyere(L, N, gamma, r, t_max);

    // on lance la simulation
    maTuyere.run(r);

    return 0;
}