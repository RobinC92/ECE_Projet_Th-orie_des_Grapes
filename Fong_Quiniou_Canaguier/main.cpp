#include "grman/grman.h"
#include <iostream>

#include "graph.h"
#include "Affichage.h"

int main()
{
    /// A appeler en 1er avant d'instancier des objets graphiques etc...
    grman::init();

    /// Le nom du répertoire où se trouvent les images à charger
    grman::set_pictures_path("pics");


    /// Un exemple de graphe
    Affichage m;

   bool i(0);


    /// Vous gardez la main sur la "boucle de jeu"
    /// ( contrairement à des frameworks plus avancés )
    while ( i!=1 )
    {
        m.update(i);
        /// Mise à jour générale (clavier/souris/buffer etc...)
        grman::mettre_a_jour();

        rest(10);
        //n++;
    }

    grman::fermer_allegro();

    return 0;
}
END_OF_MAIN();
