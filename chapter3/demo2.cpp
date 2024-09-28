/*
The strlib.h function exports a function trim(str) that returns a new 
string formed by removing all whitespace characters from the beginning and 
end of str. Write the corresponding implementation.
*/

#include <iostream>
#include <string>
using namespace std;
string trim(string str);
void test();

int main(){
    test();
    return 0;
}

string trim(string str){
    string new_string;
    int pos = 0;
    int substr_count = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == ' '){
            if (substr_count > 0){
                new_string += str.substr(pos, substr_count);
            }
            pos = i + 1;
            substr_count = 0;
        }
        else{
            substr_count++;
        }
    }
    if(substr_count > 0){
        new_string += str.substr(pos, substr_count);
    }
    return new_string;
}

void test(){
    cout << trim("Hello World") << endl;
    cout << trim("  Hello") << endl;
    cout << trim("  Hello  ") << endl;
    cout << trim(" Hello  World    ") << endl;
}