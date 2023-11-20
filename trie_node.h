#ifndef TRIE_NODE_H
#define TRIE_NODE_H

class Trie_Node{
    
    public:
        char c;
        bool ends_word;
        Trie_Node* adj[26];
        Trie_Node(char c);
};

#endif