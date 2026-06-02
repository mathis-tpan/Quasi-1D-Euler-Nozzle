#pragma once
#include "Cellule.h"
#include <vector>
#include "NumericalSchemes.h"

class Domaine {
    public:
    Domaine(int L, int N, double gamma, double r, double t_max) ;

    void run(double r);

    private:
    // Sous le capot : le chef d'orchestre possède le maillage et les outils
    std::vector<Cellule> tuyere; // c'est un vecteur dynamique pour gerer la taille a souhait du maillage
    double gamma;
    double t_max;

    double getDeltat (const Cellule& cell, double gamma, double CFL) const ;

    double getGlobalDeltat(std::vector<Cellule> tube, double CFL, double gamma) const  ;

    // Petite fonction magique pour prendre une "photo" du tube à un instant donné
    void exporterInstantane(int numero_photo);

    void appliquerConditionsLimites(double r);
};