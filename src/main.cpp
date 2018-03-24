#include <iostream>
#include "BattleField.h"
int main() {
    for(int i = 0; i < 1000; ++i){
    std::srand(time(0));
    BattleField b;
    b.init();
    b.generate();
    b.update();
    b.draw();}

    return 0;
}