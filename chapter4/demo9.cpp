/*
Write a program 
that asks the user for an input file, an output file, and a string of letters to be 
eliminated. The program should then copy the input file to the output file, 
deleting any of the letters that appear in the string of censored letters, no 
matter whether they appear in uppercase or lowercase form.
If you try to get greedy and banish all the vowels by entering aeiou in 
response to the prompt, the contents of the output file would be
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool checkInString(string str, char c){
    for(auto& elem : str){
        if(elem == c){
            return true;
        }
    }
    return false;
}
void deleteSaveFile(string fileName, string saveFileName, string checkString){
    ifstream file(fileName);
    if(file.fail()){
        cout << "reading error!" << endl;
    }
    ofstream outFile(saveFileName);
    char c;
    while((c = file.get()) != EOF){
        if (!checkInString(checkString, c)){
            outFile.put(c);
        }
    }
    file.close();
    outFile.close();
}

int main(){
    deleteSaveFile("demo.txt", "demo1.txt", "os");
    return 0;
}