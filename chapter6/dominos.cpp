#include "dominos.h"
#include <cctype>
using namespace std;

Dominos::Dominos(){
    this->leftDots = 0;
    this->rightDots = 0;
}
Dominos::Dominos(int x, int y){
    this->leftDots = x;
    this->rightDots = y;
}

std::string Dominos::toString(){
    return string(to_string(this->leftDots)) + 
        string("-") + 
        string(to_string(this->rightDots));
}
int Dominos::getLeftDots(){
    return this->leftDots;
}
int Dominos::getRightDots(){
    return this->rightDots;
}
std::ostream& operator<<(std::ostream& output, Dominos& d){
    output << d.toString() << endl;
    return output;
}