/*
Write a program that reads a file and reports how many lines, words, and 
characters appear in it. For the purposes of this program, a word consists of a 
consecutive sequence of any characters except whitespace characters. As an 
example, suppose that the file Lear.txt contains the following passage from 
Shakespeare’s King Lear,
your program should be able to generate the following sample run:
The counts in the output should be displayed in a column that is aligned on 
the right but which expands to fit the data. For example, if you have a file 
containing the full text of George Eliot’s Middlemarch, the output of your 
program should look like this:
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <iomanip>
using namespace std;

bool contain(vector<char> & v, char c){
    for(auto& elem : v){
        if(elem == c){
            return true;
        }
    }
    return false;
}
void calculateWords(string fileName){
    ifstream file(fileName);
    string line;
    int lines, words, chars;
    lines = words = chars = 0;
    vector<char> hasChars;
    bool flag = false;
    int left, right;
    while(getline(file, line)){
        left = right = 0;
        while(right < line.length()){
            if(!contain(hasChars, line[right])){
                hasChars.push_back(line[right]);
            }
            if(line[right] == ' '){
                if (left == right){
                    if (flag){
                        words++;
                        flag = false;
                    }
                    left++;
                    right++;
                }
                else{
                    words++;
                    left = right;
                }
            }
            else{
                right++;
            }
        }
        if (right > left){
            flag = true;
        }
        lines++;
    }
    words = right > left ? words + 1 : words;
    chars = hasChars.size();
    int width = max(chars, words);
    width = max(width, lines);
    width = to_string(width).length();
    std::cout << "Chars: " << setw(width + 1) << chars << endl;
    std::cout << "Words: " << setw(width + 1) << words << endl;
    std::cout << "Lines: " << setw(width + 1) << lines << endl;
}
int main(){
    calculateWords("Lear.txt");
    return 0;
}