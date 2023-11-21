#include "game.h"
#include "display.h"

Game::Game(Ui::MainWindow &ui)
{
    this->ui = ui;
    ui.found_words_label->setWordWrap(true);
    ui.found_words_label->setText(" ");

    QObject::connect(&t,&QTimer::timeout,this,&Game::update_timer);
    QObject::connect(ui.input_line,&QLineEdit::textEdited,this,&Game::guess_edited);
    QObject::connect(ui.input_line,&QLineEdit::returnPressed,this,&Game::check_guess);
    QObject::connect(ui.start_button,&QPushButton::clicked,this,&Game::start_game);
    QObject::connect(ui.give_up_button,&QPushButton::clicked,this,&Game::end_game);
    QObject::connect(ui.pause_button,&QPushButton::clicked,this,&Game::pause_game);

    init_adj();
    b = std::unique_ptr<Board>(new Board());
    init_game();

}

void Game::init_game(){
    guess = "";
    is_over = false;
    started = false;
    paused = false;
    dict = {};
    found = {};

    ui.pause_button->setText("Pause");

    time_left = QTime(0,3,0);

    b->shake();
    Trie t("../engmix.txt");
    for(int i = 0;i<16;++i){
        std::vector<int> v;
        DFS_path(i,v,t);
    }

    for(int i = 0;i<16;++i){
        ui.grid[i]->setText(QString::fromStdString("_"));
    }
}

Game::~Game(){
    //delete this->b;
}

void Game::pause_game(){
    if(!started || is_over){
        return;
    }
    if(paused){
       paused= false;
       ui.pause_button->setText("Pause");
       for(int i = 0;i<16;++i){
           ui.grid[i]->setText(QString::fromStdString(b->spot(i/4,i%4)));
       }
       t.start(1000);
    }
    else{
        paused = true;
        ui.pause_button->setText("Resume");

        for(int i = 0;i<16;++i){
            ui.grid[i]->setText(QString::fromStdString("_"));
        }
    }
}

void Game::guess_edited(const QString &text){
    guess = text.toStdString();
    std::transform(guess.begin(),guess.end(),guess.begin(),::toupper);
}

void Game::start_game(){
    if(started || is_over){
        //Start new game
        ui.found_words_label->setText("");
        ui.input_line->setText("");
        init_game();
        started=true;

        for(int i = 0;i<16;++i){
            ui.grid[i]->setText(QString::fromStdString(b->spot(i/4,i%4)));
        }
        ui.timer_display->display(time_left.toString("m.ss"));
        t.start(1000);
        return;
    }

    ui.start_button->setText("New Game");
    started=true;

    for(int i = 0;i<16;++i){
        ui.grid[i]->setText(QString::fromStdString(b->spot(i/4,i%4)));
    }
    ui.timer_display->display(time_left.toString("m.ss"));
    t.start(1000);
}

void Game::end_game(){
    if(started && !is_over){
        is_over = true;
        time_left = QTime(0,0,0);
        ui.timer_display->display("0");

        std::string all_words = ui.found_words_label->text().toStdString()+"\n";

        all_words.append("----------------------\n");
        all_words.append("You found "+std::to_string(100*found.size()/dict.size())+" percent of all words\n");

        std::vector<std::string> words[17];
        for(std::string s: get_dict()){
            words[s.size()].push_back(s);
        }
        for(int i =3;i<17;++i){
            if(words[i].size()==0){
                continue;
            }

            all_words.append("----------------------\n");
            std::sort(words[i].begin(),words[i].end());
            for(std::string s:words[i]){
                if(found.find(s)==found.end()){
                    all_words.append(s+" ");
                }

            }
            all_words.append("\n");
        }

        ui.found_words_label->setText(QString::fromStdString(all_words));
        ui.found_words_label->adjustSize();

    }

}

void Game::check_guess(){

    if(!started || is_over){
        return;
    }

    ui.input_line->setText("");

    if(dict.find(guess)!=dict.end() && found.find(guess)==found.end()){
        found.insert(guess);
        if(found.size()!=1){
            ui.found_words_label->setText(ui.found_words_label->text()+" "+ QString::fromStdString(guess));
        }
        else{
            ui.found_words_label->setText(QString::fromStdString(guess));
        }

    }
    guess = "";
}

void Game::print_dict(){
    std::vector<std::string> words[17];
    for(std::string s: dict){
        words[s.size()].push_back(s);
    }
    for(int i =3;i<17;++i){
        if(words[i].size()==0){
            continue;
        }
        std::cout<<"Words of length "<<i<<std::endl;
        std::sort(words[i].begin(),words[i].end());
        for(std::string s:words[i]){
            std::cout<<s<<std::endl;
        }
    }
}

void Game::DFS_path(int node, std::vector<int> path, Trie &t){
    //perform DFS to determine all words by determining all paths
    path.push_back(node);
    std::string word = b->get_word(path);
    if(!t.prefix_present(word)){
        return;
    }
    if(t.is_present(word) && word.size()>=3){
        dict.insert(word);
    }
    for(int i: adj[node]){
        if (std::find(path.begin(),path.end(),i)!= path.end()){
            continue;
        }
        DFS_path(i,path,t);
    }
}


void Game::init_adj()
{
   //init adjacency lists
    std::vector<int> v = {0,1,2,3};
    std::vector<int> m = {-1,0,1};

    for(int i = 0; i<16;++i)
    {
        std::vector<int> x;
        adj.push_back(std::move(x));
    }

    for(int i:v)
    {
        for(int j: v)
        {
            for(int k:m)
            {
                for(int l:m)
                {
                    if(k==0 and l == 0)
                        continue;
                    else
                    {
                        if(j+k>=0 && j+k <=3 && i+l<=3 && i+l>=0)
                        {
                            adj[4*i+j].push_back(4*(i+l)+(j+k));
                        }
                    }
                }
            }
        }
    }
}

void Game::print_game(){
    std::cout<<*b<<std::endl;
    print_dict();
}

std::unordered_set<std::string> Game::get_dict(){return dict;}

void Game::update_timer(){
    if(time_left == QTime(0,0,0)|| paused){
        return;
    }

    time_left = time_left.addSecs(-1);
    QString s = time_left.toString("m.ss");
    ui.timer_display->display(time_left.toString("m.ss"));

    if(time_left!=QTime(0,0,0)){
         t.start(1000);
    }
    else{
        end_game();
    }
}









