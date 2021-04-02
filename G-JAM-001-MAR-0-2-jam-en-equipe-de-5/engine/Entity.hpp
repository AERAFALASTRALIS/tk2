/*
** EPITECH PROJECT, 2020
** G-JAM-001-MAR-0-2-jam-killian.moudery
** File description:
** Entity.hpp
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

// Uncomment this line if VertexArray is not defined
//#define NO_SHIELD_DISPLAY

#include <string>
#include <memory>
#include <map>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#ifndef NO_SHIELD_DISPLAY
#include <SFML/Graphics/VertexArray.hpp>
#endif

struct EntityData {
    std::string name;
    float x;
    float y;
    float angle;
    float velX;
    float velY;
    float dampener;
    float maxShieldPower;
    float shieldPower;
    float shieldRecover;
    int shieldPoints;
    float shields[24];
};

class Entity {
public:
    Entity(const std::string &textureName, int x, int y, float angle, float velX, float velY, float shieldPower = 0, float shieldRecover = 0.1, int shieldPoints = 5);
    virtual ~Entity();
    Entity(const Entity &cpy) = default;
    Entity &operator=(const Entity &src) = default;

    void setVelocity(float x, float y);
    void accelerate(float x, float y);
    // accelerate in the front direction
    void accelerate(float prop);
    // Angle is in radian
    void rotate(float angle);
    void setRotation(float angle);
    float getRotation() const {return angle;}
    // 0 for no dampening, 1 for immediately stopped
    void dampening(float d);
    // Angle in radian
    void damageShield(float dmg, float angle);
    // Automatic angle detection
    void damageShield(float dmg, Entity &other);
    // called by GraphicEngine
    void draw();
    // called by GraphicEngine for customized behaviors
    virtual void update() {}
    void internalUpdate();
    bool isAlive() {return alive;}
    static void loadTexture(const std::string &filename, const std::string &textureName);
    // Unload texture. The effective texture unloading occur when there is no Entity attached to it.
    static void unloadTextures();
    static void bindWindow(sf::RenderWindow &win) {window = &win;}
    float getShieldPower() const {return shieldPower;}
    void kill() {alive = false;}
    const float &refX;
    const float &refY;
protected:
    Entity(); // For entity loading only
    void load(EntityData &sav);
    EntityData save();
private:
    #ifndef NO_SHIELD_DISPLAY
    void initShield();
    std::unique_ptr<sf::VertexArray> shield;
    #endif
    static std::map<std::string, std::shared_ptr<sf::Texture>> loadedTextures;
    static sf::RenderWindow *window;
    std::shared_ptr<sf::Texture> texture;
    sf::Sprite sprite;
    std::string name;
    float x;
    float y;
    float angle;
    float oldAngle = 0;
    float velX;
    float velY;
    float dampener = 0;
    float lastPropAng = 0;
    float propX = 0;
    float propY = -1;
    float maxShieldPower;
    float shieldPower;
    float shieldRecover;
    int shieldPoints;
    bool alive = true;
    float shields[24];
};

#endif /* ENTITY_HPP_ */
