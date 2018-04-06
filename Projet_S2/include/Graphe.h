#ifndef GRAPHE_H
#define GRAPHE_H
#include "Sommet.h"

class Graphe
{
public:

    Graphe();
    int Actualiser_Graphe(Graphe &first);
    void Reproduction(Sommet&m_sommet);
    void Calcul_insatisfait(std::vector<float> &a, float &b);

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
