#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED

#include <iostream>
#include <vector>
#include <fstream>
#include "Graphe.h"
#include "Sommet.h"
#include "Besoin.h"

//void alloueMat(int nbSom, Graphe G);
void charger(Graphe &G);
void sauver(Graphe &G);


#endif // FICHIER_H_INCLUDED



