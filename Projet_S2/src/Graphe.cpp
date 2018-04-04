#include "Graphe.h"

#include <vector>
using namespace std;

Graphe::Graphe()
{
    //ctor
}

void Graphe::Actualiser_Graphe(Graphe & first)
{
    int reproduction;
    int suicide;
    vector<int> non_nourrit;

    for(int i=0; i<m_sommet.size(); i++) /// On parcourt tout les besoins, et on enlève les quantités correspondantes
    {
        reproduction=0;
        if(m_sommet[i].m_marque)
        {
            /// Le sommet est marqué, on le saute
        }
        else if(!m_sommet[i].m_marque)
        {
            for(int j=0; j<m_sommet[i].m_besoin.size(); j++)
            {
                int besoin = m_sommet[i].m_besoin[j].m_quantiteBesoin; /// Besoin du S Lapin en carottes
                int besoin_S = m_sommet[i].m_besoin[j].m_numSommet; /// Le num du S carottes
                int nvleVal = m_sommet[besoin_S].m_quantite; /// Quantité du S carottes

                if(m_sommet[besoin_S].m_marque)
                {
                    /// Le sommet est marqué, on le saute
                }
                else if(!m_sommet[besoin_S].m_marque)
                {
                    m_sommet[besoin_S].m_quantite -= besoin*m_sommet[i].m_quantite; /// On soustrait les besoin* nb lapin
                    nvleVal = m_sommet[besoin_S].m_quantite;
                    nvleVal /= besoin; /// Nombre de lapins qui peuvent encore se nourrir

                    if(nvleVal < 0)
                    {
                        nvleVal = nvleVal*(-1); /// population non-nourrit
                        non_nourrit.push_back(nvleVal);

                        m_sommet[besoin_S].Set_marquage(true); /// On enlève le S besoin

                        if(m_sommet[i].m_besoin[j].m_vitale) /// Si le besoin est vital, on enlève aussi le S de départ
                        {
                            int nb_lapin_rest;
                            nb_lapin_rest = m_sommet[i].m_quantite - nvleVal; /// On regarde le nombre de lapin restant

                            if(nb_lapin_rest >= 0)
                                m_sommet[i].m_quantite -= nvleVal;

                            if(nb_lapin_rest < 0)
                                m_sommet[i].Set_marquage(true);
                        }
                    }
                    else
                        ++reproduction;
                }

            }

            /// Si tous les besoins satisfais ou moins de besoins insatisfais que de besoins, alors il y a reproduction

            /// Rajouter des conditions (au bouts de deux besoins en moins, meurt etc)

            /// Si plus de X% de besoins insatisfait, on tue le nombre de lapin insatisfaits

            if((reproduction >= m_sommet[i].m_besoin.size()) || (non_nourrit.size() < m_sommet[i].m_besoin.size()) )
            {
                int couple;
                couple = (m_sommet[i].m_quantite )/2; /// On détermine le nombre de couple
                m_sommet[i].m_quantite = m_sommet[i].m_quantite + couple* m_sommet[i].m_coeff;
            }
            else if(reproduction < m_sommet[i].m_besoin.size())
            {
                if(non_nourrit.size()==m_sommet[i].m_besoin.size()) /// Si il y a eu des manques dans tous les besoins
                {
                    int moy_mort(0);
                    int couple;

                    for(int y=0; y < non_nourrit.size(); y++) /// On va faire la moyenne du nombre d'individus n'ayant rien mangé
                    {
                        int nb_lapin_mort;

                        moy_mort = non_nourrit[i] + moy_mort;
                    }

                    moy_mort /= non_nourrit.size(); /// on fait la moyenne

                    m_sommet[i].m_quantite -= moy_mort; /// On actualise la quantité restante


                    couple = (m_sommet[i].m_quantite )/2; /// On détermine le nombre de couple
                    m_sommet[i].m_quantite = m_sommet[i].m_quantite + couple* m_sommet[i].m_coeff;
                }
            }
        }
    }
}

void Graphe::Actualiser_S(bool a, int besoin_S)
{

}

void Graphe::Remplir_sommet(vector<Sommet> s1)
{
    for(int i=0; i < s1.size(); i++)
    {
        /// Remplir les sommets pour tester
    }
}

Graphe::~Graphe()
{
    //dtor
}
