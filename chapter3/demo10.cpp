/*
When large numbers are written out on paper, it is traditional—at least in the 
United States—to use commas to separate the digits into groups of three. For 
example, the number one million is usually written in the following form:
1,000,000
To make it easier for programmers to display numbers in this fashion, 
implement a function
string addCommas(string digits);
that takes a string of decimal digits representing a number and returns the 
string formed by inserting commas at every third position, starting on the 
right. For example, if you were to execute the main program
int main() {
 while (true) {
 string digits;
 cout << "Enter a number: ";
 getline(cin, digits);
 if (digits == "") break;
 cout << addCommas(digits) << endl;
 }
 return 0;
}
your implementation of the addCommas function should be able to produce the 
following sample run:
*/

#include <iostream>
#include <string>
using namespace std;

// string addCommas(string digits);

string addCommas(string digits){
    if (digits.length() <= 3){
        return digits;
    }
    return addCommas(digits.substr(0, digits.length() - 3)) 
                + "," + digits.substr(digits.length() - 3, 3);
}

int main(){
    while(true){
        string digits;
        cout << "Enter a number: ";
        getline(cin, digits);
        if (digits == "") break;
        cout << addCommas(digits) << endl;
    }
    return 0;
}
