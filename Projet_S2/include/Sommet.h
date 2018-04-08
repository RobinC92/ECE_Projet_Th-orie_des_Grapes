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
        int pos_x;
        int pos_y;
        int m_nbBesoin;
        std::vector<Besoin> m_besoin;
        std::vector<int> m_adj;

        std::string m_images;
        int m_nbBesoinVital;
        int m_nbBesoinNonVital;


};

#endif // SOMMET_H
