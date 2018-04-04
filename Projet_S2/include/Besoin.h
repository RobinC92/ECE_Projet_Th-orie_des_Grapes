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


    protected:

    private:
        int m_numSommet;
        int m_quantiteBesoin;
        bool m_vitale;
};

#endif // BESOIN_H
