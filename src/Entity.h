#ifndef VERYCRAZYTANKS_ENTITY_H
#define VERYCRAZYTANKS_ENTITY_H


#include <utility>
#include <vector>
#include "Constants.h"
#include "Map.h"


class Entity {
public:
    Entity();

    Entity(int x, int y, int hp);

    virtual ~Entity();

    //Getters and Setters
    const int &getX() const;

    void setX(const int &x);

    const int &getY() const;

    void setY(const int &y);

    //Functions
    virtual void getDamage() = 0;

    virtual bool isDestroyed() = 0;

    virtual std::vector<std::pair<int, int>> getBounds() = 0;

    virtual void update() = 0;

    virtual void draw(Map &map) = 0;

protected:
    int m_x;
    int m_y;
    int m_hitPoints;
};

#endif //VERYCRAZYTANKS_ENTITY_H
