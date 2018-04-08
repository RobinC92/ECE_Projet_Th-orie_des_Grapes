#ifndef BESOIN_H
#define BESOIN_H

#include <vector>
#include <iostream>

class Besoin
{

    friend class Graphe;

    public:
        Besoin();

        virtual ~Besoin();


    //protected:

    //private:
        int m_numSommet;
        float m_quantiteBesoin;
        int m_coeffBesoin;
        bool m_vitale;
};

#endif // BESOIN_H
