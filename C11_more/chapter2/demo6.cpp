#include <iostream>
using namespace std;

// ... 表示不定长参数
template<typename ...Ts>
void magic(Ts... args){
    // sizeof... 计算不定长参数个数
    cout << sizeof...(args) << endl;
}
void test01(){
    magic();
    magic(1, "Hello"); // 可以接收任意数量、任意类型参数
    magic(2, 'c', 5.5);
}
int main(){
    test01();
    return 0;
}