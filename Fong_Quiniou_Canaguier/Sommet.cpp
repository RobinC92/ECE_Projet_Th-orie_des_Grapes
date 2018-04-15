#include "Sommet.h"

Sommet::Sommet() : m_num(0), m_quantite(0), m_marque(0), m_coeff(0), m_quantiteMax(0), m_nbBesoin(0)
{
    //ctor
}

void Sommet::Set_marquage(bool a)
{
    m_marque=a;
}

Sommet::~Sommet()
{
    //dtor
}
