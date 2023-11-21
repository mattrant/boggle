#ifndef DIE_H
#define DIE_H

#include <string>
#include <random>
#include <vector>

class Die
{
    private:
        std::string faces;
        std::vector<Die*> neighbors;
        std::string top;
    public:
        Die(std::string faces);
        void roll();
        std::string get_top() const;
};

#endif
