
#include "Fortress.h"

Fortress::Fortress() = default;

Fortress::Fortress(int x, int y) : Entity(x,y,1){
    walls.push_back(Wall(x, y, Constants::WALL_HP, Constants::WALL_TEXTURE, 3, Position::HORIZONTAL));
    walls.push_back(Wall(x, y - 2, Constants::WALL_HP, Constants::WALL_TEXTURE, 3, Position::HORIZONTAL));
    walls.push_back(Wall(x, y - 1, Constants::WALL_HP, Constants::WALL_TEXTURE, 1, Position::VERTICAL));
    walls.push_back(Wall(x + 2, y - 1, Constants::WALL_HP, Constants::WALL_TEXTURE, 1, Position::VERTICAL));
    gold = new Gold(x + 1, y - 1, Constants::GOLD_HP, Constants::GOLD_TEXTURE);
}

void Fortress::getDamage() {}

bool Fortress::isDestroyed() {
    return false;
}

std::vector<std::pair<int, int>> Fortress::getBounds() {
    //CHANGE
    return std::vector<std::pair<int, int>>();
}

void Fortress::update() {
    for(int i = 0; i < walls.size(); ++i){
        walls[i].update();
    }
    gold->update();
}

void Fortress::draw(Map &map) {
    for(int i = 0; i < walls.size(); ++i){
        walls[i].draw(map);
    }
    gold->draw(map);
}
