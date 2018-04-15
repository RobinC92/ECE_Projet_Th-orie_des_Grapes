#include "graph.h"

/***************************************************
                    VERTEX
****************************************************/

/// Le constructeur met en place les �l�ments de l'interface
VertexInterface::VertexInterface(int idx, int x, int y, std::string pic_name, int pic_idx)
{
    // La boite englobante
    m_top_box.set_pos(x, y);
    m_top_box.set_dim(130, 100);
    m_top_box.set_moveable();

    // Le slider de r�glage de valeur
    m_top_box.add_child( m_slider_value );
    m_slider_value.set_range(0.0, 100.0);  // Valeurs arbitraires, � adapter...
    m_slider_value.set_dim(20,80);
    m_slider_value.set_gravity_xy(grman::GravityX::Left, grman::GravityY::Up);

    // Label de visualisation de valeur
    m_top_box.add_child( m_label_value );
    m_label_value.set_gravity_xy(grman::GravityX::Left, grman::GravityY::Down);

    // Une illustration...
    if (pic_name!="")
    {
        m_top_box.add_child( m_img );
        m_img.set_pic_name(pic_name);
        m_img.set_pic_idx(pic_idx);
        m_img.set_gravity_x(grman::GravityX::Right);
    }
    m_img.add_child(m_connex_box);
    m_connex_box.set_dim(10,10);
    m_connex_box.set_pos(0,0);
    // Label de visualisation d'index du sommet dans une boite
    m_top_box.add_child( m_box_label_idx );
    m_box_label_idx.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Down);
    m_box_label_idx.set_dim(20,12);
    m_box_label_idx.set_bg_color(BLANC);

    m_top_box.add_child(m_supp_box);
    m_supp_box.set_dim(10,10);
    m_supp_box.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Up);
    m_supp_box.set_bg_color(ROUGECLAIR);

    m_supp_box.add_child(m_supp_image);
    m_supp_image.set_pic_name("supprimer.jpg");

    m_box_label_idx.add_child( m_label_idx );
    m_label_idx.set_message( std::to_string(idx) );
}


/// Gestion du Vertex avant l'appel � l'interface
void Vertex::pre_update()
{
    if (!m_interface)
        return;

    /// Copier la valeur locale de la donn�e m_value vers le slider associ�
    m_interface->m_slider_value.set_value(m_value);

    /// Copier la valeur locale de la donn�e m_value vers le label sous le slider
    m_interface->m_label_value.set_message( std::to_string( (int)m_value) );
}


/// Gestion du Vertex apr�s l'appel � l'interface
void Vertex::post_update()
{
    if (!m_interface)
        return;

    /// Reprendre la valeur du slider dans la donn�e m_value locale
    m_value = m_interface->m_slider_value.get_value();
}



/***************************************************
                    EDGE
****************************************************/

/// Le constructeur met en place les �l�ments de l'interface
EdgeInterface::EdgeInterface(Vertex& from, Vertex& to)
{
    // Le WidgetEdge de l'interface de l'arc
    if ( !(from.m_interface && to.m_interface) )
    {
        std::cerr << "Error creating EdgeInterface between vertices having no interface" << std::endl;
        throw "Bad EdgeInterface instanciation";
    }
    m_top_edge.attach_from(from.m_interface->m_top_box);
    m_top_edge.attach_to(to.m_interface->m_top_box);
    m_top_edge.reset_arrow_with_bullet();

    // Une boite pour englober les widgets de r�glage associ�s
//    m_top_edge.add_child(m_box_edge);
//    m_box_edge.set_dim(24,60);
//    m_box_edge.set_bg_color(BLANCBLEU);

    // Le slider de r�glage de valeur
//    m_box_edge.add_child( m_slider_weight );
//    m_slider_weight.set_range(0.0, 200.0);  // Valeurs arbitraires, � adapter...
//    m_slider_weight.set_dim(16,40);
//    m_slider_weight.set_gravity_y(grman::GravityY::Up);

    // Label de visualisation de valeur
    m_box_edge.add_child( m_label_weight );
    m_label_weight.set_gravity_y(grman::GravityY::Down);

}


/// Gestion du Edge avant l'appel � l'interface
void Edge::pre_update()
{
    if (!m_interface)
        return;

    /// Copier la valeur locale de la donn�e m_weight vers le slider associ�
    m_interface->m_slider_weight.set_value(m_weight);

    /// Copier la valeur locale de la donn�e m_weight vers le label sous le slider
    m_interface->m_label_weight.set_message( std::to_string( (int)m_weight ) );
}

/// Gestion du Edge apr�s l'appel � l'interface
void Edge::post_update()
{
    if (!m_interface)
        return;

    /// Reprendre la valeur du slider dans la donn�e m_weight locale
    m_weight = m_interface->m_slider_weight.get_value();
}



/***************************************************
                    GRAPH
****************************************************/

/// Ici le constructeur se contente de pr�parer un cadre d'accueil des
/// �l�ments qui seront ensuite ajout�s lors de la mise ne place du Graphe
GraphInterface::GraphInterface(int x, int y, int w, int h)
{
    m_top_box.set_dim(1000,740);
    m_top_box.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Up);

    m_top_box.add_child(m_tool_box);
    m_tool_box.set_dim(100,720);
    m_tool_box.set_gravity_xy(grman::GravityX::Left, grman::GravityY::Up);
    m_tool_box.set_bg_color(BLANCBLEU);

    m_top_box.add_child(m_main_box);
    m_main_box.set_dim(888,720);
    m_main_box.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Up);

    m_main_box.add_child(m_main_image);

    m_tool_box.add_child(m_add_box);
    m_add_box.set_dim(95,95);
    m_add_box.set_pos(1,101);

    m_add_box.add_child(m_add_image);
    m_add_image.set_pic_name("ajouter.jpg");

    m_tool_box.add_child(m_save);
    m_save.set_dim(95,95);
    m_save.set_gravity_xy(grman::GravityX::Left, grman::GravityY::Up);

    m_save.add_child(m_save_image);
    m_save_image.set_pic_name("save.jpg");


    m_tool_box.add_child(m_simulation);
    m_simulation.set_dim(95,95);
    m_simulation.set_pos(1,201);

    m_simulation.add_child(m_simulation_image);
    m_simulation_image.set_pic_name("Bouton_lecture.jpg");

    m_tool_box.add_child(m_connexite);
    m_connexite.set_dim(95,95);
    m_connexite.set_pos(1,301);

    m_connexite.add_child(m_connexite_image);
    m_connexite_image.set_pic_name("connexite.png");

    m_tool_box.add_child(m_quitter);
    m_quitter.set_dim(95,95);
    m_quitter.set_gravity_xy(grman::GravityX::Left, grman::GravityY::Down);

    m_quitter.add_child(m_quitter_image);
    m_quitter_image.set_pic_name("quitter.png");

}

void Graph::make_graph(Graphe first)
{
    int n=0;
    int e,f;

    m_interface = std::make_shared<GraphInterface>(50, 0, 750, 600);
    // La ligne pr�c�dente est en gros �quivalente � :
    // m_interface = new GraphInterface(50, 0, 750, 600);

    for (int i=0; i<first.m_sommet.size(); i++)
    {
        if (!first.m_sommet[i].m_marque)
            add_interfaced_vertex(first.m_sommet[i].m_num, first.m_sommet[i].m_quantite, first.m_sommet[i].pos_x,first.m_sommet[i].pos_y,first.m_sommet[i].m_quantiteMax, first.m_sommet[i].m_images);
    }
    for (int i=0; i<first.m_sommet.size(); i++)
    {
        for (int j=0; j<first.m_sommet[i].m_nbBesoin; j++)
        {
            if ((!first.m_sommet[i].m_marque)&&(!first.m_sommet[first.m_sommet[i].m_besoin[j].m_numSommet].m_marque))
            {
                e=first.m_sommet[i].m_num;
                f=first.m_sommet[i].m_besoin[j].m_numSommet;
                add_interfaced_edge(n,f,e,first.m_sommet[i].m_besoin[j].m_coeffBesoin);
                n++;
            }
        }
    }
}
void Graph::make_example()
{
    m_interface = std::make_shared<GraphInterface>(50, 0, 750, 600);
    // La ligne pr�c�dente est en gros �quivalente � :
    // m_interface = new GraphInterface(50, 0, 750, 600);

    /// Les sommets doivent �tre d�finis avant les arcs
    // Ajouter le sommet d'indice 0 de valeur 30 en x=200 et y=100 avec l'image clown1.jpg etc...
//    add_interfaced_vertex(0, 30.0, 200, 100, "carotte.jpg");
//    add_interfaced_vertex(1, 60.0, 400, 100, "ble.jpg");
//    add_interfaced_vertex(2,  50.0, 200, 300, "eau.jpg");
//    add_interfaced_vertex(3,  0.0, 400, 300, "homme.jpg");
//    add_interfaced_vertex(4,  100.0, 600, 300, "ours.jpg");
//    add_interfaced_vertex(5,  0.0, 100, 500, "renard.jpg");
//    add_interfaced_vertex(6,  0.0, 300, 500, "poule.jpg");
//    add_interfaced_vertex(7,  0.0, 500, 500, "aigle.jpg");
//    add_interfaced_vertex(8,  100.0, 600, 300, "lapin.jpg");
//    /// Les arcs doivent �tre d�finis entre des sommets qui existent !
//    // AJouter l'arc d'indice 0, allant du sommet 1 au sommet 2 de poids 50 etc...
//    add_interfaced_edge(0, 1, 2, 50.0);
//    add_interfaced_edge(1, 0, 1, 50.0);
//    add_interfaced_edge(2, 1, 3, 75.0);
//    add_interfaced_edge(3, 4, 1, 25.0);

}

/// La m�thode update � appeler dans la boucle de jeu pour les graphes avec interface
Graphe Graph::update(Graphe first, int clk, bool &q, bool &r,std :: string fond,std :: string doct)
{
    int n;
    m_interface->m_main_image.set_pic_name(fond.c_str());

    if (!m_interface)
        return first;
    for (auto &elt : m_vertices)
        elt.second.pre_update();

    for (auto &elt : m_edges)
        elt.second.pre_update();

    m_interface->m_top_box.update();

    for (auto &elt : m_vertices)
    {
        elt.second.post_update();
        if(elt.second.m_interface->m_supp_box.get_value())
        {
            std::cout<<"good"<<std::endl;
            test_remove_vertex(elt.first, first);
            first.m_sommet[elt.first].m_marque=true;
            first.m_sommet[elt.first].m_quantite=0;
            elt.second.m_interface->m_supp_box.set_value(false);
        }
    }

    for (auto &elt : m_edges)
    {
//        elt.second.m_interface->m_top_edge.m_thickness=((m_vertices[elt.second.m_to].m_value/10)*(elt.second.m_weight/10))/10;
//        for (int i=0; i<first.m_sommet[elt.second.m_to].m_nbBesoin; i++)
//        {
//            if (first.m_sommet[elt.second.m_to].m_besoin[i].m_numSommet == elt.second.m_from)
//                first.m_sommet[elt.second.m_to].m_besoin[i].m_coeffBesoin = elt.second.m_weight;
//        }
        elt.second.m_interface->m_top_edge.m_thickness=m_vertices[elt.second.m_to].m_value/15;
        elt.second.post_update();
    }
    for (auto &elt : m_vertices)
    {
        for (int i=0; i<first.m_sommet.size(); i++)
        {
            if (first.m_sommet[i].m_num == elt.first)
            {
                if (first.m_sommet[i].m_quantite != elt.second.m_value)
                {
                    first.m_sommet[i].m_quantite = elt.second.m_value;
                }
                if ((first.m_sommet[i].pos_x != elt.second.m_interface->m_top_box.get_posx())&&(first.m_sommet[i].pos_x -2!= elt.second.m_interface->m_top_box.get_posx()))
                {
                    first.m_sommet[i].pos_x = elt.second.m_interface->m_top_box.get_posx();
                }
                if ((first.m_sommet[i].pos_y != elt.second.m_interface->m_top_box.get_posy())&&(first.m_sommet[i].pos_y -2!= elt.second.m_interface->m_top_box.get_posy()))
                {
                    first.m_sommet[i].pos_y = elt.second.m_interface->m_top_box.get_posy();
                }
            }
        }
    }
    if(m_interface->m_add_box.get_value())
    {
        std :: cout << "Entrer le numero du sommet que vous voulez ajouter:" << std :: endl;
        std :: cin >> n;
        add_interfaced_vertex(first.m_sommet[n].m_num, first.m_sommet[n].m_quantite, first.m_sommet[n].pos_x,first.m_sommet[n].pos_y,first.m_sommet[n].m_quantiteMax, first.m_sommet[n].m_images);
        first.m_sommet[n].m_marque=0;
        m_edges.clear();
        m_vertices.clear();
        make_graph(first);
        m_interface->m_add_box.set_value(false);
    }
    if(m_interface->m_save.get_value())
    {
        sauver(first,doct);
        std ::  cout << "Sauvegarde Ok" << std :: endl;
        m_interface->m_save.set_value(false);
    }
    if(m_interface->m_simulation.get_value())
    {
        if(q==false)
        {
            q=true;
            m_interface->m_simulation_image.set_pic_name("Bouton_arret.jpg");
        }
        else
        {
            q=false;
            m_interface->m_simulation_image.set_pic_name("Bouton_lecture.jpg");
        }
        m_interface->m_simulation.set_value(false);

    }
    if(clk%5==0&&q==true)
    {
            first.Actualiser_Graphe(first);
            m_edges.clear();
            m_vertices.clear();
            make_graph(first);
            if (q==true)
                m_interface->m_simulation_image.set_pic_name("Bouton_arret.jpg");
            if (q==false)
                m_interface->m_simulation_image.set_pic_name("Bouton_lecture.jpg");
            std::cout << std :: endl;
            for (int i=0; i< first.m_sommet.size(); i++)
            {
                std::cout << first.m_sommet[i].m_quantite << " ";
            }
            std::cout << std :: endl;
    }

    if(m_interface->m_connexite.get_value())
    {
        m_edges.clear();
        m_vertices.clear();
        first.m_illumine.clear();
        make_graph(first);
        init_matAdj(first);
        matAdj(first);
        first.printSCCs();
        for (int i=0; i <first.m_illumine.size(); i++)
            std :: cout << first.m_illumine[i] << std :: endl;
        for (int i=0;i<first.m_illumine.size();i++)
        {
            for (auto &elt : m_vertices)
            {
                if (elt.first==11)
                    elt.second.m_interface->m_connex_box.set_bg_color(VIOLETCLAIR);
                if (elt.first==first.m_illumine[i])
                {
                    elt.second.m_interface->m_connex_box.set_bg_color(VIOLETCLAIR);
                }
            }
        }
        m_interface->m_connexite.set_value(false);
    }

    if(m_interface->m_quitter.get_value())
    {
        if(r==false)
        {
            r=true;
            m_interface->m_simulation_image.set_pic_name("Bouton_arret.jpg");
        }
        else
        {
            r=false;
            m_interface->m_simulation_image.set_pic_name("Bouton_lecture.jpg");
        }
        m_interface->m_simulation.set_value(false);
    }
    return first;
}

/// Aide � l'ajout de sommets interfac�s
void Graph::add_interfaced_vertex(int idx, double value, int x, int y,int maximum, std::string pic_name,int pic_idx)
{
    if ( m_vertices.find(idx)!=m_vertices.end() )
    {
        std::cerr << "Error adding vertex at idx=" << idx << " already used..." << std::endl;
        throw "Error adding vertex";
    }
    // Cr�ation d'une interface de sommet
    VertexInterface *vi = new VertexInterface(idx, x, y, pic_name, pic_idx);
    // Ajout de la top box de l'interface de sommet
    m_interface->m_main_box.add_child(vi->m_top_box);
    // On peut ajouter directement des vertices dans la map avec la notation crochet :
    m_vertices[idx] = Vertex(value, vi);

    m_vertices[idx].m_interface->m_slider_value.set_range(0.0,maximum);
}

/// Aide � l'ajout d'arcs interfac�s
void Graph::add_interfaced_edge(int idx, int id_vert1, int id_vert2, double weight)
{
    if ( m_edges.find(idx)!=m_edges.end())
    {
        std::cerr << "Error adding edge at idx=" << idx << " already used..." << std::endl;
        throw "Error adding edge";
    }

    if ( m_vertices.find(id_vert1)==m_vertices.end() || m_vertices.find(id_vert2)==m_vertices.end() )
    {
        std::cerr << "Error adding edge idx=" << idx << " between vertices " << id_vert1 << " and " << id_vert2 << " not in m_vertices" << std::endl;
        throw "Error adding edge";
    }

    EdgeInterface *ei = new EdgeInterface(m_vertices[id_vert1], m_vertices[id_vert2]);
    m_interface->m_main_box.add_child(ei->m_top_edge);
    m_edges[idx] = Edge(weight, ei);
    m_edges[idx].m_from = id_vert1;
    m_edges[idx].m_to = id_vert2;
    m_vertices[id_vert1].m_out.push_back(idx);
    m_vertices[id_vert2].m_in.push_back(idx);
}

/// eidx index of edge to remove
void Graph::test_remove_edge(int eidx)
{
/// r�f�rence vers le Edge � enlever
    Edge &remed=m_edges.at(eidx);

    //std::cout << "Removing edge " << eidx << " " << remed.m_from << "->" << remed.m_to << " " << remed.m_weight << std::endl;

/// Tester la coh�rence : nombre d'arc entrants et sortants des sommets 1 et 2
//    std::cout << m_vertices[remed.m_from].m_in.size() << " " << m_vertices[remed.m_from].m_out.size() << std::endl;
//    std::cout << m_vertices[remed.m_to].m_in.size() << " " << m_vertices[remed.m_to].m_out.size() << std::endl;
//    std::cout << m_edges.size() << std::endl;

/// test : on a bien des �l�ments interfac�s
    if (m_interface && remed.m_interface)
    {
/// Ne pas oublier qu'on a fait �a � l'ajout de l'arc :
        /* EdgeInterface *ei = new EdgeInterface(m_vertices[id_vert1], m_vertices[id_vert2]); */
        /* m_interface->m_main_box.add_child(ei->m_top_edge); */
        /* m_edges[idx] = Edge(weight, ei); */
/// Le new EdgeInterface ne n�cessite pas de delete car on a un shared_ptr
/// Le Edge ne n�cessite pas non plus de delete car on n'a pas fait de new (s�mantique par valeur)
/// mais il faut bien enlever le conteneur d'interface m_top_edge de l'arc de la main_box du graphe
        m_interface->m_main_box.remove_child( remed.m_interface->m_top_edge );
    }

/// Il reste encore � virer l'arc supprim� de la liste des entrants et sortants des 2 sommets to et from !
/// References sur les listes de edges des sommets from et to
    std::vector<int> &vefrom = m_vertices[remed.m_from].m_out;
    std::vector<int> &veto = m_vertices[remed.m_to].m_in;
    vefrom.erase( std::remove( vefrom.begin(), vefrom.end(), eidx ), vefrom.end() );
    veto.erase( std::remove( veto.begin(), veto.end(), eidx ), veto.end() );

/// Le Edge ne n�cessite pas non plus de delete car on n'a pas fait de new (s�mantique par valeur)
/// Il suffit donc de supprimer l'entr�e de la map pour supprimer � la fois l'Edge et le EdgeInterface
/// mais malheureusement ceci n'enlevait pas automatiquement l'interface top_edge en tant que child de main_box !
    m_edges.erase( eidx );

/// Tester la coh�rence : nombre d'arc entrants et sortants des sommets 1 et 2
//    std::cout << m_vertices[remed.m_from].m_in.size() << " " << m_vertices[remed.m_from].m_out.size() << std::endl;
//    std::cout << m_vertices[remed.m_to].m_in.size() << " " << m_vertices[remed.m_to].m_out.size() << std::endl;
//    std::cout << m_edges.size() << std::endl;

}

/// eidx index of edge to remove
void Graph::test_remove_vertex(int eidx,Graphe first)
{
    for (auto &elt : m_edges)
    {
        if (elt.second.m_from == eidx || elt.second.m_to == eidx)
        {
            test_remove_edge(elt.first);
        }
    }
/// r�f�rence vers le Vertex � enlever
    Vertex &remed=m_vertices.at(eidx);

/// test : on a bien des �l�ments interfac�sb
    if (m_interface && remed.m_interface)
    {

///il faut bien enlever le conteneur d'interface m_top_vertex de l'arc de la main_box du graphe
        m_interface->m_main_box.remove_child( remed.m_interface->m_top_box );
    }

    m_vertices.erase( eidx );
}
