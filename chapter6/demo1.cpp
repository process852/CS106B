#include <iostream>
#include <string>

using namespace std;

class Point{
public:
    Point(){
    };
    Point(int cx, int cy){
        x = cx;
        y = cy;
    }
    int Getx(){
        return x;
    }
    int Gety(){
        return y;
    }
    void showPoint(){
        cout << "(" << x <<", " << y << ")" << endl;
    }
    friend ostream& operator<<(ostream& out, Point p);
private:
    int x;
    int y;
};

ostream& operator<<(ostream& out, Point p){
    out << "(" << p.x <<", " << p.y << ")";
    return out;
}

int main(){
    Point p(2,3);
    p.showPoint();
    cout << p << endl;
    return 0;
}