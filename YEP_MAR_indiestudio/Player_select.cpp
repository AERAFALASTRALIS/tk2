/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-antoine.viala
** File description:
** Player_select
*/

#include "Player_select.hpp"
#include "Assets3DHandler.hpp"

Player_select::Player_select(int position, Graphical *graphical, Input *input)
{
    this->_position = position;
    this->_graphical = graphical;
    this->_input = input;
    this->_player_type = this->_position < 1 ? (PlayerType)(Player_select::Joueur1 + this->_position) : Player_select::robot;
    this->_chara_chosed = this->_position;
    this->createAssets();
}

Player_select::~Player_select()
{
}

void Player_select::creatbackgroundAssets()
{
    Graphical::typeTexture new_texture;

    if (this->_player_type == PlayerType::robot)
        new_texture = Graphical::SELECT_PLAYER_NAME_ROBOT;
    else if (this->_player_type == PlayerType::afk)
        new_texture = Graphical::SELECT_PLAYER_NAME_AFK;
    else
        new_texture = Graphical::SELECT_PLAYER_NAME_JOUEUR;
    // std::cout << "k         " << (Graphical::typeTexture)(new_texture) << std::endl;
    this->_asset2d_id_list.push_back(this->_graphical->get_asset2D()->create2DAsset((Graphical::typeTexture)(new_texture), SELECT_POS_X,
                                     SELECT_POS_Y - this->_graphical->get_texture_by_typeTexture(Graphical::SELECT_PLAYER_NAME_ROBOT)->getSize().Height));
    if (this->_player_type != afk) {
        // std::cout << "z         " << (Graphical::typeTexture)(Graphical::typeTexture::JOUEUR_BACKGROUND) << std::endl;
        this->_asset2d_id_list.push_back(this->_graphical->get_asset2D()->create2DAsset((Graphical::typeTexture)(Graphical::typeTexture::JOUEUR_BACKGROUND),
                                         SELECT_POS_X, SELECT_POS_Y));
    }
}

void Player_select::creatplayerAssets()
{
    if (this->_player_type != afk) {
        // std::cout << this->_graphical->get_asset3D()->getBasicMenuPosbyId(this->_position).X << " | " << this->_graphical->get_asset3D()->getBasicMenuPosbyId(this->_position).Y << " | " << this->_graphical->get_asset3D()->getBasicMenuPosbyId(this->_position).Z << std::endl;
        // std::cout << this->_graphical->get_asset3D()->getBasicMenuRotbyId(this->_position).X << " | " << this->_graphical->get_asset3D()->getBasicMenuRotbyId(this->_position).Y << " | " << this->_graphical->get_asset3D()->getBasicMenuRotbyId(this->_position).Z << std::endl;
        this->_chara_design = this->_graphical->get_asset3D()->createMeshModel3D((Graphical::typeObj)this->_position,
                                                                                 this->_graphical->get_asset3D()->getBasicMenuPosbyId(this->_position),
                                                                                 this->_graphical->get_asset3D()->getBasicMenuRotbyId(this->_position));
    }
}

void Player_select::del_asset3d() {
    // std::cout << "chara_chosed | " << this->_chara_design << std::endl;
    this->_graphical->get_asset3D()->destroyById(this->_chara_design);
    this->_asset2d_id_list.clear();
}

void Player_select::del_asset2d_list()
{
    std::list<unsigned>::iterator list_iterator;

    for (list_iterator = this->_asset2d_id_list.begin(); list_iterator != this->_asset2d_id_list.end(); ++list_iterator) {
        this->_graphical->get_asset2D()->destroy2DAsset((*list_iterator));
        list_iterator = this->_asset2d_id_list.erase(list_iterator);
    } for (list_iterator = this->_asset2d_id_list.begin(); list_iterator != this->_asset2d_id_list.end(); ++list_iterator) {
        this->_graphical->get_asset2D()->destroy2DAsset((*list_iterator));
        list_iterator = this->_asset2d_id_list.erase(list_iterator);
    } this->_asset2d_id_list.clear();
}

bool Player_select::change_par_player_select(unsigned id)
{
    // std::cout << "avant new_asset" << std::endl;
    Asset2D *new_asset = this->_graphical->get_asset2D()->getAsset2DById(id);
    // std::cout << "after new_asset" << std::endl;

    if (new_asset->type == Graphical::SELECT_FLECHE_LEFT) {
        this->_player_type = this->_player_type == robot ? (PlayerType)(Joueur1 + this->_position) : this->_player_type == afk ? robot : afk;
        return (true);
    } 
    if (new_asset->type == Graphical::SELECT_FLECHE_RIGHT) {
        this->_player_type = this->_player_type == robot ? afk : this->_player_type == afk ? (PlayerType)(Joueur1 + this->_position) : robot;
        return (true);
    }
    return (false);
}

void Player_select::stay_event()
{
    std::list<unsigned>::iterator list_it;
    Input::state_mouse_on_asset mouse_state;
    Graphical::typeTexture new_texture;
    // std::cout << "in stay_event" << std::endl;

    for (list_it = this->_asset2d_id_list.begin(); list_it != this->_asset2d_id_list.end(); ++list_it) {
        new_texture = this->_graphical->get_asset2D()->getAsset2DById((*list_it))->type;
        // std::cout << "after new_texture" << std::endl;
        if (new_texture != Graphical::SELECT_PLAYER_NAME_JOUEUR && new_texture != Graphical::SELECT_PLAYER_NAME_ROBOT && new_texture != Graphical::SELECT_PLAYER_NAME_AFK) {
            // std::cout << "avant mouse_state" << std::endl;
            mouse_state = this->_input->get_mousse_state(this->_graphical->get_asset2D()->getAsset2DById((*list_it)));
            // std::cout << "after mouse_state" << std::endl;
            if (mouse_state == Input::ON_CLICK && this->change_par_player_select((*list_it))) {
                // std::cout << "avant del_asset2D" << std::endl;
                this->del_asset2d_list();
                // std::cout << "after del_asset2D" << std::endl;
                this->createAssets();
                // std::cout << "after createassets" << std::endl;
                return;
            }
        }
    }
}

Player_select::PlayerType Player_select::get_player_type() const
{
    return (this->_player_type);
}

int Player_select::get_chara_chosed() const
{
    return (this->_chara_chosed);
}

void Player_select::creatinputAsset()
{
    Graphical::typeTexture new_texture;

    if (this->_player_type == Joueur1) {
        new_texture = Graphical::TOUCHE_J1_ZQSD;
        // std::cout << "J1 bug " << new_texture << std::endl;
    } else if (this->_player_type == Joueur2) {
        new_texture = Graphical::TOUCHE_J2_TFGH;
        // std::cout << "J2 bug " << new_texture << std::endl;
    } else if (this->_player_type == Joueur3) {
        new_texture = Graphical::TOUCHE_J3_IJKL;
        // std::cout << "J3 bug " << new_texture << std::endl;
    } else if (this->_player_type == Joueur4) {
        new_texture = Graphical::TOUCHE_J4_FLECH;
        // std::cout << "J4 bug " << new_texture << std::endl;
    } else {
        return;
    }
    // std::cout << "creatinputAsset" << std::endl;
    // std::cout << "t         " << (Graphical::typeTexture)(new_texture) << std::endl;
    // this->_asset2d_id_list.push_back(this->_graphical->get_asset2D()->create2DAsset(Graphical::TOUCHE_J1_ZQSD, SELECT_POS_X,
    //                                  SELECT_POS_Y + this->_graphical->get_texture_by_typeTexture(Graphical::JOUEUR_BACKGROUND)->getSize().Height));

    this->_asset2d_id_list.push_back(this->_graphical->get_asset2D()->create2DAsset((Graphical::typeTexture)(new_texture), SELECT_POS_X + 30,
                                     SELECT_POS_Y + this->_graphical->get_texture_by_typeTexture(Graphical::JOUEUR_BACKGROUND)->getSize().Height));
}

void Player_select::creatbuttonAsset()
{
    // std::cout << "y         " << Graphical::SELECT_FLECHE_LEFT << std::endl;
    this->_asset2d_id_list.push_back(this->_graphical->get_asset2D()->create2DAsset(Graphical::SELECT_FLECHE_LEFT,
                                     SELECT_POS_X + 10,
                                     SELECT_POS_Y - this->_graphical->get_texture_by_typeTexture(Graphical::SELECT_PLAYER_NAME_JOUEUR)->getSize().Height + 10));
    // std::cout << "i         " << Graphical::SELECT_FLECHE_RIGHT << std::endl;
    this->_asset2d_id_list.push_back(this->_graphical->get_asset2D()->create2DAsset(Graphical::SELECT_FLECHE_RIGHT,
                                     SELECT_POS_X + this->_graphical->get_texture_by_typeTexture(Graphical::SELECT_PLAYER_NAME_JOUEUR)->getSize().Width -
                                     this->_graphical->get_texture_by_typeTexture(Graphical::SELECT_FLECHE_RIGHT)->getSize().Width - 10,
                                     SELECT_POS_Y - this->_graphical->get_texture_by_typeTexture(Graphical::SELECT_PLAYER_NAME_JOUEUR)->getSize().Height + 10));
}

void Player_select::createAssets()
{
    if (this->_chara_design != -1 && this->_player_type == 5) {
        this->_graphical->get_asset3D()->destroyById(this->_chara_design);
        this->_chara_design = -1;
    }
    this->creatbackgroundAssets();
    if (this->_chara_design == -1)
        this->creatplayerAssets();
    this->creatinputAsset();
    this->creatbuttonAsset();
}
