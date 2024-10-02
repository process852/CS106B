/*
The <iomanip> library gives programmers more control over output format, 
which makes it easy, for example, to create formatted tables. Write a program 
that displays a table of trigonometric sines and cosines that looks like this:
The numeric columns should all be aligned on the right, and the columns 
containing the trigonometric functions (which are listed here for angles at 
15-degree intervals) should all have seven digits after the decimal point.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void coutMid(double value, int width, int precisionWidth){
    int number_length = to_string(value).length();
    int padding = (width - number_length) / 2;
    cout << setw(padding) << setfill(' ') << "";
    if((width - number_length) % 2 != 0)
        cout << " ";
    cout << setprecision(precisionWidth) << value << setw(padding) << setfill(' ') << "";
}
void coutMid(int value, int width){
    int number_length = to_string(value).length();
    int padding = (width - number_length) / 2;
    cout << setw(padding) << setfill(' ') << "";
    if((width - number_length) % 2 != 0)
        cout << " ";
    cout << right << value << setw(padding) << setfill(' ') << "";
}
void showSinCos(){
    cout << " theta | sin(theta) | cos(theta) |" << endl;
    cout << "-------+------------+------------+" << endl;
    const double PI = acos(-1);
    for(double i = -90; i <= 90; i += 15){
        cout << fixed;
        coutMid((int) i, 7);
        cout << "|";
        coutMid(sin(i / 180.0 * PI), 11, 7);
        cout << "|";
        coutMid(cos(i / 180.0 * PI), 11, 7);
        cout << "|" << endl;
    }
}

int main(){
    showSinCos();
    return 0;
}