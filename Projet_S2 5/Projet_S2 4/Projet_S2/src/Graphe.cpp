#include "Graphe.h"

#include <vector>
using namespace std;

Graphe::Graphe()
{
    //ctor
}

void Graphe::Reproduction(Sommet & sommet1, int couple)
{

}

void Graphe::Actualiser_Graphe(Graphe & first)
{
    char a;

    for(int i=0; i<m_sommet.size(); i++) /// On parcourt tout les besoins, et on enlève les quantités correspondantes
    {
        //system("cls");
        int reproduction(0);
        vector <float> nb_besoin_vitaux_insatisfaits;
        vector<float> nb_besoin_nonvitaux_insatisfaits;
        float nvleVal;
        float moy_mort(0);
        float moy_insatisfait_vital(0);
        float moy_insatisfait_non_vital(0);
        float total_besoin;
        float couple;

        cout << "tour de boucle : " << i << endl;
        if(m_sommet[i].m_marque)
        {
            cout << "Le sommet numero : " << m_sommet[i].m_num << " est marque, on le passe." << endl;
            /// Le sommet est marqué, on le saute
        }
        else if(!m_sommet[i].m_marque)
        {
            if(m_sommet[i].m_besoin.size()==0) /// Si le sommet n'a pas de besoin, il ne fait que se reproduire
            {
                couple = (m_sommet[i].m_quantite)/2; /// On détermine le nombre de couple
                m_sommet[i].m_quantite = m_sommet[i].m_quantite + couple* m_sommet[i].m_coeff;
            }
            else if(m_sommet[i].m_besoin.size()>0) /// Si le sommet a des voisins
            {
                for(int j=0; j<m_sommet[i].m_besoin.size(); j++)
                {

                    float besoin = m_sommet[i].m_besoin[j].m_quantiteBesoin; /// Besoin du S Lapin en carottes
                    float besoin_S = m_sommet[i].m_besoin[j].m_numSommet; /// Le num du S carottes
                    nvleVal = m_sommet[besoin_S].m_quantite; /// Quantité du S carottes

                    cout << "Le sommet " << i << "contient " << m_sommet[i].m_quantite << " a besoin du sommet " << besoin_S << ", contenant : " << nvleVal << endl;

                    if(m_sommet[besoin_S].m_marque) /// Si le besoin est marqué
                    {
                        if(m_sommet[i].m_besoin[j].m_vitale) /// Si il est vital
                        {
                            nb_besoin_vitaux_insatisfaits.push_back(m_sommet[i].m_quantite);
                            m_sommet[i].m_marque=true;
                            m_sommet[i].m_quantite=0;

                            cout << "le sommet est vital et deja marque, on met le sommet: " << m_sommet[i].m_num << " a 0." << endl;
                        }
                        if(!m_sommet[i].m_besoin[j].m_vitale)
                        {
                            nb_besoin_nonvitaux_insatisfaits.push_back(m_sommet[i].m_quantite);
                            cout << "le sommet est nonvital et deja marque" << endl;
                        }
                    }

                    else if(!m_sommet[besoin_S].m_marque)
                    {
                        nvleVal = m_sommet[besoin_S].m_quantite - besoin*m_sommet[i].m_quantite;/// Quantité restante en carottes
                        m_sommet[besoin_S].m_quantite = nvleVal;
                        cout << "quantite restante du sommet" << besoin_S << " : " << nvleVal << endl;

                        if(nvleVal < 0)
                        {
                            m_sommet[besoin_S].m_quantite = 0; /// Il n'y a plus de carottes
                            nvleVal /= besoin;
                            nvleVal = nvleVal*(-1); /// Nombre de lapins  non-nourrit


                            m_sommet[besoin_S].Set_marquage(true); /// On enlève le S besoin

                            if(!m_sommet[i].m_besoin[j].m_vitale) /// Si besoin non vital
                            {
                                nb_besoin_nonvitaux_insatisfaits.push_back(nvleVal); /// On dit qu'il y a eu un manque
                                cout << "nombre non nourrit :" << nvleVal << endl;
                            }
                            if(m_sommet[i].m_besoin[j].m_vitale) /// Si le besoin est vital
                            {
                                nb_besoin_vitaux_insatisfaits.push_back(nvleVal); /// On dit qu'il y a eu un manque
                                cout << "nombre non nourrit :" << nvleVal << endl;

                            }
                        }
                        else if(nvleVal ==0)
                        {
                            m_sommet[besoin_S].m_quantite = 0; /// Il n'y a plus de carottes
                            m_sommet[besoin_S].Set_marquage(true); /// On enlève le S besoin
                        }
                        else if(nvleVal > 0)
                        {
                            m_sommet[besoin_S].m_quantite = nvleVal;
                            ++reproduction;
                        }

                    }
                }
                cout << endl;
                cout << "taille du vecteur vital: " << nb_besoin_vitaux_insatisfaits.size() << endl;
                cout << "taille du vecteur nonvital: " << nb_besoin_nonvitaux_insatisfaits.size() << endl;

                if(nb_besoin_nonvitaux_insatisfaits.size() > 0)
                {
                    for(int y=0; y < nb_besoin_nonvitaux_insatisfaits.size(); y++) /// Moyenne lapins ayant pas mangé ressources non vitales
                    {
                        moy_insatisfait_non_vital += nb_besoin_nonvitaux_insatisfaits[y];
                        cout << "moy_insatisfait_non_vital: " << moy_insatisfait_non_vital << endl;
                    }
                }

                if(nb_besoin_vitaux_insatisfaits.size()>0)
                {
                    for(int y=0; y < nb_besoin_vitaux_insatisfaits.size(); y++) /// Moyenne lapins ayant pas mangé ressources vitales
                    {
                        moy_insatisfait_vital += nb_besoin_vitaux_insatisfaits[y];
                        cout << "moy_insatisfait_vital: " << moy_insatisfait_vital << endl;
                    }

                }


                if(nb_besoin_nonvitaux_insatisfaits.size() > 0 || nb_besoin_vitaux_insatisfaits.size() > 0)
                {
                    total_besoin = (nb_besoin_vitaux_insatisfaits.size() + nb_besoin_nonvitaux_insatisfaits.size());
                    moy_mort = (moy_insatisfait_non_vital + moy_insatisfait_vital)/total_besoin;

                    cout << "moy_insatisfait_non_vital: " << moy_insatisfait_non_vital << endl;
                    cout << "moy_insatisfait_vital: " << moy_insatisfait_vital << endl;
                    cout << "denominateur: " << total_besoin << endl;
                    cout << "moy_mort: " << moy_mort << endl;


                    float nb_lapin_rest;
                    nb_lapin_rest = m_sommet[i].m_quantite - moy_mort; /// On regarde le nombre de lapin restant
                    /// Si m_sommet[i] déjà marqué, alors m_sommet[i].m_quantite=0 (ligne 63)

                    cout << "nb_lapin_rest: "<< nb_lapin_rest << endl;

                    if(nb_lapin_rest > 0) /// si il reste des lapins, on actualise
                    {
                        cout << endl;
                        cout << endl;
                        cout << "nombre de survivants du sommet " << m_sommet[i].m_num <<": " << nb_lapin_rest<< endl;
                    }

                    if(nb_lapin_rest <= 0) /// Sinon, on ne revient plus sur le sommet
                    {
                        cout << endl;
                        cout << endl;
                        m_sommet[i].Set_marquage(true);
                        nb_lapin_rest = 0;
                        m_sommet[i].m_quantite=0;
                        cout << "nombre de survivants du sommet " << m_sommet[i].m_num <<": " << nb_lapin_rest<< endl;
                    }

                    couple = (nb_lapin_rest)/2.0; /// On se reproduit dans tous les cas
                    cout << "nombre de couple: " << couple << endl;
                    cout << "nombre de bb engendrer: " << couple*m_sommet[i].m_coeff << endl;
                    cout << endl;
                    m_sommet[i].m_quantite = m_sommet[i].m_quantite + couple* m_sommet[i].m_coeff;
                    cout << "nombre de survivants final du sommet " << ": " << m_sommet[i].m_quantite<< endl;
                    cout << endl;
                    cout << endl;

                }

                if (nb_besoin_nonvitaux_insatisfaits.size() == 0 && nb_besoin_vitaux_insatisfaits.size() == 0)
                {
                    float tempon;
                    tempon = m_sommet[i].m_quantite;

                    couple = (tempon)/2.0; /// On se reproduit dans tous les cas
                    cout << "nombre de bb engendrer: " << couple << endl;
                    m_sommet[i].m_quantite = m_sommet[i].m_quantite + couple* m_sommet[i].m_coeff;
                    cout << "nombre de survivants final du sommet " << ": " << m_sommet[i].m_quantite<< endl;
                    cout << endl;
                    cout << endl;
                }

            }

        }

        //getchar();

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
