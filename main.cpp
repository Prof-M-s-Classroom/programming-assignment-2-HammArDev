#include <iostream>
#include <string>
#include "GameDecisionTree.h"
#include <list>
#include "Story.h"
using namespace std;
int main() {
    GameDecisionTree<Story> myGame;

    string filename = "C:\\Users\\sanga\\programming-assignment-2-HammArDev\\story.txt";  // Specify the input file
    char delimiter = '|';                // '|' is the delimiter, change if needed
    // Load the story data from the file
    myGame.loadStoryFromFile(filename, delimiter);

    // Start the game
    myGame.playGame();

    return 0;
}