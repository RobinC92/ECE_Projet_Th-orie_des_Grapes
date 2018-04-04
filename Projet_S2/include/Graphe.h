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

    virtual ~Graphe();


protected:

private:

    std::vector<Sommet> m_sommet;
};

#endif // GRAPHE_H
