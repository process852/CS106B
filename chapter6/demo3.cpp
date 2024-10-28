/*
class Rational
*/
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


int gcd(int x, int y){
    int tmp;
    while(true){
        tmp = x % y;
        if (tmp == 0){
            return y;
        }
        x = y;
        y = tmp;
    }
}
class Rational{
public:
    Rational();
    Rational(int x, int y);
    Rational(int n);
    friend ostream& operator<<(ostream& out, Rational& r);
    Rational& operator+(Rational& r2);
    Rational& operator-(Rational& r2);
    Rational& operator*(Rational& r2);
    Rational& operator/(Rational& r2);


private:
    int num;
    int den;
    vector<int> _convert_input(int x, int y);
};

ostream& operator<<(ostream& out, Rational& r){
    cout << r.num << "/" << r.den << endl;
    return out;
}

Rational::Rational(){
    num = 0;
    den = 1;
}

Rational::Rational(int x, int y){
    auto item = this->_convert_input(x, y);
    num = item[0];
    den = item[1];
}

vector<int> Rational::_convert_input(int x, int y){
    if(y == 0){
        cerr << "Rational: Division by zero" << endl;
        exit(EXIT_FAILURE);
    }
    vector<int> data;
    if(x == 0){
        data.push_back(0);
        data.push_back(1);
    }
    else{
        int g = gcd(abs(x), abs(y));
        int num_ = x / g;
        int den_ = abs(y) / g;
        if (y < 0) num_ = -num_;
        data.push_back(num_);
        data.push_back(den_);
    }
    return data;
}

Rational::Rational(int n){
    num = n;
    den = 1;
}

Rational& Rational::operator+(Rational& r2){
    int x = this->num * r2.den + r2.num * this->den;
    int y = this->den * r2.den;
    auto item = this->_convert_input(x, y);
    this->num = item[0];
    this->den = item[1];
    return *this; // this 表示指针 ，*this表示对象本身
}

Rational& Rational::operator-(Rational& r2){
    int x = this->num * r2.den - r2.num * this->den;
    int y = this->den * r2.den;
    auto item = this->_convert_input(x, y);
    this->num = item[0];
    this->den = item[1];
    return *this; // this 表示指针 ，*this表示对象本身
}

Rational& Rational::operator*(Rational& r2){
    int x = this->num * r2.num;
    int y = this->den * r2.den;
    auto item = this->_convert_input(x, y);
    this->num = item[0];
    this->den = item[1];
    return *this; // this 表示指针 ，*this表示对象本身
}

Rational& Rational::operator/(Rational& r2){
    int x = this->num * r2.den;
    int y = this->den * r2.num;
    auto item = this->_convert_input(x, y);
    this->num = item[0];
    this->den = item[1];
    return *this; // this 表示指针 ，*this表示对象本身
}

void test(){
    Rational r1;
    Rational r2(2, 6);
    Rational r3(3);
    cout << r1 << r2 << r3 << endl;
    cout << r2 + r3 << endl;
    
    Rational r4(2, 6);
    Rational r5(3);
    cout << r4 - r5 << endl;

    Rational r6(2, 6);
    Rational r7(3);
    cout << r6 * r7 << endl;

    Rational r8(2, 6);
    Rational r9(3);
    cout << r8 / r9 << endl;

}

void test_gcd(){
    cout << gcd(2, 6) << endl;
    cout << gcd(2, 3) << endl;
    cout << gcd(12, 36) << endl;
}

int main(){
    //test_gcd();
    test();

    return 0;
}

