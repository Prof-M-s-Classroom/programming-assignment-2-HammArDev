#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H
using namespace std;
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

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
        vector<Node<Story>*>* nodes = new vector<Node<Story>*>();
        string desc, test;
        int eventNum, left, right, i;
        fstream fin;
        fin.open(filename);
        while(fin.peek()!=EOF){
            fin>>eventNum;
            getline(fin, test, delimiter);
            getline(fin, desc, delimiter);
            fin>>left;
            getline(fin, test, delimiter);
            fin>>right;
            Story event(desc, eventNum, left, right);
            Node<Story>* eventNode = new Node(event);
            nodes->push_back(eventNode);
        }
        cout<<"Awesome!"<<endl;
        cout.flush();
        for (i=0; i<nodes->size(); ++i) {
            Node<Story>* curr = nodes->at(i);
            left = curr->data.leftEventNumber;
            if (left<0) {
                continue;
            }
            right = curr->data.rightEventNumber;
            //Find the left and right nodes
            //NOTE: Did this because the events may be out of order
            //Using a priority queue might have been better
            for (int j=0; j<nodes->size(); ++j) {
                Node<Story>* ptr = nodes->at(j);
                if (ptr->data.eventNumber==left) {
                    //Connect them
                    curr->left = ptr;
                }
                if (right>0 && ptr->data.eventNumber==right) {
                    //Connect them
                    curr->right = ptr;
                }
            }
        }
        root = nodes->at(0);
        cout<<"Awesome :)"<<endl;
    }

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        Node<Story>* curr = root;
        cout<<curr->data.print()<<endl;
        char in;
        while (curr->left || curr->right) {
            if (curr->right) {
                cin >> in;
                if (in=='y') {
                    curr=curr->left;
                    cout<<curr->data.print()<<endl;
                }else {
                    curr = curr->right;
                    cout<<curr->data.print()<<endl;
                }
            }else {
                curr=curr->left;
                cout<<curr->data.print()<<endl;
            }
        }
    }
};

#endif // GAMEDECISIONTREE_H