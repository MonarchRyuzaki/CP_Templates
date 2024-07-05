#include <bits/stdc++.h>
using namespace std;`

class Node {
    Node* children[2];
    bool endsHere;
public:
    Node(){
        endsHere = false;
        for (int i=0; i<2; i++) children[i] = nullptr;
    }
    bool hasChild(int i) {
        return children[i];
    }
    void createChild(int i) {
        children[i] = new Node();
    }
    Node* getChild(int i){
        return children[i];
    }
    void setEnd(){
        endsHere = true;
    }
};

class Trie{
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node* curr = root;
        for (int i=31; i>=0; i--){
            int bit = (num >> i) & 1;
            if (!curr->hasChild(bit)) {
                curr->createChild(bit);
            }
            curr = curr->getChild(bit);
        }
        curr->setEnd();
    }
    int getXOR(int val) {
        int xr = 0;
        Node* curr = root;
        for (int i=31; i>=0; i--){
            int bit = (val >> i) & 1;
            if (bit) {
                if (curr->hasChild(0)) {
                    curr = curr->getChild(0);
                } else {
                    xr |= (1 << i);
                    curr = curr->getChild(1);
                }
            } else {
                if (curr->hasChild(1)) {
                    xr |= (1 << i);
                    curr = curr->getChild(1);
                } else {
                    curr = curr->getChild(0);
                }
            }
        }
        return xr ^ val;
    }
};