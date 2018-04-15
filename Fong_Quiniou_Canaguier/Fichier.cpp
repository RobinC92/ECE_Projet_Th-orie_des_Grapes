#include "Fichier.h"

void charger(Graphe &G,std :: string doc)
{
    Sommet s;
    Besoin b;
    int valSom(0), influ(0);
    std::vector<int> temp;

    std::ifstream fichier (doc.c_str());

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
            s.m_quantiteMax = valSom;

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
                b.m_quantiteBesoin = valSom/100.0;

                fichier >> valSom;
                b.m_vitale = valSom;

                fichier >> valSom;
                b.m_coeffBesoin = valSom;

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

void chargerImages(Graphe &G, std::string doc)
{
    std::string nom;
    std::ifstream fichier(doc.c_str());

    if(fichier)
    {
        while(getline(fichier, nom))
        {
            for(unsigned int i=0; i<G.m_sommet.size(); i++)
            {
                getline(fichier, nom);
                G.m_sommet[i].m_images = nom;
                std::cout << G.m_sommet[i].m_images << std::endl;
            }
        }
        fichier.close();
    }
    else
        std::cout << "Erreur a l'ouverture du fichier" << std::endl;
}

void sauver(Graphe &G,std :: string doc)
{
    int m_nbSom(G.m_nbSom);
    //std::cout << G.m_nbSom;
    std::ofstream fichier(doc.c_str(), std::ios::trunc);

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

            fichier << G.m_sommet[i].m_quantiteMax << " ";

            fichier << G.m_sommet[i].pos_x << " ";

            fichier << G.m_sommet[i].pos_y << " ";

            fichier << G.m_sommet[i].m_nbBesoin << " ";

            for(int j=0; j<G.m_sommet[i].m_nbBesoin; j++)
            {
                fichier << G.m_sommet[i].m_besoin[j].m_numSommet << " ";

                fichier << G.m_sommet[i].m_besoin[j].m_quantiteBesoin*100 << " ";

                fichier << G.m_sommet[i].m_besoin[j].m_vitale << " ";

                fichier << G.m_sommet[i].m_besoin[j].m_coeffBesoin << " ";
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

void init_matAdj(Graphe &G)
{
    int n(0), p(0);
    std::vector<int> temp;

    for(int i=0; i<G.m_nbSom; i++)
    {
        if(G.m_sommet[i].m_marque==0)
            p++;
    }

    for(int i=0; i<p; i++)
    {
        temp.push_back(0);
    }

    for( int i=0; i<p; i++)
    {
        G.m_matAdj.push_back(temp);
    }


    for(int i=0; i<G.m_nbSom; i++)
    {
        for(int j=0; j<G.m_sommet[i].m_nbBesoin; j++)
        {
            if(G.m_sommet[i].m_marque==0&&G.m_sommet[G.m_sommet[i].m_besoin[j].m_numSommet].m_marque==0)
            {
                n = G.m_sommet[i].m_besoin[j].m_numSommet;
                G.m_matAdj[G.m_sommet[i].m_num][n] = 1;
            }
        }
    }
    for(int i=0; i<G.m_matAdj.size(); i++)
    {
        std::cout << i;
        for(int j=0; j<G.m_matAdj.size(); j++)
        {
            std::cout << G.m_matAdj[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void matAdj(Graphe &G)
{
    for(int i=0; i<G.m_nbSom; i++)
    {
        for(int j=0; j<G.m_nbSom; j++)
        {
            if(G.m_matAdj[i][j]!=0)
            {
                G.m_sommet[i].m_adj.push_back(j);
                std::cout << "le sommet :" << i << "est adj au sommet :" << j << std::endl;
            }
        }
    }

    for(int i=0; i<G.m_nbSom; i++)
    {
        for(int j=0; j<G.m_nbSom; j++)
        {
            if(G.m_matAdj[j][i]!=0)
            {
                if(G.m_matAdj[i][j]==0)
                {
                    G.m_sommet[i].m_adj.push_back(G.m_sommet[j].m_num);
                }
            }
        }
    }
for (int i =0; i < G.m_nbSom; i++ )
    {
        for (int j =0; j < G.m_sommet[i].m_adj.size(); j++ )
        {
            std::cout << "adj du S " << G.m_sommet[i].m_num << ": " << G.m_sommet[i].m_adj[j] << std::endl;
        }
    }
}


