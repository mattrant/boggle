#include <random>
#include <algorithm>
#include <string>
#include <cassert>
#include <iostream>

#include "board.h"
#include "die.h"

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
        dice.push_back( std::unique_ptr<Die>(new Die(die_faces[i])));
    }

}

void Board::shake()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(dice.begin(), dice.end(),g);

    for(auto const &d:dice){
        d->roll();
    }
}

std::string Board::spot(int i, int j) const{

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

std::string Board::get_word(std::vector<int> positions) const{
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

