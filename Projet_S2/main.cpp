#include <iostream>
#include "Graphe.h"
#include "Fichier.h"

using namespace std;


int main()
{
//    vector<int> tab;
//    int kase;
//    cin >> kase;
///    tab.erase(tab.begin()+kase); // Supprime la case num�ro kase


    Graphe first;

    charger(first);

//    for(int i=0; i<2; i++)
//    {
//        first.Actualiser_Graphe(first);
//        cout << endl;
//        cout << endl;
//        cout << endl;
//        cout << endl;
//        for(int i=0; i<first.m_sommet.size(); i++)
//        {
//            cout << first.m_sommet[i].m_quantite << " ";
//        }
//        cout << endl;
//        cout << endl;
//        cout << endl;
//        cout << endl;
//
//    }
int fin(0);
    while (fin<first.m_sommet.size())
    {

        fin = first.Actualiser_Graphe(first);
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "gros affichage" << endl;
        for(int i=0; i<first.m_sommet.size(); i++)
        {
            cout << first.m_sommet[i].m_quantite << " ";
        }
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
    }

    sauver(first);


//    cout << endl;
//    for(int i=0; i<first.m_sommet.size(); i++)
//    {
//        cout << first.m_sommet[i].m_quantite << " ";
//    }

    return 0;
}
