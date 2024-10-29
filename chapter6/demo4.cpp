#include "tokenscanner.h"
#include <iostream>
#include <string>

using namespace std;

void test(){
    TokenScanner scanner;
    string message = "Hello World ! hehe ";
    scanner.setInput(message);
    while(scanner.hasMoreTokens()){
        cout << scanner.nextToken() << endl;
    }
}

int main(){
    test();
    return 0;
}