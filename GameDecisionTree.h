#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"

template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter){
        string word, test;
        fstream fin(filename);
        while(fin>>test){
            get(fin, word, delimiter);
            cout<<word<<endl;
        }
    }

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        Node<T>* curr = root;
        char in;
        while (curr->left || curr->right) {
            //curr->data->print();
            if (!curr->right) {
                cin >> in;
                if (in=='y') {
                    curr=curr->left;
                }else {
                    curr = curr->right;
                }
            }else {
                curr=curr->left;
            }
        }
    }
};

#endif // GAMEDECISIONTREE_H