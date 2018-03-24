#ifndef VERYCRAZYTANKS_BULLET_H
#define VERYCRAZYTANKS_BULLET_H

#include "Entity.h"


class Bullet : public Entity {
public:
    Bullet();

    Bullet(int x, int y, int hp, char texture, int speed, Direction dir, Type type);

    void getDamage() override;

    bool isDestroyed() override ;

    std::vector<std::pair<int, int>> getBounds() override;

    void update() override ;

    void draw(Map& map) override;

private:
    char m_texture;
    int m_speed;
    Direction m_dir;
    Type m_type;
};


#endif //VERYCRAZYTANKS_BULLET_H
