/*
Write a function
string removeCharacters(string str, string remove);
that returns a new string consisting of the characters in str after removing all 
instances of the characters in remove. For example, if you call
removeCharacters("counterrevolutionaries", "aeiou")
the function should return "cntrrvltnrs", which is the original string after 
removing all of its vowels.

In the early part of the 20th century, there was considerable interest in both 
England and the United States in simplifying the rules used for spelling 
English words, which has always been a difficult proposition. One suggestion 
advanced as part of this movement was to eliminate all doubled letters, so that 
bookkeeper would be written as bokeper and committee would become comite. 
Write a function removeDoubledLetters(str) that returns a new string in 
which any duplicated characters in str have been replaced by a single copy.
*/

#include <iostream>
#include <string>

using namespace std;

string removeCharacters(string str, string remove){
    string new_string;
    for(int i = 0; i < str.length(); i++){
        if (remove.find(str[i]) == string::npos){
            new_string += str[i];
        }
    }
    return new_string;
}

void removeCharactersInPlace(string & str, string remove){
    int last_index = 0;
    while(true){
        bool flag = true;
        for(int i = last_index; i < str.length(); i++){
            if (remove.find(str[i]) != string::npos){
                str.erase(i, 1);
                last_index = i;
                flag = false;
                break;
            }
        }
        if (flag){
            break;
        }
    }
}

string removeDoubledLetters(string str){
    string new_string;
    int start, end;
    start = end = 0;
    while(end < str.length()){
        if(str[start] == str[end]){
            end++;
        }
        else{
            new_string += str[start];
            start = end;
        }
    }
    if (end > start){
        new_string += str[start];
    }
    return new_string;
}

void test(){
    cout << removeCharacters("counterrevolutionaries", "aeiou") << endl;
    string name = "counterrevolutionaries";
    removeCharactersInPlace(name, "aeiou");
    cout << name << endl;
    cout << removeDoubledLetters("bookkeeper") << endl;
    cout << removeDoubledLetters("committee") << endl;
}
int main(){
    test();
    return 0;
}