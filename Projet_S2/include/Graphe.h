#ifndef GRAPHE_H
#define GRAPHE_H
#include "Sommet.h"
#include <stack>

class Graphe
{
public:

    Graphe();
    int Actualiser_Graphe(Graphe &first);
    void Reproduction(Sommet&m_sommet);
    void Calcul_insatisfait(std::vector<float> &a, float &b);



    void fillOrder(int v, bool visited[], std::stack<int> &Stack);
    // A recursive function to print DFS starting from v
    void DFSUtil(int v, bool visited[]);
    void printSCCs();

    // Function that returns reverse (or transpose) of this graph
    Graphe getTranspose();
    virtual ~Graphe();

    int m_nbSom;
    std::vector<Sommet> m_sommet;
    std::vector<std::vector <int>> m_matAdj;



protected:

private:

    //std::vector<Sommet> m_sommet;
};

#endif // GRAPHE_H
