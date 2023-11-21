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
        std::unique_ptr<Board> b;
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

        void DFS_path(int node, std::vector<int> path, const Trie &t);
        void init_adj();
        void init_game();

    public:

        Game(Ui::MainWindow &ui);
        ~Game();
        void print_game() const;
        void print_dict() const;

    private slots:
        void update_timer();
        void guess_edited(const QString &text);
        void check_guess();
        void end_game();
        void start_game();
        void pause_game();



};

#endif // GAME_H
