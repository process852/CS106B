#include "dominos.h"


void test(){
    using namespace std;
    Dominos instance1;
    Dominos instance2(4, 1);

    cout << instance1 << endl;
    cout << instance2 << endl;
    cout << instance2.getLeftDots() << instance2.getRightDots() << endl;

}
int main(){
    test();
    return 0;
}