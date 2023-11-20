#include "game.h"

Game::Game()
{
    guess = "";
    b = new Board();
    is_over = false;

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
