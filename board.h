#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include <memory>

#include "die.h"

class Board
{
    private:
        std::vector<std::unique_ptr<Die>> dice;
    public:
        Board();

        void shake();
        std::string spot(int i, int j) const;
        std::string get_word(std::vector<int> positions);

        friend std::ostream& operator<<(std::ostream &os, const Board &b);
};

#endif
