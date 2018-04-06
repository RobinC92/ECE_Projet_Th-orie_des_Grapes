#ifndef ARETE_H
#define ARETE_H
#include <iostream>
#include "Sommet.h"


class Arete
{
    public:
        Arete(Sommet s1, Sommet s2);
        virtual ~Arete();

        int m_numArete;
        Sommet m_s1;
        Sommet m_s2;


    protected:

    private:
};

#endif // ARETE_H
