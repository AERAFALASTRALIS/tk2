/*
** EPITECH PROJECT, 2020
** G-JAM-001-MAR-0-2-jam-killian.moudery
** File description:
** Entity.cpp
*/
#include "Entity.hpp"
#include <math.h>
#include <cstring>
#include <SFML/Graphics.hpp>

std::map<std::string, std::shared_ptr<sf::Texture>> Entity::loadedTextures;
sf::RenderWindow *Entity::window = nullptr;

Entity::Entity() : refX(x), refY(y) {}

Entity::Entity(const std::string &textureName, int _x, int _y, float angle, float velX, float velY, float shieldPower, float shieldRecover, int shieldPoints) :
    refX(x), refY(y), name(textureName), x(_x), y(_y), angle(angle), velX(velX), velY(velY), maxShieldPower(shieldPower), shieldPower(shieldPower), shieldRecover(shieldRecover), shieldPoints(shieldPoints)
{
    texture = loadedTextures[textureName];
    if (texture) {
        sprite.setTexture(*texture, true);
        auto tmp = texture->getSize();
        sprite.setOrigin(tmp.x/2, tmp.y/2);
    }
    for (int i = 0; i < shieldPoints; ++i)
        shields[i] = shieldPower;
    #ifndef NO_SHIELD_DISPLAY
    if (shieldPoints > 1)
        initShield();
    #endif
}

Entity::~Entity()
{}

#ifndef NO_SHIELD_DISPLAY
void Entity::initShield()
{
    shield = std::make_unique<sf::VertexArray>(sf::TriangleStrip, shieldPoints * 4 + 2);

    sf::VertexArray &v = *shield;
    const float radius = texture->getSize().x / 2;
    const float radius2 = radius + 5;
    float ang = 0;
    const float angShift = 3.1415926 * 2 / (shieldPoints * 2);
    const sf::Color c(0, 255, 255);
    const sf::Color c2(0, 192, 255);
    const sf::Vector2f shift(radius, radius);
    for (int i = 0; i <= shieldPoints * 2; ++i) {
        const sf::Vector2f vec(cos(ang), sin(ang));
        v[i * 2] = sf::Vertex(vec * radius + shift, c);
        v[i * 2 | 1] = sf::Vertex(vec * radius2 + shift, c2);
        ang += angShift;
    }
}
#endif

void Entity::load(EntityData &sav)
{
    name = sav.name;
    texture = loadedTextures[name];
    if (texture) {
        sprite.setTexture(*texture, true);
        auto tmp = texture->getSize();
        sprite.setOrigin(tmp.x/2, tmp.y/2);
    }
    x = sav.x;
    y = sav.y;
    angle = sav.angle;
    velX = sav.velX;
    velY = sav.velY;
    dampener = sav.dampener;
    maxShieldPower = sav.maxShieldPower;
    shieldPower = sav.shieldPower;
    shieldRecover = sav.shieldRecover;
    shieldPoints = sav.shieldPoints;
    memcpy(&shields, &sav.shields, 24*sizeof(float));
    #ifndef NO_SHIELD_DISPLAY
    if (shieldPoints > 1)
        initShield();
    #endif
}

EntityData Entity::save()
{
    EntityData tmp {name, x, y, angle, velX, velY, dampener, maxShieldPower, shieldPower, shieldRecover, shieldPoints, {}};
    memcpy(&tmp.shields, &shields, 24*sizeof(float));
    return tmp;
}

void Entity::draw()
{
    if (angle != oldAngle) {
        oldAngle = angle;
        sprite.setRotation(oldAngle * (180. / 3.1415926));
    }
    sprite.setPosition(x, y);
    window->draw(sprite);

    #ifndef NO_SHIELD_DISPLAY
    if (shield) {
        auto &s = *shield;
        for (int i = 0; i <= shieldPoints * 2; ++i) {
            if (i & 1) {
                const float c = (shields[i / 2] + shields[(i / 2 + 1) % shieldPoints]) / (2 * maxShieldPower);
                s[i * 2].color.a = c * 192;
                s[i * 2 | 1].color.a = c * c * 160;
            } else {
                const float c = shields[(i / 2) % shieldPoints] / maxShieldPower;
                s[i * 2].color.a = c * 255;
                s[i * 2 | 1].color.a = c * c * 192;
            }
        }
        window->draw(s, sf::RenderStates(sprite.getTransform()));
    }
    #endif
}

void Entity::setVelocity(float _x, float _y)
{
    velX = _x;
    velY = _y;
}

void Entity::accelerate(float _x, float _y)
{
    velX += _x;
    velY += _y;
}

void Entity::accelerate(float prop)
{
    if (lastPropAng != angle) {
        lastPropAng = angle;
        propX = sin(angle);
        propY = -cos(angle);
    }
    accelerate(prop * propX, prop * propY);
}

void Entity::dampening(float damp)
{
    dampener = damp;
}

void Entity::damageShield(float dmg, float ang)
{
    ang -= angle;
    ang /= 3.1415926 * 2;
    ang = ang - (((int) ang) - (ang < 0));
    if ((shields[(int) (ang * shieldPoints)] -= dmg) < 0.)
        alive = false;
}

void Entity::rotate(float ang)
{
    angle += ang;
}

void Entity::setRotation(float ang)
{
    angle = ang;
}

void Entity::internalUpdate()
{
    x += velX;
    y += velY;
    velX -= velX * dampener;
    velY -= velY * dampener;
    // Shield system
    shieldPower = 0;
    for (int i = 0; i < shieldPoints; ++i) {
        if ((shields[i] += shieldRecover) > maxShieldPower)
            shields[i] = maxShieldPower;
        shieldPower += shields[i];
    }
}

void Entity::loadTexture(const std::string &filename, const std::string &textureName)
{
    auto tex = std::make_shared<sf::Texture>();

    if (tex->loadFromFile(std::string("textures/") + filename))
        loadedTextures[textureName] = tex;
}

void Entity::unloadTextures()
{
    loadedTextures.clear();
}

void Entity::damageShield(float dmg, Entity &other)
{
    float x2 = other.x - x;
    float y2 = other.y - y;
    const float normalization = sqrt(x2 * x2 + y2 * y2);
    x2 /= normalization;
    y2 /= normalization;
    damageShield(dmg, atan2(y2, x2));
}
