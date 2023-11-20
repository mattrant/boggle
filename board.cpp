#include <random>
#include <algorithm>
#include <string>
#include <cassert>
#include <iostream>

#include "board.h"
#include "die.h"
//TODO: use unique_ptr or learn to implement constructor and assignment/copy operators for rule of 5
Board::Board()
{
    std::vector<std::string> die_faces = {
    "RIFOBX",
    "IFEHEY",
    "DENOWS",
    "UTOKND",
    "HMSRAO",
    "LUPETS",
    "ACITOA",
    "YLGKUE",
    "QBMJOA",
    "EHISPN",
    "VETIGN",
    "BALIYT",
    "EZAVND",
    "RALESC",
    "UWILRG",
    "PACEMD"
    };

    for(int i = 0;i<16;++i){
        dice.push_back( new Die(die_faces[i]));
    }

}

void Board::shake()
{
    //shake the dice in the board
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(dice.begin(), dice.end(),g);

    for(Die* d:dice){
        d->roll();
    }
}

std::string Board::spot(int i, int j) const{
    /*
    Returns the die at position (i,j) on the 4x4 board. The top left
    corner is considered to be (0,0).
    */
    assert(i<4 && i>=0 && j<4 && j>=0);
    
    return dice[4*i+j]->get_top();
}

std::ostream& operator<<(std::ostream &os, const Board &b){
    for(int i = 0;i<4;++i){
        for(int j = 0;j<4;++j){
            os<<(b.spot(i,j))<<" ";
        }
        std::cout<<std::endl;
    }
    return os;
}

std::string Board::get_word(std::vector<int> positions){
    //returns words indicated by the positions
    if(positions.size()==0){
        return "";
    }

    std::string s;
    for(int i:positions){
        s.append(spot(i/4,i%4));
    }
    return s;
}

Board::~Board(){
    for(Die* d: dice){
        delete d;
    }
}
