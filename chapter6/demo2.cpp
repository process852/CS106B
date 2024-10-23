#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
    double a = 1.0 / 2;
    double b = 1.0 / 3;
    double c = 1.0 / 6;
    double sum = a + b + c; // 浮点数表示的精度是有限的
    cout << setprecision(16);
    cout << "1/2 + 1/3 + 1/6 = " << sum << endl;
    return 0;
}