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


    std::string doc= "donnees.txt";
    Graphe first;

    charger(first, doc);
    init_BesoinsVitaux(first);

    first.Actualiser_Graphe(first);

    sauver(first);

    cout << endl;
    for(int i=0; i<first.m_sommet.size(); i++)
    {
     cout << first.m_sommet[i].m_quantite << " ";
    }

    return 0;
}
