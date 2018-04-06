#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED

#include <iostream>
#include <vector>
#include <fstream>
#include "Graphe.h"
#include "Sommet.h"
#include "Besoin.h"
#include "Arete.h"


void alloueMat(int nbSom, Graphe &G);
void charger(Graphe &G, std::string doc);
void chargerImages(Graphe &G);
void sauver(Graphe &G);
void sauverImages(Graphe &G);
void init_BesoinsVitaux(Graphe &G);


#endif // FICHIER_H_INCLUDED



