#ifndef GAME_H
#define GAME_H

#include <string>
#include <unordered_set>

#include <QObject>
#include <QString>

#include "board.h"

class Game : public QObject
{
    private:
        Board *b;
        std::string guess;
        bool is_over;
        std::unordered_set<std::string> dict;
        std::unordered_set<std::string> found;



    public:
        Game();
        ~Game();
    public slots:
        void guess_edited(const QString &text);
        void check_guess();

};

#endif // GAME_H
