#ifndef GAME_H
#define GAME_H

#include <string>
#include <unordered_set>

#include <QObject>
#include <QString>

#include "board.h"
#include "trie.h"

class Game : public QObject
{
    private:
        Board *b;
        std::string guess;
        bool is_over;
        std::unordered_set<std::string> dict;
        std::unordered_set<std::string> found;
        std::vector<std::vector<int>> adj;

        void DFS_path(int node, std::vector<int> path, Trie &t);
        void init_adj();


    public:
        Game();
        ~Game();

        void print_dict();
        void print_game();
    public slots:
        void guess_edited(const QString &text);
        void check_guess();

};

#endif // GAME_H
