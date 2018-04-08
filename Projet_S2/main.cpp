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

//    std::string doc= "donnees.txt";
//
    Graphe first;

    charger(first, "donnees.txt");
    init_BesoinsVitaux(first);
    matAdj(first);



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
int j(0);

first.printSCCs();

//        first.Actualiser_Graphe(first);
//
//        for(int i=0; i<first.m_sommet.size(); i++)
//        {
//            cout << first.m_sommet[i].m_quantite << " ";
//        }
//

    return 0;
}
