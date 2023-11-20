#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <deque>
#include <fstream>

#include "board.h"
#include "die.h"
#include "trie.h"

std::unordered_set<std::string> dict;

void print_board(Board &b)
{
    for(int i = 0;i<4;++i){
        for(int j = 0;j<4;++j){
            std::cout<<(b.spot(i,j))<<" ";
        }
        std::cout<<std::endl;
    }
}

std::string get_word(Board &b, std::vector<int> &positions)
{
    //returns words indicated by the positions
    if(positions.size()==0){
        return "";
    }

    std::string s;
    for(int i:positions){
        s.append(b.spot(i/4,i%4));
    }
    return s;
}

void DFS_path(Board &b, int node, std::vector<std::vector<int>> &adj, std::vector<int> path, Trie &t)
{
    //perform DFS to determine all words by determining all paths
    path.push_back(node);
    std::string word = get_word(b,path);
    if(!t.prefix_present(word)){
        return;
    }
    if(t.is_present(word)){
        dict.insert(word);
    }
    for(int i: adj[node]){
        if (std::find(path.begin(),path.end(),i)!= path.end()){
            continue;
        }
        DFS_path(b,i,adj,path,t);
    }
}

void init_adj(std::vector<std::vector<int>> &adj)
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

void get_words(Board &b,Trie &t){
    std::vector<std::vector<int>> adj;
    init_adj(adj);

    for(int i = 0;i<16;++i){
        std::cout<<"Starting at "<<b.spot(i/4,i%4)<<std::endl;
        std::vector<int> v;

        DFS_path(b,i,adj,v,t);
    }
    
}

void print_dict(){
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

int main(){
    // Board b;
    // b.shake();
    // Trie t("dictionary.txt");
    // print_board(b);
    // get_words(b,t);
    // print_dict();
}
