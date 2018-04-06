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

    //protected:

    //private:

        int m_num;
        int m_quantite;
        bool m_marque;
        int m_coeff;
        int m_nbBesoin;
        int m_nbBesoinVital;
        int m_nbBesoinNonVital;

        /// Rajouter le nombre de sommet non vitaux et vitaux

        int pos_x;
        int pos_y;
        std::vector<Besoin> m_besoin;

};

#endif // SOMMET_H
