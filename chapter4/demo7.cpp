/*
On occasion, publishers find it useful to evaluate layouts and stylistic designs 
without being distracted by the actual words. To do so, they sometimes 
typeset sample pages in such a way that all of the original letters are replaced 
with random letters. The resulting text has the spacing and punctuation 
structure of the original, but no longer conveys any meaning that might get in 
the way of the design. The publishing term for text that has been replaced in 
this way is greek, presumably after the old saying “It’s all Greek to me,” 
which is itself adapted from a line from Julius Caesar.
Write a program that reads characters from an input file and displays them 
on the console after making the appropriate random substitutions. Your 
program should replace every uppercase character in the input by a random 
uppercase character and every lowercase character by a random lowercase 
one. Nonalphabetic characters should remain unchanged. For example, if the 
input file Troilus.txt contains the text from Troilus and Cressida,
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <random>
using namespace std;

void replaceChar(string fileName){
    ifstream file(fileName);
    if (file.fail()){
        cout << "error !" << endl;
        return;
    }
    char c;
    char Array[26];
    for(int i = 0; i < 26; i++){
        Array[i] = 'a' + i;
    }
    while((c = file.get()) != EOF){
        if(isalpha(c)){
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> dis(0, 25);
            int random_number = dis(gen);
            if (c >= 'a' && c <= 'z'){
                cout.put(Array[random_number]);
            }   
            else if (c >= 'A' && c <= 'Z'){
                cout.put(Array[random_number] - ('a' - 'A'));
            }

        }
        else{
            cout.put(c);
        }
    }
}

int main(){
    replaceChar("demo.txt");
    return 0;
}