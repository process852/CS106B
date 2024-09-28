/*
Write a function createRegularPlural(word) that returns the plural of 
word formed by following these standard English rules:
a. If the word ends in s, x, z, ch, or sh, add es to the word.
b. If the word ends in a y preceded by a consonant, change the y to ies.
c. In all other cases, add just an s.
Write a test program and design a set of test cases to verify that your program 
works.
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool endWith(string str, string suffix){
    int suffix_len = suffix.length() - 1;
    int str_len = str.length() - 1;
    while(suffix_len >= 0){
        if (str[str_len] != suffix[suffix_len]){
            return false;
        }
        str_len--;
        suffix_len--;
    }
    return true;

}
string createRegularPlural(string word){
    vector<string> elements = {"s", "x", "z", "ch", "sh"};
    bool flag = false;
    for(string& s : elements){
        flag = flag || endWith(word, s);
    }
    if(flag)
        return word + "es";
    unordered_set vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    if(endWith(word, "y") && (!vowel.count(word[word.length() - 2]))){
        return word.substr(0, word.length() - 1) + "ies";
    }
    return word + "s";
}
void test(){
    cout << createRegularPlural("cat") << endl;
    cout << createRegularPlural("Bus") << endl;
    cout << createRegularPlural("City") << endl;
    cout << createRegularPlural("Boy") << endl;
}
int main(){
    test();
    return 0;
}