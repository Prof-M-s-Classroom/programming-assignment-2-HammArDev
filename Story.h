#ifndef STORY_H
#define STORY_H

#include <string>
using namespace std;
class Story {
public:
    string description;
    int eventNumber;
    int leftEventNumber;
    int rightEventNumber;

    // Default constructor
    Story():description(""), eventNumber(0), leftEventNumber(-1), rightEventNumber(-1) {}

    // Parameterized constructor
    Story(string desc, int num, int leftNum, int rightNum)
        :description(desc), eventNumber(num), leftEventNumber(leftNum), rightEventNumber(rightNum)
    {}

    void changeDesc(string desc) {
        description = desc;
    }
    string print() {
        return description;
    }
};

#endif // STORY_H