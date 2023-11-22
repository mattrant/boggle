#include <stdio.h>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>

#include "trie.h"
#include "trie_node.h"

Trie::Trie(std::string file_name)
{
    for(int i = 0;i<26;++i){
        adj[i] = std::unique_ptr<Trie_Node> (new Trie_Node(char(i+int('A'))));
    }


    std::ifstream infile(file_name);
    std::string line;
    while(std::getline(infile,line)){
        if(std::all_of(std::begin(line),std::end(line),[](char c){return std::isalpha(c);})){
            this->insert(line);
        }   
    }
  
}

void Trie::insert(std::string s)
{
    assert(s.size()!=0);
    std::transform(s.begin(),s.end(),s.begin(),::toupper);

    Trie_Node* curr = adj[int(s[0])-int('A')].get();
    for(unsigned int i =1; i<s.size();++i){
        int index = int(s[i])-int('A');
        if(curr->adj[index] == NULL){
            curr->adj[index] = std::unique_ptr<Trie_Node>(new Trie_Node(s[i]));
        }
        curr = curr->adj[index].get();
    }
    curr->ends_word = true;
}
bool Trie::is_present(std::string s) const{
    
    assert(s.size()!=0);
    std::transform(s.begin(),s.end(),s.begin(),::toupper);
    
    Trie_Node* curr = adj[int(s[0])-int('A')].get();
    for(unsigned int i =1;i<s.size();++i){
        int index = int(s[i])-int('A');
        if(curr->adj[index] == NULL)
            return false;
        curr=curr->adj[index].get();
    }
    return curr->ends_word;

}

bool Trie::prefix_present(std::string s) const{
    assert(s.size()!=0);
    std::transform(s.begin(),s.end(),s.begin(),::toupper);

    Trie_Node* curr = adj[int(s[0])-int('A')].get();
    for(unsigned int i =1;i<s.size();++i){
        int index = int(s[i])-int('A');
        if(curr->adj[index] == NULL)
            return false;
        curr=curr->adj[index].get();
    }
    return true;
}

//void Trie::delete_tree(Trie_Node* t)
//{
//    for(int i = 0;i<26;++i){
//        if(t->adj[i]!=NULL)
//            delete_tree(t->adj[i]);
//    }
//    delete t;
//}

//Trie::~Trie(){
//    for(int i=0;i<26;++i){
//       delete_tree(this->adj[i]);
//    }
//}
