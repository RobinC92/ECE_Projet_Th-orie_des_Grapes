#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED

#include "grman/widget.h"
#include "grman/grman.h"
#include "graph.h"
#include <iostream>

class Affichage
{

public:
    Affichage();
    ~Affichage();
    grman::WidgetBox m_top_box;
    grman::WidgetImage m_img;
    grman::WidgetBox m_boite_boutons1;
    grman::WidgetBox m_boite_boutons2;
    grman::WidgetBox m_boite_boutons3;
    grman::WidgetBox m_boite_boutons4;
    grman::WidgetButton m_bouton1;       // Sera le bouton avec le texte NEW
    grman::WidgetButton m_bouton2;       // Sera le bouton avec le texte NEW
    grman::WidgetButton m_bouton3;       // Sera le bouton avec le texte NEW
    grman::WidgetButton m_bouton4;       // Sera le bouton avec le texte NEW
    grman::WidgetImage m_bouton1_image;  // L'image de clown méchant
    grman::WidgetImage m_bouton2_image;  // L'image de clown méchant
    grman::WidgetImage m_bouton3_image;  // L'image de clown méchant
    grman::WidgetImage m_bouton4_image;  // L'image de clown méchant


    void update(bool &i);
};


#endif // AFFICHAGE_H_INCLUDED
