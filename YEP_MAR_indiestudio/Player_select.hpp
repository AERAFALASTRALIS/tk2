/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-antoine.viala
** File description:
** Player_select
*/

#ifndef PLAYER_SELECT_HPP_
#define PLAYER_SELECT_HPP_

#include "Graphical.hpp"
#include "Input.hpp"

#define SELECT_POS_X ((SCREEN_WIDTH / 2) - ((this->_graphical->get_texture_by_typeTexture(Graphical::JOUEUR_BACKGROUND)->getSize().Width) * 2) - 200 + (((this->_graphical->get_texture_by_typeTexture(Graphical::JOUEUR_BACKGROUND)->getSize().Width) + 100) * this->_position) + 50)
#define SELECT_POS_Y ((SCREEN_HEIGHT / 2) - (this->_graphical->get_texture_by_typeTexture(Graphical::JOUEUR_BACKGROUND)->getSize().Height))

class Player_select {
    public:
        enum PlayerType {
            Joueur1,
            Joueur2,
            Joueur3,
            Joueur4,
            robot,
            afk
        };    

        Player_select(int position, Graphical *graphical, Input *input);
        ~Player_select();

        void createAssets();
        void creatinputAsset();
        void creatbackgroundAssets();
        PlayerType get_player_type() const;
        int get_chara_chosed() const;
        void creatplayerAssets();
        void stay_event();
        bool change_par_player_select(unsigned id);
        void del_asset2d_list();
        void del_asset3d();
        void creatbuttonAsset();

    protected:
        std::list<unsigned> _asset2d_id_list;
        PlayerType _player_type;
        int _position;
        Graphical *_graphical;
        Input *_input;
        unsigned _chara_design = -1;
        int _chara_chosed;
    private:
};

#endif /* !PLAYER_SELECT_HPP_ */
