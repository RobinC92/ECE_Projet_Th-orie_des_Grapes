#include "Fichier.h"

void alloueMat(int nbSom, Graphe &G)
{
    std::vector<int> temp;

    for(int i=0; i<nbSom; i++)
    {
        temp.push_back(0);
    }

    for( int i=0; i<nbSom; i++)
    {
        G.m_matAdj.push_back(temp);
    }
}


void charger(Graphe &G, std::string doc)
{
    Sommet s;
    Besoin b;
    int valSom(0), influ(0);
    std::vector<int> temp;

    std::ifstream fichier (doc.c_str());

    if(fichier)
    {
        fichier >> G.m_nbSom;

        alloueMat(G.m_nbSom, G);




//        for(int i=0; i<G.m_nbSom; i++)
//        {
//            for(int j=0; j<G.m_nbSom; j++)
//            {
//                std::cout << G.m_matAdj[i][j] << " ";
//            }
//            std::cout << std::endl;
//        }
//        std::cout << std::endl;


        for(int i=0; i<G.m_nbSom; i++)
        {
            for(int j=0; j<G.m_nbSom; j++)
            {
                fichier >> influ;
                G.m_matAdj[i][j] = influ;
            }
        }

//        for(int i=0; i<G.m_nbSom; i++)
//        {
//            for(int j=0; j<G.m_nbSom; j++)
//            {
//                std::cout << G.m_matAdj[i][j] << " ";
//            }
//            std::cout << std::endl;
//        }
//
//            std::cout << std::endl;



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

//    for(int i=0; i<G.m_nbSom; i++)
//    {
//        for(int j=0; j<G.m_sommet[i].m_nbBesoin; j++)
//        {
//
//            std::cout << G.m_sommet[i].m_nbBesoin << " " << G.m_sommet[i].m_num << " " << G.m_sommet[i].m_besoin[j].m_numSommet << std::endl;
//        }
//    }
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
                //std::cout << G.m_sommet[i].m_images << std::endl;
            }
        }
        fichier.close();
    }
    else
        std::cout << "Erreur a l'ouverture du fichier" << std::endl;
}


void sauver(Graphe &G)
{
    int m_nbSom(G.m_nbSom);
    //std::cout << G.m_nbSom;
    std::ofstream fichier("donnes_bis.txt", std::ios::trunc);

    if(fichier)
    {
        fichier << m_nbSom;
        fichier << std::endl;

        for(int i=0; i<m_nbSom; i++)
        {
            for(int j=0; j<m_nbSom; j++)
            {
                fichier << G.m_matAdj[i][j] << " ";
                std::cout << G.m_matAdj[i][j] << " ";
            }
            fichier << std::endl;
        }

        for(int i=0; i<m_nbSom; i++)
        {
            fichier << G.m_sommet[i].m_num << " ";

            fichier << G.m_sommet[i].m_quantite << " ";

            fichier << G.m_sommet[i].m_marque << " ";

            fichier << G.m_sommet[i].m_coeff << " ";

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
        std::cout << "Erreur � l'ouverture du fichier" << std::endl;
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
        std::cout << "Erreur � l'ouverture du fichier" << std::endl;
}

//void init_BesoinsVitaux(Graphe &G)
//{
//    for(int i=0; i<G.m_nbSom; i++)
//    {
//        for(int j=0; j<G.m_nbSom; j++)
//        {
//            if(G.m_sommet[i].m_besoin[j].m_vitale == 1)
//                G.m_sommet[i].m_besoin[j];
//
//            else
//                G.m_sommet[i].m_besoin[j].m_nbBesoinNonVital++;
//        }
//    }
//}

void init_BesoinsVitaux(Graphe &G)
{
    for(int i=0; i<G.m_nbSom; i++)
    {
        for(int j=0; j<G.m_sommet[i].m_nbBesoin; j++)
        {
            if(G.m_sommet[i].m_besoin[j].m_vitale == 1)
                G.m_sommet[i].m_nbBesoinVital++;

            else
                G.m_sommet[i].m_nbBesoinNonVital++;
        }
    }
}


