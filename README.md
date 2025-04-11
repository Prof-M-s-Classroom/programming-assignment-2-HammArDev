[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jIKk4bke)
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name:** `Hamish Arora`  
### **Student ID:** `131233177`  

---

## **1. Project Overview**
In this project, I created a decision tree game using a binary tree structure. You can progress through the story by typing y or n
---

## **2. Folder & File Structure**
(Explain the role of each file in your project.)

- **`main.cpp`** → `Loads and runs the game`  
- **`GameDecisionTree.h`** → `This object is a binary tree, and consists of Nodes. It has functions to load the game, and run it`  
- **`Node.h`** → `The node has a story event, and pointers to link it to the  next events`  
- **`Story.h`** → `Contains the event, as well as node number data`  
- **`story.txt`** → `Input file for game`  

---

## **3. Decision Tree Construction**
(Explain how the decision tree is built from the `story.txt` file.)

- Story objects are created through their constructor, and stored in a Node.
- After parsing through the file, we'll have a list of Nodes.
- Then, I traverse the list, connecting the Nodes to the Story object specified leftNumber and rightNumber

-NOTE: -1 indicates NULL/no connection
-If a Story event has a -1 as the rightNumber only, then it'll act as an intermediate node
-You can use this to fill in the details before a shared node

---

## **4. Game Traversal**
-The player plays by typing 'y' or 'n'
Once they finish the game, the program ends.
If they reach a special, shared node, then they get to choose from its options.
So, a shared node enables you to get the same ending from 2 different paths

---

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)

- How is the file read and parsed using a delimiter?  
- How do you ensure nodes are properly linked?  
- Any challenges faced while handling file input?  

---

## **6. Debugging Process (Errors & Fixes)**
When I tried to test the intermediate nodes, I found out that they weren't read properly.
Thus, the node had a NULL left attribute. So, I checked the input file, and it was formatted incorrectly.
After fixing the format, the intermediate nodes worked
---

## **7. Sample Output & Walkthrough**
You're starting to take your walk. Suddenly, you feel a drop of water hit your eyebrow. Do you turn back(y/n)?
n

You continued, and the drizzle got you slightly drenched-> While walking, you see a man trying to clean up a huge mess.
Help him(y/n)?
y

He was suffering from a panic attack-> You decide to drive him to the hospital, and run into traffic-> Should you run t
o the hospital or wait it out(y\n for run)
n

You drive, and the man feels hungry. Drive to Rubios(y/n)?
y

He reaches for a snack in his pocket(c to continue)
It turns to dusk. The man starts to choke, step on the gas or stop and help out(y for gas)?
c

Your passenger hits their head. Check on them or continue driving(y for checking)?
n

He wakes up, but is still panicking(c to continue)
You're able to talk the man down, and find out that they're playing Mariokart in the hospital. You have a good time the
re :)

---

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

- **Loading the tree from the file** → `O(?)`- You read through n events
- And, in the worst case, for each node(O(n)), you search the list of nodes twice(2n=O(n))
- Therefore, it's O(n)*O(n) = O(n^2)
- **Searching for an event in the tree** → `O(n)`  as the tree isn't balanced
- **Game traversal efficiency** → `O(n)`  Though it depends on the height of the tree, in the worst case, all events are sequential
- Yielding O(n) time

---

## **9. Edge Cases & Testing**
(Describe at least one edge case you tested and its outcome.)
-I tested the scenario where the player reached a leaf node, and the game ended as I expected
-I tested intermediate nodes. One wasn't printing, and from that, I found out that I forgot the print statement
-Lastly, I tested the nodes that shared a child. They worked :)
Example:
> I tested a scenario where the player reaches a dead-end (leaf node) and ensured the program correctly ends the game.

---

## **10. Justification of Additional Features (If Any)**
None
## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
