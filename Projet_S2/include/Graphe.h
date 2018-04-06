#ifndef GRAPHE_H
#define GRAPHE_H
#include "Sommet.h"

class Graphe
{
public:

    Graphe();
    void Actualiser_Graphe(Graphe &first);
    void Actualiser_S(bool, int );
    void Remplir_sommet(std::vector<Sommet> s1);
    void Reproduction(float & moy_mort, Sommet&m_sommet);

       std::vector<std::vector <int>> get_matAdj();

    virtual ~Graphe();

    int m_nbSom;
    std::vector<Sommet> m_sommet;
    std::vector<std::vector <int>> m_matAdj;



protected:

private:

    //std::vector<Sommet> m_sommet;
};

#endif // GRAPHE_H
