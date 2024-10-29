#include <iostream>
#include <string>
#include <cctype>
#include "tokenscanner.h"

using namespace std;

TokenScanner::TokenScanner(){

}

TokenScanner::TokenScanner(string str){
    this->setInput(str);
}

void TokenScanner::setInput(string str){
    this->buffer = str;
    this->cp = 0;
}

void TokenScanner::skipWhiteSpace(){
    while(cp < this->buffer.length() && isspace(this->buffer[cp])){
        ++cp;
    }
}

bool TokenScanner::hasMoreTokens(){
    if(ignoreWhiteSpaceFlag) this->skipWhiteSpace();
    return cp < buffer.length();
}

void TokenScanner::ignoreWhiteSpace(){
    this->ignoreWhiteSpaceFlag = true;
}

string TokenScanner::nextToken(){
    if(ignoreWhiteSpaceFlag) this->skipWhiteSpace();
    if(cp >= buffer.length()){
        return "";
    }
    else if (isalnum(buffer[cp])){
        int start = cp;
        while(cp < buffer.length() && isalnum(buffer[cp])){
            cp++;
        }
        return buffer.substr(start, cp - start);
    }
    else{
        return string(1, buffer[cp++]);
    }
}