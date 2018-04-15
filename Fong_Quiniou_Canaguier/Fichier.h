#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED

#include <iostream>
#include <vector>
#include <fstream>
#include "Graphe.h"
#include "Sommet.h"
#include "Besoin.h"

//void alloueMat(int nbSom, Graphe G);
void charger(Graphe &G,std :: string doc);
void chargerImages(Graphe &G, std::string doc);
void sauver(Graphe &G,std :: string doc);
void sauverImages(Graphe &G);
void init_matAdj(Graphe &G);
void matAdj(Graphe &G);



#endif // FICHIER_H_INCLUDED



