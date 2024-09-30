#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double PI = 3.1415926;

void printPrecisionTable(){
    for(int prec = 0; prec <=6; prec+=2){
        cout << setw(12) << PI << setprecision(prec) << PI << endl;
    }
}

