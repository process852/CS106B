/*
Implement the function endsWith(str, suffix), which returns true if 
str ends with suffix. Like its startsWith counterpart, the endsWith
function should allow the second argument to be either a string or a character.
*/

#include <iostream>

using namespace std;
bool endsWith(string str, string suffix);
void test();

int main()
{
    test();
    return 0;
}

bool endsWith(string str, string suffix){
    // calculate length
    int str_len = str.length();
    int suffix_len = suffix.length();
    if (suffix_len > str_len){
        return false;
    }
    else{
        while(suffix_len > 0){
            if (str[--str_len] != suffix[--suffix_len]){
                return false;
            }
            suffix_len--;
            str_len--;
        }
        return true;
    }
}

void test(){
    cout << endsWith("Hello", "llo") << endl;
    cout << endsWith("Hello", "") << endl;
    cout << endsWith(string("World"), string("hello")) << endl;
    cout << endsWith(string("hello"), string("world hello")) << endl;
}