#ifndef VERYCRAZYTANKS_MAP_H
#define VERYCRAZYTANKS_MAP_H

#include <vector>
#include <string>
#include <iostream>

class Map {
public:
    Map();

    void init(int width, int height);

    const int& getWidth() const;
    const int& getHeight() const;

    std::string& operator[](int index) {
        return m_field[index];
    }
    void display();
    void clear();

private:
    std::vector<std::string> m_field;
    int m_width;
    int m_height;
};

#endif //VERYCRAZYTANKS_MAP_H
