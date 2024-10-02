#include <iostream>
#include <fstream>

using namespace std;

string promptUserForFile(ifstream & input, string prompt){
    while(true){
        cout << prompt;
        string filename;
        getline(cin, filename);
        input.open(filename.c_str());
        if (!input.fail()) return filename;
        input.clear();
        cout << "Unable to open that file. Try again." << endl;
        if(prompt == "") prompt = "Input file: ";
    }
}

int main(){
    ifstream input;
    promptUserForFile(input, "Input file: ");
    char ch;
    while(input.get(ch)){
        cout.put(ch);
    }
    input.close();
    return 0;
}


