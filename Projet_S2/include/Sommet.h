#ifndef SOMMET_H
#define SOMMET_H
#include "Besoin.h"
#include <vector>

class Sommet
{

    friend class Graphe;

    public:

        Sommet();

        void Remplissage();
        void Set_marquage(bool);

        virtual ~Sommet();

    protected:

    private:

        int m_num;
        int m_quantite;
        bool m_marque;
        int m_coeff;

        int pos_x;
        int pos_y;
        std::vector<Besoin> m_besoin;

};

#endif // SOMMET_H
