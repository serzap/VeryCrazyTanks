#ifndef VERYCRAZYTANKS_ENTITY_H
#define VERYCRAZYTANKS_ENTITY_H


#include <utility>
#include <vector>

class Entity {
public:
    Entity();
    Entity(int x, int y, int hp, char texture);

    const int &getX();

    void setX(int x);

    const int &getY();

    void setY(int y);

    virtual std::vector<std::pair<int, int>> getBounds() = 0;

    void getDamage();

    bool isDestroyed();

    virtual void draw(char **map) = 0;
protected:
    int m_x;
    int m_y;
    int m_hitPoints;
    char m_texture;
};


#endif //VERYCRAZYTANKS_ENTITY_H
