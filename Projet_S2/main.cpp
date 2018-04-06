#include <iostream>
#include "Graphe.h"
#include "Fichier.h"

using namespace std;


int main()
{
//    vector<int> tab;
//    int kase;
//    cin >> kase;
///    tab.erase(tab.begin()+kase); // Supprime la case numéro kase


    Graphe first;

    charger(first);

    first.Actualiser_Graphe(first);

    sauver(first);

    cout << endl;
    for(int i=0; i<first.m_sommet.size(); i++)
    {
     cout << first.m_sommet[i].m_quantite << " ";
    }

//int a(2);
//float b(3.5);
//float c;
//c= a/b;
//cout << c;
    return 0;
}
