#ifndef SOMMET_H
#define SOMMET_H
#include "Besoin.h"
#include <vector>
#include <string>

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
        std::string m_images;
        int m_nbBesoin;
        int m_nbBesoinVital;
        int m_nbBesoinNonVital;


        int pos_x;
        int pos_y;
        std::vector<Besoin> m_besoin;

};

#endif // SOMMET_H
