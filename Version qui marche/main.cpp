#include "grman/grman.h"
#include <iostream>

#include "graph.h"

int main()
{
    /// A appeler en 1er avant d'instancier des objets graphiques etc...
    grman::init();

    /// Le nom du répertoire où se trouvent les images à charger
    grman::set_pictures_path("pics");

    /// Un exemple de graphe
    Graphe first;
    Graph g;
    charger(first);
    chargerImages(first);
    g.make_graph(first);
    int n=0;
    bool i(0);

    /// Vous gardez la main sur la "boucle de jeu"
    /// ( contrairement à des frameworks plus avancés )
    while ( !key[KEY_ESC] )
    {
        /// Il faut appeler les méthodes d'update des objets qui comportent des widgets
        g.update(first);

        /// Mise à jour générale (clavier/souris/buffer etc...)
        grman::mettre_a_jour();

        /*if (i==0)
        {
            g.test_remove_edge(2);

            g.test_remove_vertex(3);
            i=1;
        }
        else
        {

            g.add_interfaced_vertex(3,  0.0, 400, 300, "homme.jpg");
            g.add_interfaced_edge(2, 1, 3, 75.0);
            i=0;
        }*/
        rest(10);
        n++;
    }

    grman::fermer_allegro();

    return 0;
}
END_OF_MAIN();


