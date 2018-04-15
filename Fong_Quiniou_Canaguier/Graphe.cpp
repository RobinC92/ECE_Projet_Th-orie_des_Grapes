#include "Graphe.h"

#include <vector>
using namespace std;

Graphe::Graphe()
{
    //ctor
}

int Graphe::Actualiser_Graphe(Graphe & first)
{
    char a;
    int fin(0);

    for(int i=0; i<m_sommet.size(); i++) /// On parcourt tout les besoins, et on enlève les quantités correspondantes
    {
        //system("cls");
        int reproduction(0);
        vector <float> nb_besoin_vitaux_insatisfaits;
        vector <float> nb_besoin_nonvitaux_insatisfaits;
        float nvleVal;
        float moy_mort(0);
        float moy_insatisfait_vital(0);
        float moy_insatisfait_non_vital(0);
        float total_besoin;


        cout << "tour de boucle : " << i << endl;
        if(m_sommet[i].m_marque)
        {
            cout << "Le sommet numero : " << m_sommet[i].m_num << " est marque, on le passe." << endl;
            ++fin;
            /// Le sommet est marqué, on le saute
        }
        else if(!m_sommet[i].m_marque)
        {
            if(m_sommet[i].m_besoin.size()==0) /// Si le sommet n'a pas de besoin, il ne fait que se reproduire
            {
                float couple;
                couple = (m_sommet[i].m_quantite)/2; /// On détermine le nombre de couple
                m_sommet[i].m_quantite = m_sommet[i].m_quantite + couple* m_sommet[i].m_coeff;
            }
            else if(m_sommet[i].m_besoin.size()>0) /// Si le sommet a des voisins
            {
                for(int j=0; j<m_sommet[i].m_besoin.size(); j++)
                {
                    if(m_sommet[i].m_marque)
                    {
                        cout << "Le sommet numero : " << m_sommet[i].m_num << " est marque, on le passe." << endl;

                        /// Le sommet est marqué, on le saute
                    }
                    else
                    {
                        float besoin = m_sommet[i].m_besoin[j].m_quantiteBesoin/**m_sommet[i].m_besoin[j].m_coeffBesoin/100*/; /// Besoin du S Lapin en carottes
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

                                cout << "le sommet "<< besoin_S << " est vital et deja marque, on met le sommet: " << m_sommet[i].m_num << " a 0." << endl;
                            }
                            if(!m_sommet[i].m_besoin[j].m_vitale)
                            {
                                nb_besoin_nonvitaux_insatisfaits.push_back(m_sommet[i].m_quantite);
                                cout << "le sommet "<< besoin_S << " est nonvital et deja marque" << endl;
                            }
                        }

                        else if(!m_sommet[besoin_S].m_marque)
                        {
                            cout << besoin << endl;
                            cout << "besoin*m_sommet[i].m_quantite: " << besoin*m_sommet[i].m_quantite<< endl; ;
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
                            else if(nvleVal >=0 && nvleVal <2)
                            {
                                m_sommet[besoin_S].m_quantite = 0; /// Il n'y a plus de carottes
                                m_sommet[besoin_S].Set_marquage(true); /// On enlève le S besoin
                                cout << "On supprime le sommet " << besoin_S << endl;
                            }

                            else if(nvleVal > 2)
                            {
                                m_sommet[besoin_S].m_quantite = nvleVal;
                            }
                        }
                    }
                }

                if(!m_sommet[i].m_marque)
                {
                    cout << endl;
                    cout << "taille du vecteur vital: " << nb_besoin_vitaux_insatisfaits.size() << endl;
                    cout << "taille du vecteur nonvital: " << nb_besoin_nonvitaux_insatisfaits.size() << endl;


                    Calcul_insatisfait(nb_besoin_vitaux_insatisfaits, moy_insatisfait_vital); /// Insatisfait vitalement
                    Calcul_insatisfait(nb_besoin_nonvitaux_insatisfaits, moy_insatisfait_non_vital); /// Insatisfait non_vitalement


                    moy_mort = moy_insatisfait_vital; /// nb de mort

                    if(moy_insatisfait_vital>0) /// Si il y a eu des lapins insatisfaits vitalement
                    {
                        float nb_lapin_rest;
                        nb_lapin_rest = m_sommet[i].m_quantite - moy_insatisfait_vital; /// Nb de lapins restant
                        /// Si m_sommet[i] déjà marqué, alors m_sommet[i].m_quantite=0 (ligne 63)

                        cout << "nb_lapin_rest bra: "<< nb_lapin_rest << endl;

                        if(nb_lapin_rest > 0)
                        {
                            if(moy_insatisfait_non_vital>0)
                            {
                                float pourcentage;
                                pourcentage = (moy_insatisfait_non_vital*100)/(m_sommet[i].m_quantite);

                                if(pourcentage < 50)
                                {
                                    ///Personne ne meurt en plus
                                    m_sommet[i].m_quantite = nb_lapin_rest;
                                    Reproduction(m_sommet[i]);

                                }
                                else if(pourcentage >= 50)
                                {
                                    moy_mort *= 1.2; /// On augmente les morts de 20%

                                    m_sommet[i].m_quantite -= moy_mort;

                                    if (m_sommet[i].m_quantite >= 2.0) /// Si il y a plus de 2 individus
                                    {
                                        /// Alors on se reproduit
                                        Reproduction(m_sommet[i]);
                                    }
                                    if(m_sommet[i].m_quantite <= 0)
                                    {
                                        m_sommet[i].m_quantite=0;
                                        m_sommet[i].m_marque=true;
                                        cout << "On supprime le sommet " << m_sommet[i].m_num << endl;
                                    }

                                }
                            }
                            else if(moy_insatisfait_non_vital <= 0)
                            {
                                /// Alors on se reproduit
                                m_sommet[i].m_quantite = nb_lapin_rest;

                                if (m_sommet[i].m_quantite >= 2.0) /// Si il y a plus de 2 individus
                                {
                                    /// Alors on se reproduit
                                    Reproduction(m_sommet[i]);
                                }

                            }

                        }
                        else if(nb_lapin_rest <= 0)
                        {
                            /// On supprime le sommet
                            m_sommet[i].m_quantite=0;
                            m_sommet[i].m_marque=true;
                            cout << "On supprime le sommet " << m_sommet[i].m_num << endl;
                        }
                    }
                    else if(moy_insatisfait_non_vital>0)
                    {
                        float pourcentage;
                        pourcentage = (moy_insatisfait_non_vital*100)/(m_sommet[i].m_quantite);

                        if(pourcentage < 50)
                        {
                            ///Personne ne meurt
                            /// On se reproduit ...
                            if (m_sommet[i].m_quantite >= 2.0) /// Si il y a plus de 2 individus
                            {
                                /// Alors on se reproduit
                                Reproduction(m_sommet[i]);
                            }
                            if(m_sommet[i].m_quantite <= 0)
                            {
                                m_sommet[i].m_quantite=0;
                                m_sommet[i].m_marque=true;
                                cout << "On supprime le sommet " << m_sommet[i].m_num << endl;
                            }

                        }
                        else if(pourcentage >= 50)
                        {
                            moy_mort = moy_insatisfait_non_vital/2.0; /// La moitié insatisfaite non_vitalement meurt

                            m_sommet[i].m_quantite -= moy_mort;

                            if(m_sommet[i].m_quantite >= 2.0) /// Si il y a plus de 2 individus
                            {
                                /// Alors on se reproduit
                                Reproduction(m_sommet[i]);
                            }
                            if(m_sommet[i].m_quantite <= 0)
                            {
                                m_sommet[i].m_quantite=0;
                                m_sommet[i].m_marque=true;
                                cout << "On supprime le sommet " << m_sommet[i].m_num << endl;
                            }

                        }
                    }
                    else
                    {
                        /// Reproduction normale
                        if (m_sommet[i].m_quantite >= 2.0) /// Si il y a plus de 2 individus
                        {
                            /// Alors on se reproduit
                            Reproduction(m_sommet[i]);
                        }
                        if(m_sommet[i].m_quantite <= 0)
                        {
                            m_sommet[i].m_quantite=0;
                            m_sommet[i].m_marque=true;
                            cout << "On supprime le sommet " << m_sommet[i].m_num << endl;
                        }
                    }

                }

            }
            //getchar();
        }
    }
    return fin;
}
void Graphe::Reproduction(Sommet&m_sommet)
{
    float couple;
    float tempon;
    tempon = m_sommet.m_quantite;

    couple = (tempon)/2.0; /// On se reproduit dans tous les cas
    cout << "nombre de couple: " << couple << endl;
    m_sommet.m_quantite = m_sommet.m_quantite + couple* m_sommet.m_coeff;
    cout << "nombre de survivants final du sommet " << ": " << m_sommet.m_quantite<< endl;
    cout << endl;
    cout << endl;
}

void Graphe::Calcul_insatisfait(vector<float> &nb_besoin_insatisfaits, float &moy_insatisfait)
{
    if(nb_besoin_insatisfaits.size() > 0)
    {
        for(int y=0; y < nb_besoin_insatisfaits.size(); y++) /// Moyenne lapins ayant pas mangé ressources non vitales
        {
            moy_insatisfait += nb_besoin_insatisfaits[y];
            cout << "moy_insatisfait: " << moy_insatisfait << endl;
        }
        moy_insatisfait/=nb_besoin_insatisfaits.size();
    }
}

vector<int> Graphe::Recursion(int v, bool visited[])
{
    vector<int> connexe;

    DFSUtil(v,visited,connexe);

    cout << "taille: " << connexe.size()<< endl;

    if(connexe.size()>=2)
    {
        return connexe;
    }
    else
    {
        connexe.clear();
        return connexe;
    }
}

void Graphe::DFSUtil(int v, bool visited[], vector<int> &connexe)
{
    // Mark the current node as visited and print it
    visited[v] = true;

    cout << v << " ";

    connexe.push_back(v);
    //Recur for all the vertices adjacent to this vertex
    for (int i = 0; i < m_sommet[v].m_besoin.size(); ++i)
        if (!visited[m_sommet[v].m_besoin[i].m_numSommet])
            DFSUtil(m_sommet[v].m_besoin[i].m_numSommet, visited, connexe);
}

Graphe Graphe::getTranspose()
{
    Graphe g;


    /// Mettre dans g les sommets du graphe

    for (int v = 0; v < m_nbSom; v++)
    {
        Sommet s1;
        Besoin b1;

        s1.m_num = m_sommet[v].m_num;
        s1.m_quantite = 1;
        s1.m_marque = 1;
        s1.m_coeff = 1;
        s1.m_nbBesoin = 1;
        // Recur for all the vertices adjacent to this vertex

        //cout << "adj du sommet: "<< m_sommet[v].m_num << ": " << m_sommet[v].m_adj.size() << endl;
        for (int i=0; i<m_sommet[v].m_adj.size(); i++) /// ADJ
        {
            int adj(0);
            for(int j =0; j < m_sommet[v].m_besoin.size(); j++)
            {
                if(m_sommet[v].m_adj[i]==m_sommet[v].m_besoin[j].m_numSommet)
                {
                    ++adj;
                }
            }
            if(adj == 0) /// Si ce n'est pas un besoin
            {
                b1.m_numSommet = m_sommet[v].m_adj[i];
                b1.m_quantiteBesoin=0;
                b1.m_vitale=true;

                s1.m_besoin.push_back(b1);
//                cout << "le sommet " << s1.m_num << " a pour besoin " << m_sommet[v].m_adj[i] << endl;
            }

        }
        g.m_sommet.push_back(s1);
    }


    return g;
}

void Graphe::fillOrder(int v, bool visited[], stack<int> &Stack)
{
    // Mark the current node as visited and print it
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex

    for (int i = 0; i < m_sommet[v].m_besoin.size(); ++i)
        if (!visited[m_sommet[v].m_besoin[i].m_numSommet])
            fillOrder(m_sommet[v].m_besoin[i].m_numSommet, visited, Stack);

    // All vertices reachable from v are processed by now, push v
    Stack.push(v);
}

void Graphe::printSCCs()
{
    m_illumine.clear();

    stack<int> Stack;

    // Mark all the vertices as not visited (For first DFS)
    bool * visited = new bool[m_nbSom];
    for(int i = 0; i < m_nbSom; i++)
        visited[i] = false;

    // Fill vertices in stack according to their finishing times
    for(int i = 0; i < m_nbSom; i++)
        if(visited[i] == false)
            fillOrder(i, visited, Stack);

    // Create a reversed graph
    Graphe gr = getTranspose();

    // Mark all the vertices as not visited (For second DFS)
    for(int i = 0; i < m_nbSom; i++)
        visited[i] = false;

    // Now process all vertices in order defined by Stack
    while (Stack.empty() == false)
    {
        // Pop a vertex from stack
        int v = Stack.top();
        Stack.pop();

        // Print Strongly connected component of the popped vertex
        if (visited[v] == false)
        {
            vector <int> a;
            a = gr.Recursion(v, visited);

            for(int i = 0; i< a.size(); i++)
            {
                m_illumine.push_back(a[i]);
            }
            cout << endl;
        }
    }
    Tri();
}

void Graphe::Tri()
{
    int tempon;
    int  *tableau = new int[m_illumine.size()];

     for(int i=0; i<m_illumine.size(); i++)
     {
         tableau[i]=m_illumine[i];
     }

     for (int j=0; j<m_illumine.size(); j++) ///Double boucle imbriqué, on tri autant de fois qu'il y a de nombres
    {                         ///Pour les faires "remonter" un par un.
        for (int i=0; i<m_illumine.size()-1; i++)
        {
            if (tableau[i]>tableau[i+1]) // Si les conditions sont respectés, on effectue le swap.
            {
                tempon=tableau[i+1];
                tableau[i+1]=tableau[i];
                tableau[i]=tempon;
            }
        }
    }

    for(int i=0; i<m_illumine.size(); i++)
     {
         m_illumine[i] = tableau[i];
     }
     delete [] tableau;
}

Graphe::~Graphe()
{
    //dtor
}
