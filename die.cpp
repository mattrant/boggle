#include <string>
#include <random>
#include <vector>
#include <iostream>
#include "die.h"

Die::Die(std::string faces)
{   
    this->faces = faces;
}
void Die::roll()
{
    //Sets the top face of the die
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0,5);

    std::string top{this->faces[dist(gen)]};
    this-> top = top == "Q"? "QU": top;
}
std::string Die::get_top() const{ return top;}
