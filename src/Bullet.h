#ifndef VERYCRAZYTANKS_BULLET_H
#define VERYCRAZYTANKS_BULLET_H

#include "Constants.h"
#include "Entity.h"


class Bullet : public Entity {
public:
    Bullet();

    Bullet(int x, int y, int hp, char texture, int speed, Direction dir, Type type);

    void move();

private:
    int m_speed;
    Direction m_dir;
    Type m_type;
};


#endif //VERYCRAZYTANKS_BULLET_H
