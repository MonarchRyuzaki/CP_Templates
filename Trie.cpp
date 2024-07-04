#include <bits/stdc++.h>
using namespace std;

class Node {
private:
    Node* children[26];
    bool endsHere;
public:
    Node () {
        endsHere = false;
        for (int i=0; i<26; i++) children[i] = nullptr;
    }
    bool hasChild(int x) {
        return children[x];  
    }
    void createChild(int x) {
        children[x] = new Node();
    }
    Node* getChild(int x){
        return children[x];
    }
    void eraseChild(int x) {
        children[x] = nullptr;
    }
    bool canErase(){
        bool flag = true;
        for (int i=0; i<26; i++){
            flag &= (!children[i]);
        }
        return flag && !endsHere;
    }
    void unsetEnd(){
        endsHere = false;
    }
    void setEnd() {
        endsHere = true;
    }
    bool isEnd() {
        return endsHere;
    }
};

class Trie {
private:
    Node* root;
    bool eraseRec(string word, int idx, Node* root) {
        if (idx == word.size()){
            root->unsetEnd();
            return root->canErase();
        }
        bool canEraseChild = eraseRec(word, idx+1, root->getChild(word[idx] - 'a'));
        if (canEraseChild) {
            root->eraseChild(word[idx]-'a');
        }
        return root->canErase();
    }
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for (auto &c: word) {
            if (!curr->hasChild(c-'a')) {
                curr->createChild(c-'a');
            } 
            curr = curr->getChild(c-'a');
        }
        curr->setEnd();
    }

    bool search(string word) {
        Node* curr = root;
        for (auto &c: word) {
            if (!curr->hasChild(c-'a')) {
                return false;
            } 
            curr = curr->getChild(c-'a');
        }
        return curr->isEnd();
    }

    void erase(string word) {
        if (!search(word)) return;
        eraseRec(word, 0, root);
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for (auto &c: prefix) {
            if (!curr->hasChild(c-'a')) {
                return false;
            } 
            curr = curr->getChild(c-'a');
        }
        return true;
    }
};