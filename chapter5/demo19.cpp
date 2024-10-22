#include <iostream>
#include <string>
#include <map>
#include <cctype>
using namespace std;

const map<char, string> codeTable = {
    {'A', ". -"},
    {'B', "- . . ."},
    {'C', "- . - ."},
    {'I', ". ."},
    {'N', "- ."},
    {'O',"- - -"},
    {'S', ". . ."},
    {'T', "-"},
};

string translateMessage(string & line){
    bool isLetters;
    for(int index = 0; index < line.length(); index++){
        char c = line.at(index);
        if(c == ' ')
            continue;
        else if (c == '.' || c == '-'){
            isLetters = false;
            break;
        }
        else if (isalpha(c)){
            isLetters = true;
            break;
        }
    }
    if(isLetters){
        string morseCode;
        for(int index=0; index < line.length(); index++){
            char c = line[index];
            if(! isalpha(c)){
                continue;
            }
            else{
                string tmp = codeTable.at(c);
                morseCode += tmp;
            }
        }
        return morseCode;

    }
    else{
        return "None";
    }
}

int main(){
    cout << "Morse code Translator: " << endl;
    while(true){
        string line;
        getline(cin, line);
        if(! line.length())
            break;
        string output = translateMessage(line);
        cout << output << endl;
    }
    return 0;
}