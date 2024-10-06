/*
Write the overloaded functions
void readVector(istream & is, Vector<int> & vec);
void readVector(istream & is, Vector<double> & vec);
void readVector(istream & is, Vector<string> & vec);
each of which reads lines from the input stream specified by is into the vector 
vec. In the input stream, each element of the vector appears on a line of its 
own. The function should read elements until it encounters a blank line or the 
end of the file.
To illustrate the operation of this function, suppose that you have the data 
file
and that you have opened infile as an ifstream on that file. In addition, 
suppose that you have declared the variable roots as follows:
Vector<double> roots;
The first call to readVector(infile, roots) should initialize roots so 
that it contains the four elements shown at the beginning of the file. The 
second call should change the value of roots so that it contains the eight 
elements shown at the end of the file. Calling readVector a third time 
should set roots to an empty vector.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

void readVector(istream & is, vector<string> & vec){
    string line;
    while(getline(is, line)){
        if(line == "")
            break;
        vec.push_back(line);
    }
}
void showVector(vector<string> & data){
    for(auto& elem : data){
        cout << fixed << setw(8) << elem;
    }
    cout << endl;
}

int main(){
    ifstream file("data.txt");
    if (file.fail())
        cout << "file reading error!" << endl;
    vector<string> data;
    readVector(file, data);
    showVector(data);
    readVector(file, data);
    showVector(data);
    readVector(file, data);
    showVector(data);
    file.close();
    return 0;
}

