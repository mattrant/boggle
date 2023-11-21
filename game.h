#ifndef GAME_H
#define GAME_H

#include <string>
#include <unordered_set>

#include <QObject>
#include <QString>
#include <QTime>
#include <QTimer>

#include "board.h"
#include "trie.h"
#include "display.h"

class Game : public QObject
{
    private:
        Board *b;
        std::string guess;
        bool started;
        bool is_over;
        bool paused;
        std::unordered_set<std::string> dict;
        std::unordered_set<std::string> found;
        std::vector<std::vector<int>> adj;
        QTime time_left;
        QTimer t;
        Ui::MainWindow ui;

        void DFS_path(int node, std::vector<int> path, Trie &t);
        void init_adj();
        std::string found_words_string();
        void init_game();

    public:


        Game(Ui::MainWindow &ui);
        ~Game();
        void print_game();
        void print_dict();
        std::unordered_set<std::string> get_dict();
    private slots:
        void update_timer();
        void guess_edited(const QString &text);
        void check_guess();
        void end_game();
        void start_game();
        void pause_game();



};

#endif // GAME_H
