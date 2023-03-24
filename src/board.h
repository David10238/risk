
#ifndef BOARD_H
#define BOARD_H

#include<string>
#include <array>
#include<vector>


constexpr int N_TERRITORIES = 42;

struct territory {
    int id;
    std::string name;
    int x, y;
    std::vector<int> edges;
    territory(int id, std::string name, int x, int y);
    territory();
    void addEdges(std::vector<territory> edges);
};

struct board {
public:
    std::array<territory, N_TERRITORIES> territories;
    board();
};

#endif