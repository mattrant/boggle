#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include "die.h"

class Board
{
    private:
        std::vector<Die*> dice;
    public:
        Board();

        void shake();
        std::string spot(int i, int j);
        ~Board();
};

#endif