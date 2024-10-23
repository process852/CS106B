/*
Telephone numbers in the United States and Canada are organized into various 
three-digit area codes. A single state or province will often have many area 
codes, but a single area code will not cross a state boundary. This rule makes 
it possible to list the geographical locations of each area code in a data file. 
For this problem, assume that you have access to the file AreaCodes.txt, 
which lists all the area codes paired with their locations as illustrated by the 
first few lines of that file:
Using the AirportCodes program as a model, write the code necessary to 
read this file into a Map<int,string>, where the key is the area code and the 
value is the location. Once you’ve read in the data, write a main program that 
repeatedly asks the user for an area code and then looks up the corresponding 
location, as illustrated in the following sample run:
*/
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
using namespace std;


void seperateChar(string line, char c, int& code, string& location){
    int index = 0;
    for(int i = 0; i < line.length(); i++){
        if(line.at(i) == c){
            index = i;
            break;
        }
    }
    string number_string = line.substr(0, index);
    code = stol(number_string);
    location = line.substr(index + 1, line.length() - index - 1);
}


void readFile(map<int, string>& dict, const string fileName){
    fstream file;
    file.open(fileName.c_str());
    string line;
    if(file.fail()){
        cout << "file read error!" << endl;
        return;
    }
    while(getline(file, line)){
        int code;
        string location;
        seperateChar(line, '-', code, location);
        dict[code] = location;
    }
    return;
}

void showMap(const map<int, string> & dict){
    cout << "{" << endl;
    for(const auto& elem : dict){
        cout << elem.first << ": " << elem.second << "," << endl;
    }
    cout << "}" << endl;
}

int main(){
    string fileName = "./ArerCode.txt";
    map<int, string> dict;
    readFile(dict, fileName);
    showMap(dict);
    return 0;
}