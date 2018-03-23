#ifndef VERYCRAZYTANKS_TANK_H
#define VERYCRAZYTANKS_TANK_H

#include "Bullet.h"


class Tank : public Entity {
public:
    Tank();

    Tank(int x, int y, int hp, char texture, int speed, Direction dir, Type type);

    void move();

    Bullet &shoot();

    std::vector<std::pair<int, int>> getBounds() override;

    void draw(Map &map) override;

private:
    char m_texture;
    int m_speed;
    Direction m_dir;
    Type m_type;
};


#endif //VERYCRAZYTANKS_TANK_H
