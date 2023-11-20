#include "game.h"

Game::Game()
{
    guess = "";
    b = new Board();
    is_over = false;

    init_adj();

    b->shake();
    Trie t("../engmix.txt");
    for(int i = 0;i<16;++i){
        std::vector<int> v;
        DFS_path(i,v,t);
    }

}
Game::~Game(){
    delete this->b;
}
void Game::guess_edited(const QString &text){
    guess = text.toStdString();
}

void Game::check_guess(){

    if(found.find(guess) == found.end() && dict.find(guess)!=dict.end()){
        //TODO: add word to 'found' box
        found.insert(guess);
    }
    guess = "";
}

void Game::print_dict(){
    std::vector<std::string> words[17];
    for(std::string s: dict){
        words[s.size()].push_back(s);
    }
    for(int i =3;i<17;++i){
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














