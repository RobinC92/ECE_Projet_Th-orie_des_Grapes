#include "Fichier.h"

//void alloueMat(int nbSom, Graphe G)
//{
//    std::vector<int> temp;
//
//    for(int i=0; i<nbSom; i++)
//    {
//        temp.push_back(0);
//    }
//
//    for( int i=0; i<nbSom; i++)
//    {
//        G.m_matAdj.push_back(temp);
//    }
//}


void charger(Graphe &G)
{
    Sommet s;
    Besoin b;
    int valSom(0), influ(0);
    std::vector<int> temp;

    std::ifstream fichier ("donnees.txt");

    if(fichier)
    {
        fichier >> G.m_nbSom;

        for(int i=0; i<G.m_nbSom; i++)
        {
            fichier >> valSom;
            s.m_num = valSom;

            fichier >> valSom;
            s.m_quantite = valSom;

            fichier >> valSom;
            s.m_marque = valSom;

            fichier >> valSom;
            s.m_coeff = valSom;

            fichier >> valSom;
            s.pos_x = valSom;

            fichier >> valSom;
            s.pos_y = valSom;

            fichier >> valSom;
            s.m_nbBesoin = valSom;


            for(int j=0; j<s.m_nbBesoin; j++)
            {
                fichier >> valSom;
                b.m_numSommet = valSom;

                fichier >> valSom;
                b.m_quantiteBesoin = valSom/10.0;

                fichier >> valSom;
                b.m_vitale = valSom;

                s.m_besoin.push_back(b);

            }
            G.m_sommet.push_back(s);
            s.m_besoin.clear();

        }
        fichier.close();
    }
    else
        std::cout << "Erreur a l'ouverture du fichier" << std::endl;
}

void chargerImages(Graphe &G)
{
    std::string nom;
    std::ifstream fichier("images.txt");

    if(fichier)
    {
        while(getline(fichier, nom))
        {
            for(unsigned int i=0; i<G.m_sommet.size(); i++)
            {
                getline(fichier, nom);
                G.m_sommet[i].m_images = nom;
            }
        }
        fichier.close();
    }
    else
        std::cout << "Erreur a l'ouverture du fichier" << std::endl;
}

void init_matAdj(Graphe &G)
{
    int n(0);
    std::vector<int> temp;

    for(int i=0; i<G.m_nbSom; i++)
    {
        temp.push_back(0);
    }

    for( int i=0; i<G.m_nbSom; i++)
    {
        G.m_matAdj.push_back(temp);
    }


    for(int i=0; i<G.m_nbSom; i++)
    {
        for(int j=0; j<G.m_sommet[i].m_nbBesoin; j++)
        {
            n = G.m_sommet[i].m_besoin[j].m_numSommet;
            G.m_matAdj[i][n] = 1;
        }
    }
}

void sauver(Graphe &G)
{
    int m_nbSom(G.m_nbSom);
    std::ofstream fichier("donnes_bis.txt", std::ios::trunc);

    if(fichier)
    {
        fichier << m_nbSom;
        fichier << std::endl;

        for(int i=0; i<m_nbSom; i++)
        {
            fichier << G.m_sommet[i].m_num << " ";

            fichier << G.m_sommet[i].m_quantite << " ";

            fichier << G.m_sommet[i].m_marque << " ";

            fichier << G.m_sommet[i].m_coeff << " ";

            fichier << G.m_sommet[i].pos_x << " ";

            fichier << G.m_sommet[i].pos_y << " ";

            fichier << G.m_sommet[i].m_nbBesoin << " ";

            for(int j=0; j<G.m_sommet[i].m_nbBesoin; j++)
            {
                fichier << G.m_sommet[i].m_besoin[j].m_numSommet << " ";

                fichier << G.m_sommet[i].m_besoin[j].m_quantiteBesoin*10 << " ";

                fichier << G.m_sommet[i].m_besoin[j].m_vitale << " ";
            }
            fichier << std::endl;

        }
        fichier << std::endl;

        fichier.close();
    }
    else
        std::cout << "Erreur à l'ouverture du fichier" << std::endl;
}

void sauverImages(Graphe &G)
{
    std::ofstream fichier("images_bis.txt", std::ios::trunc);

    if(fichier)
    {
        for(int i=0; i<G.m_sommet.size(); i++)
        {
            fichier << std::endl;
            fichier << G.m_sommet[i].m_images;
        }
        fichier.close();
    }
    else
        std::cout << "Erreur à l'ouverture du fichier" << std::endl;
}


//void matAdj(Graphe &G)
//{
//    for(int i=0; i<G.m_nbSom; i++)
//    {
//        for(int j=0; j<G.m_nbSom; j++)
//        {
//            if(G.m_matAdj[i][j]!=0)
//                std::cout << "EGALLL " << std::endl;
//            if(G.m_matAdj[i][j] != 0)
//            {
//                G.m_sommet[i].m_adj.push_back(G.m_sommet[j].m_num);
//                G.m_sommet[j].m_adj.push_back(G.m_sommet[i].m_num);
//                std::cout << G.m_sommet[i].m_num << " " << G.m_sommet[j].m_num << std::endl;
//
//            }
//        }
//    }
//}
