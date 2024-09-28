/*
An acronym is a new word formed by combining, in order, the initial letters of 
a series of words. For example, the word scuba is an acronym formed from 
the first letters in self-contained underwater breathing apparatus. Similarly, 
AIDS is an acronym for Acquired Immune Deficiency Syndrome. Write a
function acronym that takes a string and returns the acronym formed from 
that string. To ensure that your function treats hyphenated compounds like 
self-contained as two words, it should define the beginning of a word as any 
alphabetic character that appears either at the beginning of the string or after a 
nonalphabetic character.
*/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string acronym(const string str){
    string new_string;
    int pos;
    int wordCount = 0;
    for(int i = 0; i < str.length(); i++){
        if (isalpha(str[i])){
            if (wordCount == 0){
                pos = i;
            }
            wordCount += 1;
        }
        else{
            if(wordCount > 0){
                new_string += str[pos];
                wordCount = 0;
                pos = i + 1;
            }
            pos++;
        }
    }
    if(wordCount > 0)
        new_string += str[pos];
    return new_string;
}

void test(){
    cout << acronym("Acquired Immune Deficiency Syndrome") << endl;
    cout << acronym("self-contained underwater breathing apparatus") << endl;
}

int main(){
    test();
    return 0;
}