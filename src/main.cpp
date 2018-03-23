#include <iostream>
#include "BattleField.h"
int main() {
    std::srand(time(0));
    BattleField b;
    b.init();
    b.generate();

    return 0;
}