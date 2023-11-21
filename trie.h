#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <memory>

#include "trie_node.h"
class Trie{
    public:
        std::unique_ptr<Trie_Node> adj[26];
        Trie(std::string file_name);
//        ~Trie();
        void insert(std::string s);
        bool is_present(std::string s);
        bool prefix_present(std::string s);
    private:
//        void delete_tree(Trie_Node* t);
};

#endif
