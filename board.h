#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>

#include "die.h"

class Board
{
    private:
        std::vector<Die*> dice;
    public:
        Board();

        void shake();
        std::string spot(int i, int j) const;
        std::string get_word(std::vector<int> positions);
        ~Board();

        friend std::ostream& operator<<(std::ostream &os, const Board &b);
};

#endif
