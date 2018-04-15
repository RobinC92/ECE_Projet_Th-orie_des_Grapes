#include "Affichage.h"

Affichage::Affichage()
{
    m_top_box.set_frame(0, 0, 1025, 800);

    m_top_box.add_child( m_img );
    m_img.set_dim(1025, 800);
    m_img.set_pic_name("menu.jpg");


/// Puis un 2eme bouton avec une image
    m_top_box.add_child( m_boite_boutons1 );
    m_boite_boutons1.set_dim(100, 40);
    m_boite_boutons1.set_pos(60,450);

    m_boite_boutons1.add_child( m_bouton1 );
    m_bouton1.set_dim(100,40);
    m_boite_boutons1.add_child(m_bouton1_image);
    m_bouton1_image.set_pic_name("bouton1.jpg");


/// Puis un 2eme bouton avec une image
    m_top_box.add_child( m_boite_boutons2 );
    m_boite_boutons2.set_dim(100, 40);
    m_boite_boutons2.set_pos(460,450);

    m_boite_boutons2.add_child( m_bouton2 );
    m_bouton2.set_dim(100,40);
    m_boite_boutons2.add_child(m_bouton2_image);
    m_bouton2_image.set_pic_name("bouton2.jpg");


/// Puis un 2eme bouton avec une image
    m_top_box.add_child( m_boite_boutons3 );
    m_boite_boutons3.set_dim(100, 40);
    m_boite_boutons3.set_pos(820,450);

    m_boite_boutons3.add_child( m_bouton3 );
    m_bouton3.set_dim(100,40);
    m_boite_boutons3.add_child(m_bouton3_image);
    m_bouton3_image.set_pic_name("bouton3.png");


/// Puis un 2eme bouton avec une image
    m_top_box.add_child( m_boite_boutons4 );
    m_boite_boutons4.set_dim(100, 40);
    m_boite_boutons4.set_pos(0,720);

    m_boite_boutons4.add_child( m_bouton4 );
    m_bouton4.set_dim(100,40);
    m_boite_boutons4.add_child(m_bouton4_image);
    m_bouton4_image.set_pic_name("bouton4.jpg");
}

Affichage::~Affichage()
{
    //dtor
}


void Affichage::update(bool &i)
{
    /// Si tous les widgets dépendants de l'objet sont dans une top box
    /// alors ce seul appel suffit (la propagation d'updates se fait ensuite automatiquement)
    m_top_box.update();
    bool r(false);

    if ( m_bouton1.clicked() )
    {
        std::string doc = "images.txt";
        std :: string fond = "fond.jpg";
        std::string doct = "donnees.txt";
        Graphe first;
        Graph g;
        charger(first,doct);
        chargerImages(first, doc);
        g.make_graph(first);
        init_matAdj(first);
        matAdj(first);
        int n=0;
        bool i(0);
        /// Vous gardez la main sur la "boucle de jeu"
        /// ( contrairement à des frameworks plus avancés )
        first.printSCCs();
        while ( r!=true)
        {

            /// Il faut appeler les méthodes d'update des objets qui comportent des widgets
            first = g.update(first,n,i,r,fond,doct);
            /// Mise à jour générale (clavier/souris/buffer etc...)
            grman::mettre_a_jour();
            //rest(10);
            n++;
        }
    }




    if ( m_bouton2.clicked() )
    {
        std::string doc = "images1.txt";
        std :: string fond = "fond1.jpg";
        std::string doct = "donnees1.txt";
        Graphe first;
        Graph g;
        charger(first,doct);
        chargerImages(first, doc);
        g.make_graph(first);
        int n=0;
        bool i(0);
        bool q(0);
        /// Vous gardez la main sur la "boucle de jeu"
        /// ( contrairement à des frameworks plus avancés )
        while ( r!=true )
        {

            /// Il faut appeler les méthodes d'update des objets qui comportent des widgets
            first = g.update(first,n,i,r,fond,doct);
            /// Mise à jour générale (clavier/souris/buffer etc...)
            grman::mettre_a_jour();
            //rest(10);
            n++;
        }
    }




    if ( m_bouton3.clicked() )
    {
        std::string doc = "images2.txt";
        std :: string fond = "fond2.jpg";
        std::string doct = "donnees2.txt";
        Graphe first;
        Graph g;
        charger(first,doct);
        chargerImages(first, doc);
        g.make_graph(first);
        int n=0;
        bool i(0);
        bool q(0);
        /// Vous gardez la main sur la "boucle de jeu"
        /// ( contrairement à des frameworks plus avancés )
        while (r!=true)
        {

            /// Il faut appeler les méthodes d'update des objets qui comportent des widgets
            first = g.update(first,n,i,r,fond,doct);
            /// Mise à jour générale (clavier/souris/buffer etc...)
            grman::mettre_a_jour();
            //rest(10);
            n++;
        }
    }

    if ( m_bouton4.clicked() )
    {
        i=1;
    }

}
