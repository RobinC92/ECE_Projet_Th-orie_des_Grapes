#include "Graphe.h"

#include <vector>
using namespace std;

Graphe::Graphe()
{
    //ctor
}

//void Graphe::Reproduction(Sommet & sommet1, int couple)
//{
//
//}

void Graphe::Actualiser_Graphe(Graphe & first)
{
    for(int i=0; i<m_sommet.size(); i++) /// On parcourt tout les besoins, et on enlève les quantités correspondantes
    {
        int reproduction(0);
        vector <int> nb_besoin_vitaux_insatisfaits;
        vector<int> nb_besoin_nonvitaux_insatisfaits;
        int nvleVal;

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
                nvleVal = m_sommet[besoin_S].m_quantite; /// Quantité du S carottes

                if(m_sommet[besoin_S].m_marque)
                {
                    if(m_sommet[i].m_besoin[j].m_vitale) /// Si le sommet marque est vital
                    {
                        nb_besoin_vitaux_insatisfaits.push_back(besoin*m_sommet[i].m_quantite);
                    }
                    if(!m_sommet[i].m_besoin[j].m_vitale)
                    {
                        nb_besoin_nonvitaux_insatisfaits.push_back(besoin*m_sommet[i].m_quantite);
                    }
                }
                else if(!m_sommet[besoin_S].m_marque)
                {
                    nvleVal = m_sommet[besoin_S].m_quantite - besoin*m_sommet[i].m_quantite;/// Quantité restante en carottes

                    if(nvleVal < 0)
                    {
                        m_sommet[besoin_S].m_quantite = 0; /// Il n'y a plus de carottes
                        nvleVal /= besoin; /// Nombre de lapins qui peuvent encore se nourrir
                        nvleVal = nvleVal*(-1); /// nombre population non-nourrit

                        m_sommet[besoin_S].Set_marquage(true); /// On enlève le S besoin

                        if(!m_sommet[i].m_besoin[j].m_vitale) /// Si besoin non vital
                        {
                            //if( (nvleVal*100)/m_sommet[i].m_quantite > 50 ) /// Si moins de la moitié de la pop manque de la ressource
                            nb_besoin_nonvitaux_insatisfaits.push_back(nvleVal); /// On dit qu'il y a eu un manque
                        }
                        if(m_sommet[i].m_besoin[j].m_vitale) /// Si le besoin est vital
                        {
                            //if( (nvleVal*100)/m_sommet[i].m_quantite > 50 ) /// Si moins de la moitié de la pop manque de la ressource
                            nb_besoin_vitaux_insatisfaits.push_back(nvleVal); /// On dit qu'il y a eu un manque
                        }
                        /*
                        int nb_lapin_rest;
                        nb_lapin_rest = m_sommet[i].m_quantite - nvleVal; /// On regarde le nombre de lapin restant

                        if(nb_lapin_rest >= 0) /// si il reste des lapins, on actualise
                            m_sommet[i].m_quantite = nb_lapin_rest;

                        if(nb_lapin_rest < 0) /// Sinon, on ne revient plus sur le sommet
                        {
                            m_sommet[i].Set_marquage(true);
                            m_sommet[i].m_quantite=0;
                        }*/
                    }
                    else
                        ++reproduction;
                }
            }

            /// Pourcentage de besoins insatisfaits
            /*int insatisfait = (nb_besoin_nonvitaux_insatisfaits.size()+nb_besoin_vitaux_insatisfaits)*100;
            insatisfait /= m_sommet[i].m_besoin.size();

            int couple;
            couple = (m_sommet[i].m_quantite )/2; /// On détermine le nombre de couple

            if(!m_sommet[i].m_marque) /// Si S non marqué, on envisage une reproduction
            {
                if(insatisfait < 30) /// si moins de 30% des besoins insatisfaits et besoins vitaux satisfaits
                {
                    if(nb_besoin_vitaux_insatisfaits == 0)
                    {
                        Reproduction(m_sommet[i], 1);
                    }
                }
                if(insatisfait >= 30 && insatisfait <50 && nb_besoin_vitaux_insatisfaits == 0) /// si plus de 40% des besoins insatisfaits, on ne se reproduit pas
                {
                    if(nb_besoin_vitaux_insatisfaits == 0)
                    {
                        Reproduction(m_sommet[i],1);
                    }
                }
                if(insatisfait >= 50 && insatisfait < 75 && nb_besoin_vitaux_insatisfaits == 0) /// si plus de 40% des besoins insatisfaits, on ne se reproduit pas
                {
                    /// reproduction
                }
                if(insatisfait >= 75 && nb_besoin_vitaux_insatisfaits == 0) /// si plus de 40% des besoins insatisfaits, on ne se reproduit pas
                {
                    /// reproduction
                }
            }*/
                    int moy_mort(0);
                    int moy_insatisfait_vital(0);
                    int moy_insatisfait_non_vital(0);
                    int total_besoin;

                    int couple;

                    for(int y=0; y < nb_besoin_nonvitaux_insatisfaits.size(); y++) /// Moyenne lapins ayant pas mangé ressources non vitales
                    {
                        moy_insatisfait_non_vital += nb_besoin_nonvitaux_insatisfaits[i];
                    }
                    for(int y=0; y < nb_besoin_vitaux_insatisfaits.size(); y++) /// Moyenne lapins ayant pas mangé ressources vitales
                    {
                        moy_insatisfait_vital += nb_besoin_vitaux_insatisfaits[i];
                    }

                    total_besoin = (nb_besoin_vitaux_insatisfaits.size() + nb_besoin_nonvitaux_insatisfaits.size());
                    moy_mort = (moy_insatisfait_non_vital + moy_insatisfait_vital)/total_besoin;
                    /*moy_insatisfait_vital/= nb_besoin_vitaux_insatisfaits.size(); /// On fait la moyenne
                    moy_insatisfait_non_vital/= nb_besoin_nonvitaux_insatisfaits.size();

                    moy_mort = moy_insatisfait_non_vital + moy_insatisfait_vital;

                    m_sommet[i].m_quantite -= moy_mort; /// On actualise la quantité restante
                    */

                    int nb_lapin_rest;
                    nb_lapin_rest = m_sommet[i].m_quantite - nvleVal; /// On regarde le nombre de lapin restant

                    if(nb_lapin_rest >= 0) /// si il reste des lapins, on actualise
                        m_sommet[i].m_quantite = nb_lapin_rest;

                    if(nb_lapin_rest < 0) /// Sinon, on ne revient plus sur le sommet
                    {
                        m_sommet[i].Set_marquage(true);
                        m_sommet[i].m_quantite=0;
                    }

                    if(m_sommet[i].m_quantite < 0) /// Si tout le monde est mort
                        m_sommet[i].m_quantite = 0;

                    else /// Sinon
                    {
                        couple = (m_sommet[i].m_quantite)/2; /// On détermine le nombre de couple
                        m_sommet[i].m_quantite = m_sommet[i].m_quantite + couple* m_sommet[i].m_coeff;
                    }

                }
            }
        }
//void Graphe::Actualiser_S(bool a, int besoin_S)
//{
//
//}
//
//void Graphe::Remplir_sommet(vector<Sommet> s1)
//{
//    for(int i=0; i < s1.size(); i++)
//    {
//        /// Remplir les sommets pour tester
//    }
//}

Graphe::~Graphe()
{
    //dtor
}
