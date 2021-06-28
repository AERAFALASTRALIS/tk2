/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-antoine.viala
** File description:
** Player_select
*/

#include "Graphical_game.hpp"
#include "Assets3DHandler.hpp"
#include "Assets2DHandler.hpp"
#include "Input.hpp"
// #include "Chara_in_game.hpp"
#include <iostream>

Graphical_game::Graphical_game(Graphical *graphical, Parametre *parametre, int nbrobot)
{   
    this->_graphical = graphical;
    this->_parametre = parametre;
    this->_input = graphical->get_input();
    timer = _graphical->getdevice()->getTimer();
    this->result = timer->getTime();
    this->pos.X = -150;
    this->pos.Y = 140;
    this->pos.Z = 0;
    this->posX = 100;
    this->posY = 0;
    this->posM.X = -200;
    this->posM.Y = 170;
    this->posM.Z = 0;
    this->posB.X = -80;
    this->posB.Y = 90;
    this->posB.Z = 0;

    this->_nb_player = 0;
    this->_nb_in_list = 1;
    this->_ammo[Graphical::typeObj::JOUEUR1] = 1;
    this->_ammo[Graphical::typeObj::JOUEUR2] = 1;
    this->_ammo[Graphical::typeObj::JOUEUR3] = 1;
    this->_ammo[Graphical::typeObj::JOUEUR4] = 1;
    this->_boom[Graphical::typeObj::JOUEUR1] = 0;
    this->_boom[Graphical::typeObj::JOUEUR2] = 0;
    this->_boom[Graphical::typeObj::JOUEUR3] = 0;
    this->_boom[Graphical::typeObj::JOUEUR4] = 0;
    this->_povX[Graphical::typeObj::JOUEUR1] = 0;
    this->_povX[Graphical::typeObj::JOUEUR2] = 0;
    this->_povX[Graphical::typeObj::JOUEUR3] = 0;
    this->_povX[Graphical::typeObj::JOUEUR4] = 0;
    this->_povY[Graphical::typeObj::JOUEUR1] = 0;
    this->_povY[Graphical::typeObj::JOUEUR2] = 0;
    this->_povY[Graphical::typeObj::JOUEUR3] = 0;
    this->_povY[Graphical::typeObj::JOUEUR4] = 0;
    this->_hp[Graphical::typeObj::JOUEUR1] = 1;
    this->_hp[Graphical::typeObj::JOUEUR2] = 1;
    this->_hp[Graphical::typeObj::JOUEUR3] = 1;
    this->_hp[Graphical::typeObj::JOUEUR4] = 1;
    this->_boom_pos[Graphical::typeObj::JOUEUR1] = irr::core::vector3df(0, 0, 0);
    this->_boom_pos[Graphical::typeObj::JOUEUR2] = irr::core::vector3df(0, 0, 0);
    this->_boom_pos[Graphical::typeObj::JOUEUR3] = irr::core::vector3df(0, 0, 0);
    this->_boom_pos[Graphical::typeObj::JOUEUR4] = irr::core::vector3df(0, 0, 0);
    this->_map_start_pos[Graphical::typeObj::JOUEUR1] = irr::core::vector3df(-160, 149, -1);
    this->_map_start_pos[Graphical::typeObj::JOUEUR2] = irr::core::vector3df(-160, -170, -1);
    this->_map_start_pos[Graphical::typeObj::JOUEUR3] = irr::core::vector3df(160, 149, -1);
    this->_map_start_pos[Graphical::typeObj::JOUEUR4] = irr::core::vector3df(160, -170, -1);
    this->_map_old_pos[Graphical::typeObj::JOUEUR1] = irr::core::vector3df(-160, 149, -1);
    this->_map_old_pos[Graphical::typeObj::JOUEUR2] = irr::core::vector3df(-160, -170, -1);
    this->_map_old_pos[Graphical::typeObj::JOUEUR3] = irr::core::vector3df(150, 150, -1);
    this->_map_old_pos[Graphical::typeObj::JOUEUR4] = irr::core::vector3df(150, -150, -1);
    // this->_parametre->get_Player_config_list()[]
    for (struct Player_config *player_config: this->_parametre->get_Player_config_list()) {
        if (this->_nb_in_list == 1) {
            if ((*player_config).robot == false) {
                create_player(Graphical::typeObj::JOUEUR1, *player_config);
                this->_nb_player = this->_nb_player + 1;
                this->_map_what_player[this->_nb_player] = Graphical::typeObj::JOUEUR1;
                this->_type_robot[Graphical::typeObj::JOUEUR1] = false;
            }
            if ((*player_config).robot == true) {
                this->_map_robot_typeObj_id[Graphical::typeObj::ROBOT1] = this->_graphical->get_asset3D()->createMeshModel3D((*player_config).model_chara, this->_map_start_pos[Graphical::typeObj::JOUEUR1], irr::core::vector3df(-90, 0, 0));
                this->_type_robot[Graphical::typeObj::JOUEUR1] = true;
            }
        } else if (this->_nb_in_list == 2) {
            if ((*player_config).robot == false) {
                create_player(Graphical::typeObj::JOUEUR2, *player_config);
                this->_nb_player = this->_nb_player + 1;
                this->_map_what_player[this->_nb_player] = Graphical::typeObj::JOUEUR2;
                this->_type_robot[Graphical::typeObj::JOUEUR2] = false;
            }
            if ((*player_config).robot == true) {
                this->_map_robot_typeObj_id[Graphical::typeObj::ROBOT2] = this->_graphical->get_asset3D()->createMeshModel3D((*player_config).model_chara, this->_map_start_pos[Graphical::typeObj::JOUEUR2], irr::core::vector3df(-90, 0, 0));
                this->_type_robot[Graphical::typeObj::JOUEUR2] = true;
            }
        }
        else if (this->_nb_in_list == 3) {
            if ((*player_config).robot == false) {
                create_player(Graphical::typeObj::JOUEUR3, *player_config);
                this->_nb_player = this->_nb_player + 1;
                this->_map_what_player[this->_nb_player] = Graphical::typeObj::JOUEUR3;
                this->_type_robot[Graphical::typeObj::JOUEUR3] = false;
            }
            if ((*player_config).robot == true) {
                this->_map_robot_typeObj_id[Graphical::typeObj::ROBOT3] = this->_graphical->get_asset3D()->createMeshModel3D((*player_config).model_chara, this->_map_start_pos[Graphical::typeObj::JOUEUR3], irr::core::vector3df(-90, 0, 0));
                this->_type_robot[Graphical::typeObj::JOUEUR3] = true;
            }
        }
        else if (this->_nb_in_list == 4) {
            if ((*player_config).robot == false) {
                create_player(Graphical::typeObj::JOUEUR4, *player_config);
                this->_nb_player = this->_nb_player + 1;
                this->_map_what_player[this->_nb_player] = Graphical::typeObj::JOUEUR4;
                this->_type_robot[Graphical::typeObj::JOUEUR4] = false;
            }
            if ((*player_config).robot == true) {
                this->_map_robot_typeObj_id[Graphical::typeObj::ROBOT4] = this->_graphical->get_asset3D()->createMeshModel3D((*player_config).model_chara, this->_map_start_pos[Graphical::typeObj::JOUEUR4], irr::core::vector3df(-90, 0, 0));
                this->_type_robot[Graphical::typeObj::JOUEUR4] = true;
            }
        }
        this->_nb_in_list = this->_nb_in_list + 1;
    }

    // int nb_player_robot = this->_nb_in_list + nbrobot;
    // for (int nb_player_robot = this->_nb_in_list + nbrobot; nb_player_robot < 5; nb_player_robot = nb_player_robot + 1) {
    //     if (nb_player_robot == 2)
    //     this->_map_robot_typeObj_id[Graphical::typeObj::ROBOT1] = this->_graphical->get_asset3D()->createMeshModel3D(player_config.model_chara, this->_map_start_pos[Graphical::typeObj::JOUEUR1], irr::core::vector3df(-90, 0, 0));
    // }
}

Graphical_game::~Graphical_game()
{
}

bool Graphical_game::placeBox()
{
    int i = rand() % 100;
    if (i >= 30) {
        return (true);
    } else {
        return (false);
    }
}

void Graphical_game::create_player(Graphical::typeObj arg1, Player_config player_config)
{
    if (arg1 == Graphical::typeObj::JOUEUR1) {
        this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR1] = this->_graphical->get_asset3D()->createMeshModel3D(player_config.model_chara, this->_map_start_pos[Graphical::typeObj::JOUEUR1], irr::core::vector3df(-90, 0, 0));
        this->_map_player_typeObj_Player_config[Graphical::typeObj::JOUEUR1] = player_config;
    } if (arg1 == Graphical::typeObj::JOUEUR2) {
        this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR2] = this->_graphical->get_asset3D()->createMeshModel3D(player_config.model_chara, this->_map_start_pos[Graphical::typeObj::JOUEUR2], irr::core::vector3df(-90, 0, 0));
        this->_map_player_typeObj_Player_config[Graphical::typeObj::JOUEUR2] = player_config;
    } if (arg1 == Graphical::typeObj::JOUEUR3) {
        this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR3] = this->_graphical->get_asset3D()->createMeshModel3D(player_config.model_chara, this->_map_start_pos[Graphical::typeObj::JOUEUR3], irr::core::vector3df(-90, 0, 0));
        this->_map_player_typeObj_Player_config[Graphical::typeObj::JOUEUR3] = player_config;
    } if (arg1 == Graphical::typeObj::JOUEUR4) {
        this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR4] = this->_graphical->get_asset3D()->createMeshModel3D(player_config.model_chara, this->_map_start_pos[Graphical::typeObj::JOUEUR4], irr::core::vector3df(-90, 0, 0));
        this->_map_player_typeObj_Player_config[Graphical::typeObj::JOUEUR4] = player_config;
    }
}

void Graphical_game::create_game_asset()
{
    srand((unsigned int)time(NULL));
    this->_list_pause.push_back(this->_graphical->get_asset2D()->create2DAsset(Graphical::MAIN_MENU_BACKGROUD, 0, 0));
    this->_list_pause.push_back(this->_graphical->get_asset2D()->create2DAsset(Graphical::PAUSE_TITLE, (SCREEN_WIDTH / 2) - this->_graphical->get_texture_by_typeTexture(Graphical::PAUSE_TITLE)->getSize().Width, (SCREEN_HEIGHT / 2 ) - this->_graphical->get_texture_by_typeTexture(Graphical::PAUSE_TITLE)->getSize().Height));
    this->background.push_back(this->_graphical->get_asset2D()->create2DAsset(Graphical::MAIN_MENU_BACKGROUD, 0, 0));
    //caisse (cassable)
    for (int i = 0; i < 3; i++) {
        for (int x = 0; x < 9; x++) {
            if (placeBox() == true) {
                this->_asset3d_id_list = this->_graphical->get_asset3D()->createMeshModel3D(Graphical::BOITE1, irr::core::vector3df(posB.X+(i*80), 130-(x*40), posB.Z), irr::core::vector3df(0, 0, 0));
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int x = 0; x < 9; x++) {
            if (placeBox() == true) {
                this->_asset3d_id_list = this->_graphical->get_asset3D()->createMeshModel3D(Graphical::BOITE1, irr::core::vector3df(-160+(x*40), posB.Y-40-(i*80), posB.Z), irr::core::vector3df(0, 0, 0));
            }
        }
    }
    //sol
    for (int i = 0; i < 11; i++) {
        for (int x = 0; x < 11; x++) {
             this->_asset3d_id_list = this->_graphical->get_asset3D()->createMeshModel3D(Graphical::SOL1, irr::core::vector3df(posM.X + (x*40), posM.Y-(i*40), posM.Z+80), irr::core::vector3df(0, 0, 0));
        }
    }
    //mur du haut
    for (int i = 0; i < 11; i++) {
        this->_asset3d_id_list = this->_graphical->get_asset3D()->createMeshModel3D(Graphical::STAGE1, irr::core::vector3df(posM.X + (i*40), posM.Y, posM.Z), irr::core::vector3df(0, 0, 0));
    }
    //murs du milieu + bloc (non cassable)
    for (int i = 1; i < 10; i++) {
        if ((i % 2) == 0) {
            for (int x = 0; x < 6; x++) {
                this->_asset3d_id_list = this->_graphical->get_asset3D()->createMeshModel3D(Graphical::STAGE1, irr::core::vector3df(posM.X + (x * 80), posM.Y-(i*40), posM.Z), irr::core::vector3df(0, 0, 0));
            }
        } else {
            this->_asset3d_id_list = this->_graphical->get_asset3D()->createMeshModel3D(Graphical::STAGE1, irr::core::vector3df(posM.X, posM.Y - (i * 40), posM.Z), irr::core::vector3df(0, 0, 0));
            this->_asset3d_id_list = this->_graphical->get_asset3D()->createMeshModel3D(Graphical::STAGE1, irr::core::vector3df(posM.X +400, posM.Y - (i * 40), posM.Z), irr::core::vector3df(0, 0, 0));
        }
    }
    //mur d'en bas
    for (int i = 0; i < 11; i++) {
        this->_asset3d_id_list = this->_graphical->get_asset3D()->createMeshModel3D(Graphical::STAGE1, irr::core::vector3df(posM.X + (i*40), posM.Y-400, posM.Z), irr::core::vector3df(0, 0, 0));
    }
    /* Pour chercher l'ID en fonction de la pos
    irr::core::vector3df A;
    for (int i = 1; i < 100; i++) {
        A = this->_graphical->get_asset3D()->getPositionById(i);
        std::cout << "ID " << i << " : " << A.X << " X | " << A.Y << " Y | " << A.Z << " Z" << std::endl;
    }
    */
}

bool Graphical_game::isBlocked_Up(irr::core::vector3df pos)
{
    irr::core::vector3df bloc;
    int max = this->_graphical->get_asset3D()->getIndex();

    for (int x = 0; x <= max; x++) {
        bloc = this->_graphical->get_asset3D()->getPositionById(x);
        if (bloc.Z == 0 && bloc.Y == (int)bloc.Y) {
            if (pos.Y+21 >= bloc.Y && pos.Y < bloc.Y &&
            ((pos.X+7 >= bloc.X && pos.X+7 <= bloc.X+40) ||
            (pos.X+30 >= bloc.X && pos.X+30 <= bloc.X+40))) {
                return (true);
            }
        } else if (bloc.Z == -1) {
            if (pos.Y+21 >= bloc.Y && pos.Y < bloc.Y &&
            ((pos.X+7 >= bloc.X && pos.X+7 <= bloc.X+30) ||
            (pos.X+30 >= bloc.X && pos.X+30 <= bloc.X+30))) {
                return (true);
            }
        }
    }
    return (false);
}

bool Graphical_game::isBlocked_Down(irr::core::vector3df pos)
{
    irr::core::vector3df bloc;
    int max = this->_graphical->get_asset3D()->getIndex();

    for (int x = 0; x <= max; x++) {
        bloc = this->_graphical->get_asset3D()->getPositionById(x);
        if (bloc.Z == 0 && bloc.Y == (int)bloc.Y) {
            if (bloc.Y+60 >= pos.Y && pos.Y > bloc.Y+40 &&
            ((pos.X+7 >= bloc.X && pos.X+7 <= bloc.X+40) ||
            (pos.X+30 >= bloc.X && pos.X+30 <= bloc.X+40))) {
                return (true);
            }
        } else if (bloc.Z == -1) {
            if (bloc.Y+25 >= pos.Y && pos.Y > bloc.Y &&
            ((pos.X+7 >= bloc.X && pos.X+7 <= bloc.X+40) ||
            (pos.X+30 >= bloc.X && pos.X+30 <= bloc.X+40))) {
                return (true);
            }
        }
    }
    return (false);
}

bool Graphical_game::isBlocked_Left(irr::core::vector3df pos)
{
    irr::core::vector3df bloc;
    int max = this->_graphical->get_asset3D()->getIndex();

    for (int x = 0; x <= max; x++) {
        bloc = this->_graphical->get_asset3D()->getPositionById(x);
        if (bloc.Z == 0 && bloc.Y == (int)bloc.Y) {
            if (pos.X <= bloc.X+40 && pos.X > bloc.X &&
            ((pos.Y-5 >= bloc.Y && pos.Y-5 <= bloc.Y+40) ||
            (pos.Y+15 >= bloc.Y && pos.Y+15 <= bloc.Y+40))) {
                return (true);
            }
        } else if (bloc.Z == -1) {
            if (pos.X <= bloc.X+40 && pos.X > bloc.X &&
            ((pos.Y-5 >= bloc.Y && pos.Y-5 <= bloc.Y+25) ||
            (pos.Y+15 >= bloc.Y && pos.Y+15 <= bloc.Y+25))) {
                return (true);
            }
        }
    }
    return (false);
}

bool Graphical_game::isBlocked_Right(irr::core::vector3df pos)
{
    irr::core::vector3df bloc;
    int max = this->_graphical->get_asset3D()->getIndex();

    for (int x = 0; x <= max; x++) {
        bloc = this->_graphical->get_asset3D()->getPositionById(x);
        if (bloc.Z == 0 && bloc.Y == (int)bloc.Y) {
            if (pos.X+40 >= bloc.X && pos.X < bloc.X &&
            ((pos.Y-5 >= bloc.Y && pos.Y-5 <= bloc.Y+25) ||
            (pos.Y+15 >= bloc.Y && pos.Y+15 <= bloc.Y+25))) {
                return (true);
            }
        } else if (bloc.Z == -1) {
            if (pos.X+40 >= bloc.X && pos.X < bloc.X &&
            ((pos.Y-5 >= bloc.Y && pos.Y-5 <= bloc.Y+25) ||
            (pos.Y+15 >= bloc.Y && pos.Y+15 <= bloc.Y+25))) {
                return (true);
            }            
        }
    }
    return (false);
}

void Graphical_game::killPlayerByPos(irr::core::vector3df pos)
{
    irr::core::vector3df bomb;
    unsigned P1 = this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR1];
    unsigned P2 = this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR2];
    unsigned P3 = this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR3];
    unsigned P4 = this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR4];
    irr::core::vector3df pos1 = this->_graphical->get_asset3D()->getPositionById(P1);
    pos1.Z = pos1.Z + 200;
    irr::core::vector3df pos2 = this->_graphical->get_asset3D()->getPositionById(P2);
    pos2.Z = pos2.Z + 200;
    irr::core::vector3df pos3 = this->_graphical->get_asset3D()->getPositionById(P3);
    pos3.Z = pos3.Z + 200;
    irr::core::vector3df pos4 = this->_graphical->get_asset3D()->getPositionById(P4);
    pos4.Z = pos4.Z + 200;

    if (this->_graphical->get_asset3D()->getPositionById(P1) == pos) {
        this->_hp[Graphical::typeObj::JOUEUR1] = 0;
        this->_graphical->get_asset3D()->setPositionbyId(pos1, P1);
    }
    if (this->_graphical->get_asset3D()->getPositionById(P2) == pos) {
        this->_hp[Graphical::typeObj::JOUEUR2] = 0;
        this->_graphical->get_asset3D()->setPositionbyId(pos2, P2);
    }
    if (this->_graphical->get_asset3D()->getPositionById(P3) == pos) {
        this->_hp[Graphical::typeObj::JOUEUR3] = 0;
        this->_graphical->get_asset3D()->setPositionbyId(pos3, P3);
    }
    if (this->_graphical->get_asset3D()->getPositionById(P4) == pos) {
        this->_hp[Graphical::typeObj::JOUEUR4] = 0;
        this->_graphical->get_asset3D()->setPositionbyId(pos4, P4);
    }
}

void Graphical_game::checkDamage(irr::core::vector3df pos)
{
    irr::core::vector3df bomb;
    int max = this->_graphical->get_asset3D()->getIndex();


    for (int x = 0; x <= max; x++) {
        bomb = this->_graphical->get_asset3D()->getPositionById(x);
        // Up Damage
        if (pos.Y+40 == bomb.Y &&
        bomb.X == pos.X &&
        this->_graphical->get_asset3D()->getStateById(x) == 1) {
            this->_graphical->get_asset3D()->destroyById(x);
        }
        // Down Damage
        if (pos.Y-40 == bomb.Y &&
        bomb.X == pos.X &&
        this->_graphical->get_asset3D()->getStateById(x) == 1) {
            this->_graphical->get_asset3D()->destroyById(x);
        }
        // Right Damage
        if (pos.X+40 == bomb.X &&
        bomb.Y == pos.Y &&
        this->_graphical->get_asset3D()->getStateById(x) == 1) {
            this->_graphical->get_asset3D()->destroyById(x);
        }
        // Up Damage
        if (pos.X-40 == bomb.X &&
        bomb.Y == pos.Y &&
        this->_graphical->get_asset3D()->getStateById(x) == 1) {
            this->_graphical->get_asset3D()->destroyById(x);
        }
        // Up Damage Player
        if (bomb.Y >= pos.Y && bomb.Y <= pos.Y + 100 &&
        bomb.X+20 >= pos.X && bomb.X+20 <= pos.X +40 &&
        this->_graphical->get_asset3D()->getStateById(x) == 2) {
            killPlayerByPos(bomb);
        }
        // Down Damage Player
        if (bomb.Y+10 >= pos.Y-40 && bomb.Y+10 <= pos.Y+40 &&
        bomb.X+20 >= pos.X && bomb.X+20 <= pos.X +40 &&
        this->_graphical->get_asset3D()->getStateById(x) == 2) {
            killPlayerByPos(bomb);
        }
        // Right Damage Player
        if (bomb.X+20 >= pos.X && bomb.X+10 <= pos.X + 80 &&
        bomb.Y-5 >= pos.Y && bomb.Y-5 <= pos.Y+40 &&
        this->_graphical->get_asset3D()->getStateById(x) == 2) {
            killPlayerByPos(bomb);
        }
        // Left Damage Player
        if (bomb.X+20 <= pos.X+40 && bomb.X+10 >= pos.X-40 &&
        bomb.Y-5 >= pos.Y && bomb.Y-5 <= pos.Y+40 &&
        this->_graphical->get_asset3D()->getStateById(x) == 2) {
            killPlayerByPos(bomb);
        }
    }
}

void Graphical_game::destroyBomb(irr::core::vector3df pos)
{
    irr::core::vector3df bomb;
    int max = this->_graphical->get_asset3D()->getIndex();

    for (int x = 0; x <= max; x++) {
        bomb = this->_graphical->get_asset3D()->getPositionById(x);
        if (bomb.X == pos.X && bomb.Y == pos.Y && bomb.Z == pos.Z &&
        this->_graphical->get_asset3D()->getStateById(x) == 3) {
            this->_graphical->get_asset3D()->destroyById(x);
            return;
        }
    }
}

void Graphical_game::deplacement()
{
    // std::map<std::string, bool> inputs = this->_input->get_all_input();

    // for (Chara_in_game &player : this->_vector_player) {
    //     player.set_anim(anim::AFK);
    //     if (inputs[player.get_map_key()[key_for_player::UP]] == true && player.get_pos().Y < 140) {
    //         player.move_player(direction::UP_D);
    //     } if (inputs[player.get_map_key()[key_for_player::DOWN]] == true && player.get_pos().Y > -230) {
    //         player.move_player(direction::DOWN_D);
    //     } if (inputs[player.get_map_key()[key_for_player::LEFT]] == true && player.get_pos().X < 410) {
    //         player.move_player(direction::LEFT_D);
    //     } if (inputs[player.get_map_key()[key_for_player::RIGHT]] == true && player.get_pos().X > -410) {
    //         player.move_player(direction::RIGHT_D);
    //     } if (this->timer->getTime() - this->result >= 1) {

            // if (player.get_pos().Y == player.get_old_pos().Y && player.get_pos().X == player.get_old_pos().X) {
            //     player.set_anim(anim::AFK);
            // } else {
            //     player.set_pos()
            // }
    //     }
    // }

    // if (inputs[this->_map_player_typeObj_Player_config[Graphical::typeObj::JOUEUR1].key[key_for_player::UP]] == true &&
    //     this->_graphical->get_asset3D()->getPositionById(this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR1]).Y < 140)

    irr::core::vector3df tnt;
    tnt.Z = 0;
    int t;

    if (this->_input->get_input("z") == true && this->_type_robot[Graphical::typeObj::JOUEUR1] == false &&
    this->_hp[Graphical::typeObj::JOUEUR1] == 1) { // J1
        this->_graphical->get_asset3D()->setRotationbyId(irr::core::vector3df(-90, 0, 180), this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR1]);
        this->_povX[Graphical::typeObj::JOUEUR1] = 0;
        this->_povY[Graphical::typeObj::JOUEUR1] = -20;
        if (isBlocked_Up(this->_map_start_pos[Graphical::typeObj::JOUEUR1]) == false)
            this->_map_start_pos[Graphical::typeObj::JOUEUR1].Y = this->_map_start_pos[Graphical::typeObj::JOUEUR1].Y + 1;
    }
    if (this->_input->get_input("s") == true && this->_type_robot[Graphical::typeObj::JOUEUR1] == false &&
    this->_hp[Graphical::typeObj::JOUEUR1] == 1) {
        this->_graphical->get_asset3D()->setRotationbyId(irr::core::vector3df(-90, 0, 0), this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR1]);
        this->_povX[Graphical::typeObj::JOUEUR1] = 0;
        this->_povY[Graphical::typeObj::JOUEUR1] = 0;
        if (isBlocked_Down(this->_map_start_pos[Graphical::typeObj::JOUEUR1]) == false)
            this->_map_start_pos[Graphical::typeObj::JOUEUR1].Y = this->_map_start_pos[Graphical::typeObj::JOUEUR1].Y - 1;
    }
    if (this->_input->get_input("q") == true && this->_type_robot[Graphical::typeObj::JOUEUR1] == false &&
    this->_hp[Graphical::typeObj::JOUEUR1] == 1) {
        this->_graphical->get_asset3D()->setRotationbyId(irr::core::vector3df(-90, 0, 270), this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR1]);
        this->_povX[Graphical::typeObj::JOUEUR1] = 40;
        this->_povY[Graphical::typeObj::JOUEUR1] = 0;
        if (isBlocked_Left(this->_map_start_pos[Graphical::typeObj::JOUEUR1]) == false)
            this->_map_start_pos[Graphical::typeObj::JOUEUR1].X = this->_map_start_pos[Graphical::typeObj::JOUEUR1].X - 1;
    }
    if (this->_input->get_input("d") == true && this->_type_robot[Graphical::typeObj::JOUEUR1] == false &&
    this->_hp[Graphical::typeObj::JOUEUR1] == 1) {
        this->_graphical->get_asset3D()->setRotationbyId(irr::core::vector3df(-90, 0, 90), this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR1]);
        this->_povX[Graphical::typeObj::JOUEUR1] = 5;
        this->_povY[Graphical::typeObj::JOUEUR1] = 0;
        if (isBlocked_Right(this->_map_start_pos[Graphical::typeObj::JOUEUR1]) == false)
            this->_map_start_pos[Graphical::typeObj::JOUEUR1].X = this->_map_start_pos[Graphical::typeObj::JOUEUR1].X + 1;
    }
    if (this->_ammo[Graphical::typeObj::JOUEUR1] == 1) {
        if (this->_input->get_input("e") == true && this->_type_robot[Graphical::typeObj::JOUEUR1] == false) {
            this->_boom[Graphical::typeObj::JOUEUR1] = timer->getTime();
            this->_ammo[Graphical::typeObj::JOUEUR1] = 0;
            t = this->_map_start_pos[Graphical::typeObj::JOUEUR1].X + this->_povX[Graphical::typeObj::JOUEUR1];
            if (t % 40 != 0) {
                tnt.X = (t < 0) ? (t / 40 * 40 - 40) : (t / 40 * 40);
            } else {
                tnt.X = t / 40 * 40;
            }
            t = this->_map_start_pos[Graphical::typeObj::JOUEUR1].Y + this->_povY[Graphical::typeObj::JOUEUR1];
            if (t % 40 != 0) {
                tnt.Y = (t < 0) ? (t / 40 * 40 - 30) : (t / 40 * 40 + 10);
            } else {
                tnt.Y = t / 40 * 40 + 10;
            }
            this->_boom_pos[Graphical::typeObj::JOUEUR1] = tnt;
            this->_asset3d_id_list = this->_graphical->get_asset3D()->createMeshModel3D(Graphical::BOMBE1, tnt, irr::core::vector3df(0, 0, 0));
        }
    } else if (this->_ammo[Graphical::typeObj::JOUEUR1] == 0 && (this->timer->getTime() - this->_boom[Graphical::typeObj::JOUEUR1]) >= 2000) {
        this->_ammo[Graphical::typeObj::JOUEUR1] = 1;
        checkDamage(this->_boom_pos[Graphical::typeObj::JOUEUR1]);
        destroyBomb(this->_boom_pos[Graphical::typeObj::JOUEUR1]);
    }

    if (this->_input->get_input("t") == true && this->_type_robot[Graphical::typeObj::JOUEUR2] == false &&
    this->_hp[Graphical::typeObj::JOUEUR2] == 1) { //J2
        this->_graphical->get_asset3D()->setRotationbyId(irr::core::vector3df(-90, 0, 180), this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR2]);
        this->_povX[Graphical::typeObj::JOUEUR2] = 0;
        this->_povY[Graphical::typeObj::JOUEUR2] = -20;
        if (isBlocked_Up(this->_map_start_pos[Graphical::typeObj::JOUEUR2]) == false)
            this->_map_start_pos[Graphical::typeObj::JOUEUR2].Y = this->_map_start_pos[Graphical::typeObj::JOUEUR2].Y + 1;
    }
    if (this->_input->get_input("g") == true && this->_type_robot[Graphical::typeObj::JOUEUR2] == false &&
    this->_hp[Graphical::typeObj::JOUEUR2] == 1) {
        this->_graphical->get_asset3D()->setRotationbyId(irr::core::vector3df(-90, 0, 0), this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR2]);
        this->_povX[Graphical::typeObj::JOUEUR2] = 0;
        this->_povY[Graphical::typeObj::JOUEUR2] = 0;
        if (isBlocked_Down(this->_map_start_pos[Graphical::typeObj::JOUEUR2]) == false)
            this->_map_start_pos[Graphical::typeObj::JOUEUR2].Y = this->_map_start_pos[Graphical::typeObj::JOUEUR2].Y - 1;
    }
    if (this->_input->get_input("f") == true && this->_type_robot[Graphical::typeObj::JOUEUR2] == false &&
    this->_hp[Graphical::typeObj::JOUEUR2] == 1) {
        this->_graphical->get_asset3D()->setRotationbyId(irr::core::vector3df(-90, 0, 270), this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR2]);
        this->_povX[Graphical::typeObj::JOUEUR2] = 40;
        this->_povY[Graphical::typeObj::JOUEUR2] = 0;
        if (isBlocked_Left(this->_map_start_pos[Graphical::typeObj::JOUEUR2]) == false)
            this->_map_start_pos[Graphical::typeObj::JOUEUR2].X = this->_map_start_pos[Graphical::typeObj::JOUEUR2].X - 1;
    }
    if (this->_input->get_input("h") == true && this->_type_robot[Graphical::typeObj::JOUEUR2] == false &&
    this->_hp[Graphical::typeObj::JOUEUR2] == 1) {
        this->_graphical->get_asset3D()->setRotationbyId(irr::core::vector3df(-90, 0, 90), this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR2]);
        this->_povX[Graphical::typeObj::JOUEUR2] = 5;
        this->_povY[Graphical::typeObj::JOUEUR2] = 0;
        if (isBlocked_Right(this->_map_start_pos[Graphical::typeObj::JOUEUR2]) == false)
            this->_map_start_pos[Graphical::typeObj::JOUEUR2].X = this->_map_start_pos[Graphical::typeObj::JOUEUR2].X + 1;
    }
    if (this->_ammo[Graphical::typeObj::JOUEUR2] == 1) {
        if (this->_input->get_input("y") == true && this->_type_robot[Graphical::typeObj::JOUEUR2] == false) {
            this->_boom[Graphical::typeObj::JOUEUR2] = timer->getTime();
            this->_ammo[Graphical::typeObj::JOUEUR2] = 0;
            t = this->_map_start_pos[Graphical::typeObj::JOUEUR2].X + this->_povX[Graphical::typeObj::JOUEUR2];
            if (t % 40 != 0) {
                tnt.X = (t < 0) ? (t / 40 * 40 - 40) : (t / 40 * 40);
            } else {
                tnt.X = t / 40 * 40;
            }
            t = this->_map_start_pos[Graphical::typeObj::JOUEUR2].Y + this->_povY[Graphical::typeObj::JOUEUR2];
            if (t % 40 != 0) {
                tnt.Y = (t < 0) ? (t / 40 * 40 - 30) : (t / 40 * 40 + 10);
            } else {
                tnt.Y = t / 40 * 40 + 10;
            }
            this->_boom_pos[Graphical::typeObj::JOUEUR2] = tnt;
            this->_asset3d_id_list = this->_graphical->get_asset3D()->createMeshModel3D(Graphical::BOMBE1, tnt, irr::core::vector3df(0, 0, 0));
        }
    } else if (this->_ammo[Graphical::typeObj::JOUEUR2] == 0 && (this->timer->getTime() - this->_boom[Graphical::typeObj::JOUEUR2]) >= 2000) {
        this->_ammo[Graphical::typeObj::JOUEUR2] = 1;
        checkDamage(this->_boom_pos[Graphical::typeObj::JOUEUR2]);
        destroyBomb(this->_boom_pos[Graphical::typeObj::JOUEUR2]);
    }  

    if (this->_input->get_input("i") == true && this->_type_robot[Graphical::typeObj::JOUEUR3] == false &&
    this->_hp[Graphical::typeObj::JOUEUR3] == 1) { // J3
        this->_graphical->get_asset3D()->setRotationbyId(irr::core::vector3df(-90, 0, 180), this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR3]);
        this->_povX[Graphical::typeObj::JOUEUR3] = 0;
        this->_povY[Graphical::typeObj::JOUEUR3] = -20;
        if (isBlocked_Up(this->_map_start_pos[Graphical::typeObj::JOUEUR3]) == false)
            this->_map_start_pos[Graphical::typeObj::JOUEUR3].Y = this->_map_start_pos[Graphical::typeObj::JOUEUR3].Y + 1;
    }
    if (this->_input->get_input("k") == true && this->_type_robot[Graphical::typeObj::JOUEUR3] == false &&
    this->_hp[Graphical::typeObj::JOUEUR3] == 1) {
        this->_graphical->get_asset3D()->setRotationbyId(irr::core::vector3df(-90, 0, 0), this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR3]);
        this->_povX[Graphical::typeObj::JOUEUR3] = 0;
        this->_povY[Graphical::typeObj::JOUEUR3] = 0;
        if (isBlocked_Down(this->_map_start_pos[Graphical::typeObj::JOUEUR3]) == false)
            this->_map_start_pos[Graphical::typeObj::JOUEUR3].Y = this->_map_start_pos[Graphical::typeObj::JOUEUR3].Y - 1;
    }
    if (this->_input->get_input("j") == true && this->_type_robot[Graphical::typeObj::JOUEUR3] == false &&
    this->_hp[Graphical::typeObj::JOUEUR3] == 1) {
        this->_graphical->get_asset3D()->setRotationbyId(irr::core::vector3df(-90, 0, 270), this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR3]);
        this->_povX[Graphical::typeObj::JOUEUR3] = 40;
        this->_povY[Graphical::typeObj::JOUEUR3] = 0;
        if (isBlocked_Left(this->_map_start_pos[Graphical::typeObj::JOUEUR3]) == false)
            this->_map_start_pos[Graphical::typeObj::JOUEUR3].X = this->_map_start_pos[Graphical::typeObj::JOUEUR3].X - 1;
    }
    if (this->_input->get_input("l") == true && this->_type_robot[Graphical::typeObj::JOUEUR3] == false &&
    this->_hp[Graphical::typeObj::JOUEUR3] == 1) {
        this->_graphical->get_asset3D()->setRotationbyId(irr::core::vector3df(-90, 0, 90), this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR3]);
        this->_povX[Graphical::typeObj::JOUEUR3] = 5;
        this->_povY[Graphical::typeObj::JOUEUR3] = 0;
        if (isBlocked_Right(this->_map_start_pos[Graphical::typeObj::JOUEUR3]) == false)
            this->_map_start_pos[Graphical::typeObj::JOUEUR3].X = this->_map_start_pos[Graphical::typeObj::JOUEUR3].X + 1;
    }
    if (this->_ammo[Graphical::typeObj::JOUEUR3] == 1) {
        if (this->_input->get_input("o") == true && this->_type_robot[Graphical::typeObj::JOUEUR3] == false) {
            this->_boom[Graphical::typeObj::JOUEUR3] = timer->getTime();
            this->_ammo[Graphical::typeObj::JOUEUR3] = 0;
            t = this->_map_start_pos[Graphical::typeObj::JOUEUR3].X + this->_povX[Graphical::typeObj::JOUEUR3];
            if (t % 40 != 0) {
                tnt.X = (t < 0) ? (t / 40 * 40 - 40) : (t / 40 * 40);
            } else {
                tnt.X = t / 40 * 40;
            }
            t = this->_map_start_pos[Graphical::typeObj::JOUEUR3].Y + this->_povY[Graphical::typeObj::JOUEUR3];
            if (t % 40 != 0) {
                tnt.Y = (t < 0) ? (t / 40 * 40 - 30) : (t / 40 * 40 + 10);
            } else {
                tnt.Y = t / 40 * 40 + 10;
            }
            this->_boom_pos[Graphical::typeObj::JOUEUR3] = tnt;
            this->_asset3d_id_list = this->_graphical->get_asset3D()->createMeshModel3D(Graphical::BOMBE1, tnt, irr::core::vector3df(0, 0, 0));
        }
    } else if (this->_ammo[Graphical::typeObj::JOUEUR3] == 0 && (this->timer->getTime() - this->_boom[Graphical::typeObj::JOUEUR3]) >= 2000) {
        this->_ammo[Graphical::typeObj::JOUEUR3] = 1;
        checkDamage(this->_boom_pos[Graphical::typeObj::JOUEUR3]);
        destroyBomb(this->_boom_pos[Graphical::typeObj::JOUEUR3]);
    }

    if (this->_input->get_input("up_arrow") == true && this->_type_robot[Graphical::typeObj::JOUEUR4] == false &&
    this->_hp[Graphical::typeObj::JOUEUR4] == 1) { // J4
        this->_graphical->get_asset3D()->setRotationbyId(irr::core::vector3df(-90, 0, 180), this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR4]);
        this->_povX[Graphical::typeObj::JOUEUR4] = 0;
        this->_povY[Graphical::typeObj::JOUEUR4] = -20;
        if (isBlocked_Up(this->_map_start_pos[Graphical::typeObj::JOUEUR4]) == false)
            this->_map_start_pos[Graphical::typeObj::JOUEUR4].Y = this->_map_start_pos[Graphical::typeObj::JOUEUR4].Y + 1;
    }
    if (this->_input->get_input("down_arrow") == true && this->_type_robot[Graphical::typeObj::JOUEUR4] == false &&
    this->_hp[Graphical::typeObj::JOUEUR4] == 1) {
        this->_graphical->get_asset3D()->setRotationbyId(irr::core::vector3df(-90, 0, 0), this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR4]);
        this->_povX[Graphical::typeObj::JOUEUR4] = 0;
        this->_povY[Graphical::typeObj::JOUEUR4] = 0;
        if (isBlocked_Down(this->_map_start_pos[Graphical::typeObj::JOUEUR4]) == false)
            this->_map_start_pos[Graphical::typeObj::JOUEUR4].Y = this->_map_start_pos[Graphical::typeObj::JOUEUR4].Y - 1;
    }
    if (this->_input->get_input("left_arrow") == true && this->_type_robot[Graphical::typeObj::JOUEUR4] == false &&
    this->_hp[Graphical::typeObj::JOUEUR4] == 1) {
        this->_graphical->get_asset3D()->setRotationbyId(irr::core::vector3df(-90, 0, 270), this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR4]);
        this->_povX[Graphical::typeObj::JOUEUR4] = 40;
        this->_povY[Graphical::typeObj::JOUEUR4] = 0;
        if (isBlocked_Left(this->_map_start_pos[Graphical::typeObj::JOUEUR4]) == false)
            this->_map_start_pos[Graphical::typeObj::JOUEUR4].X = this->_map_start_pos[Graphical::typeObj::JOUEUR4].X - 1;
    }
    if (this->_input->get_input("right_arrow") == true && this->_type_robot[Graphical::typeObj::JOUEUR1] == false &&
    this->_hp[Graphical::typeObj::JOUEUR4] == 1) {
        this->_graphical->get_asset3D()->setRotationbyId(irr::core::vector3df(-90, 0, 90), this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR4]);
        this->_povX[Graphical::typeObj::JOUEUR4] = 5;
        this->_povY[Graphical::typeObj::JOUEUR4] = 0;
        if (isBlocked_Right(this->_map_start_pos[Graphical::typeObj::JOUEUR4]) == false)
            this->_map_start_pos[Graphical::typeObj::JOUEUR4].X = this->_map_start_pos[Graphical::typeObj::JOUEUR4].X + 1;
    }
    if (this->_ammo[Graphical::typeObj::JOUEUR4] == 1) {
        if (this->_input->get_input("right_shift") == true && this->_type_robot[Graphical::typeObj::JOUEUR4] == false) {
            this->_boom[Graphical::typeObj::JOUEUR4] = timer->getTime();
            this->_ammo[Graphical::typeObj::JOUEUR4] = 0;
            t = this->_map_start_pos[Graphical::typeObj::JOUEUR4].X + this->_povX[Graphical::typeObj::JOUEUR4];
            if (t % 40 != 0) {
                tnt.X = (t < 0) ? (t / 40 * 40 - 40) : (t / 40 * 40);
            } else {
                tnt.X = t / 40 * 40;
            }
            t = this->_map_start_pos[Graphical::typeObj::JOUEUR4].Y + this->_povY[Graphical::typeObj::JOUEUR4];
            if (t % 40 != 0) {
                tnt.Y = (t < 0) ? (t / 40 * 40 - 30) : (t / 40 * 40 + 10);
            } else {
                tnt.Y = t / 40 * 40 + 10;
            }
            this->_boom_pos[Graphical::typeObj::JOUEUR4] = tnt;
            this->_asset3d_id_list = this->_graphical->get_asset3D()->createMeshModel3D(Graphical::BOMBE1, tnt, irr::core::vector3df(0, 0, 0));
        }
    } else if (this->_ammo[Graphical::typeObj::JOUEUR4] == 0 && (this->timer->getTime() - this->_boom[Graphical::typeObj::JOUEUR4]) >= 2000) {
        this->_ammo[Graphical::typeObj::JOUEUR4] = 1;
        checkDamage(this->_boom_pos[Graphical::typeObj::JOUEUR4]);
        destroyBomb(this->_boom_pos[Graphical::typeObj::JOUEUR4]);
    }

    if (this->timer->getTime() - this->result >= 1) {
        if (this->_map_start_pos[Graphical::typeObj::JOUEUR1] == this->_map_old_pos[Graphical::typeObj::JOUEUR1] && this->_type_robot[Graphical::typeObj::JOUEUR1] == false) {
            this->_graphical->get_asset3D()->changeAnimationById(this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR1], AFK);
        } else if (this->_type_robot[Graphical::typeObj::JOUEUR1] == false) {
            this->_graphical->get_asset3D()->setPositionbyId(this->_map_start_pos[Graphical::typeObj::JOUEUR1], this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR1]);
            this->_graphical->get_asset3D()->changeAnimationById(this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR1], RUN);
            this->_map_old_pos[Graphical::typeObj::JOUEUR1] = this->_map_start_pos[Graphical::typeObj::JOUEUR1];
        }
        if (this->_map_start_pos[Graphical::typeObj::JOUEUR2] == this->_map_old_pos[Graphical::typeObj::JOUEUR2] && this->_type_robot[Graphical::typeObj::JOUEUR2] == false) {
            this->_graphical->get_asset3D()->changeAnimationById(this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR2], AFK);
        } else if (this->_type_robot[Graphical::typeObj::JOUEUR2] == false) {
            this->_graphical->get_asset3D()->setPositionbyId(this->_map_start_pos[Graphical::typeObj::JOUEUR2], this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR2]);
            this->_graphical->get_asset3D()->changeAnimationById(this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR2], RUN);
            this->_map_old_pos[Graphical::typeObj::JOUEUR2] = this->_map_start_pos[Graphical::typeObj::JOUEUR2];
        }
        if (this->_map_start_pos[Graphical::typeObj::JOUEUR3] == this->_map_old_pos[Graphical::typeObj::JOUEUR3] && this->_type_robot[Graphical::typeObj::JOUEUR3] == false){
            this->_graphical->get_asset3D()->changeAnimationById(this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR3], AFK);
        } else if (this->_type_robot[Graphical::typeObj::JOUEUR3] == false) {
            this->_graphical->get_asset3D()->setPositionbyId(this->_map_start_pos[Graphical::typeObj::JOUEUR3], this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR3]);
            this->_graphical->get_asset3D()->changeAnimationById(this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR3], RUN);
            this->_map_old_pos[Graphical::typeObj::JOUEUR3] = this->_map_start_pos[Graphical::typeObj::JOUEUR3];
        }
        if (this->_map_start_pos[Graphical::typeObj::JOUEUR4] == this->_map_old_pos[Graphical::typeObj::JOUEUR4] && this->_type_robot[Graphical::typeObj::JOUEUR4] == false) {
            this->_graphical->get_asset3D()->changeAnimationById(this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR4], AFK);
        } else if (this->_type_robot[Graphical::typeObj::JOUEUR4] == false) {
            this->_graphical->get_asset3D()->setPositionbyId(this->_map_start_pos[Graphical::typeObj::JOUEUR4], this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR4]);
            this->_graphical->get_asset3D()->changeAnimationById(this->_map_player_typeObj_id[Graphical::typeObj::JOUEUR4], RUN);
            this->_map_old_pos[Graphical::typeObj::JOUEUR4] = this->_map_start_pos[Graphical::typeObj::JOUEUR4];
        }
        this->result = this->timer->getTime();
    }
}

void Graphical_game::display_pause()
{
    // std::cout << "display_pause" << std::endl;
    std::list<unsigned>::iterator list_pause_iterator;
    
    for (list_pause_iterator = this->_list_pause.begin(); list_pause_iterator != this->_list_pause.end(); list_pause_iterator++)
        this->_graphical->get_asset2D()->displayById((*list_pause_iterator));
    // this->_graphical->drawAll();
}

void Graphical_game::display()
{
    std::list<unsigned>::iterator list_background_iterator;
    
    if (background.size() == 0){
        this->_graphical->get_asset2D()->destroyAll2DAsset();
        this->create_game_asset();
    }
    this->deplacement();
    // this->_graphical->get_asset2D()->displayAll2DAsset();
    for (list_background_iterator = this->background.begin(); list_background_iterator != this->background.end(); list_background_iterator++)
        this->_graphical->get_asset2D()->displayById((*list_background_iterator));
    this->_graphical->drawAll();
}
