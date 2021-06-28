/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-antoine.viala
** File description:
** Player_select
*/

#ifndef GRAPHICAL_HPP_
#define GRAPHICAL_HPP_

#include "irrlicht.h"
#include <map>

#define SCREEN_HEIGHT (this->_graphical->get_driver_screen_size().Height)
#define SCREEN_WIDTH (this->_graphical->get_driver_screen_size().Width)
#define NAME_WINDOW L"ALED"

class Input;
class Parametre;
class Assets3DHandler;
class Assets2DHandler;

class Graphical {
    public:

    enum typeMesh {
        JOUEUR1_AFK,
        JOUEUR1_RUN,
        JOUEUR2_AFK,
        JOUEUR2_RUN,
        JOUEUR3_AFK,
        JOUEUR3_RUN,
        JOUEUR4_AFK,
        JOUEUR4_RUN,
        STAGE,
        GROUND,
        BOX,
        BOMB,
    };

    enum typeTexture {
        /* Quelle type de texture, genre quand tu faite le fill texture, this->_texture[PLAYER_NAME_JOUEUR] = this->_driver->gettexture(path_dynamique_de_la_texture)  */
        JOUEUR1_JPG,
        JOUEUR2_JPG,
        JOUEUR3_JPG,
        JOUEUR4_JPG,
        MAP,
        SOL,
        BOITE,
        BOMBE,
        JOUEUR_BACKGROUND, /* pour le select player*/
        TOUCHE_J1_ZQSD, /* Trouver une image avec les 4 touche a coter  */
        TOUCHE_J2_TFGH,
        TOUCHE_J3_IJKL,
        TOUCHE_J4_FLECH,
        MAIN_MENU_BACKGROUD,
        MAIN_MENU_TITLE,
        MAIN_MENU_BUTTON_PLAY,
        MAIN_MENU_BUTTON_PLAY_OVER,
        MAIN_MENU_BUTTON_QUIT,
        MAIN_MENU_BUTTON_QUIT_OVER,
        SELECT_FLECHE_LEFT,
        SELECT_FLECHE_RIGHT,
        SELECT_PLAYER_NAME_JOUEUR,
        SELECT_PLAYER_NAME_ROBOT,
        SELECT_PLAYER_NAME_AFK,
        SELECT_BUTTON_RETURN,
        SELECT_BUTTON_RETURN_OVER,
        SELECT_BUTTON_PLAY,
        SELECT_BUTTON_PLAY_OVER,
        PAUSE_TITLE,
    };

    enum typeObj {
        /* Quelle type de texture, genre quand tu faite le fill texture, this->_texture[PLAYER_NAME_JOUEUR] = this->_driver->gettexture(path_dynamique_de_la_texture)  */
        JOUEUR1,
        JOUEUR2,
        JOUEUR3,
        JOUEUR4,
        ROBOT1,
        ROBOT2,
        ROBOT3,
        ROBOT4,
        STAGE1,
        SOL1,
        BOITE1,
        BOMBE1,
    };

        Graphical(Input *input);
        ~Graphical();

        // void add_camera_in_scene_manager(irr::scene::ISceneManager* parent, irr::core::vector3df position, irr::core::vector3df lookat);
        void add_camera_in_scene_manager(irr::core::vector3df position, irr::core::vector3df lookat);
        void drawAll();
        void fill_mesh();
        void fill_texture();
        void end_scene();
        irr::video::ITexture* get_texture_by_typeTexture(typeTexture typeTexture);
        irr::core::dimension2du get_driver_screen_size() const;
        Assets3DHandler *get_asset3D();
        Assets2DHandler *get_asset2D();
        bool get_reload() const;
        Input *get_input() const;
        short int get_actual_scene() const;
        void set_actual_scene(short int aled);
        irr::IrrlichtDevice* getdevice() const;
        void setdevice (irr::IrrlichtDevice* _device);
        void setreload(bool reload);
        irr::video::IVideoDriver* getdriver() const;
        void setdriver(irr::video::IVideoDriver* _driver);
        irr::scene::ISceneManager* getsceneManager() const;
        void setsceneManager(irr::scene::ISceneManager* _sceneManager);
    protected:
        std::map<typeTexture, irr::video::ITexture*> _texture;
        std::map<typeMesh, irr::scene::IAnimatedMesh*> _mesh;
        Input *_input;
        Assets3DHandler *_asset3d;
        Assets2DHandler *_asset2d;
        irr::IrrlichtDevice* device;
        irr::video::IVideoDriver* driver;
        irr::scene::ISceneManager* sceneManager;
        short int actual_scene; // 0 = rien : 1 = menu : 2 = game
        bool _reload;
    private:
};

#endif /* !GRAPHICAL_HPP_ */
