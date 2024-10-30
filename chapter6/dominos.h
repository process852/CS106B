/*
The game of dominos is played using pieces that are usually black rectangles 
with some number of white dots on each side. For example, the domino
is called the 4-1 domino, with four dots on its left side and one on its right.
Define a simple Domino class that represents a traditional domino. Your 
class should export the following entries:
• A default constructor that creates the 0-0 domino
• A constructor that takes the number of dots on each side
• A toString method that creates a string representation of the domino
• Two getter methods named getLeftDots and getRightDots

Write the domino.h interface and the domino.cpp implementation that 
export this class. As with the examples in the text, all instance variables 
should be private to the class, and the interface should overload the <<
operator so that it is possible to print a string representation of a domino.
Test your implementation of the Domino class by writing a program that 
creates a full set of dominos from 0-0 up to 6-6 and then displays those 
dominos on the console. A full set of dominos contains one copy of each 
possible domino in that range, disallowing duplicates that result from flipping 
a domino over. A domino set, therefore, has a 4-1 domino but not a separate 
1-4 domino.
*/

#ifndef _DOMINOS_H
#define _DOMINOS_H
#include <iostream>
#include <string>

class Dominos{
public:
    Dominos();
    Dominos(int x, int y);
    std::string toString();
    int getLeftDots();
    int getRightDots();
    friend std::ostream& operator<<(std::ostream& output, Dominos& d);
private:
    int leftDots;
    int rightDots;

};


#endif