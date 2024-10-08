/*
std::pair 提供两个异质对象作为一个单元存储的途径
*/
#include <iostream>
#include <utility>
#include <string>
#include <map>
using namespace std;

void showMap(map<string, int> & data){
    cout << "{\n";
    for(const auto& [key, value] : data){
        cout << "    [" << key << ": " << value << "]" << endl;
    }
    cout << "}\n";
}
int main(){
    // example std::pair
    pair<string, int> p("Jack", 22);
    cout << p.first << endl; // 访问第一个元素
    cout << p.second << endl; // 访问第二个元素
    // 元组式访问元素
    cout << "(" << get<0>(p) << ", " << get<1>(p) << ")" << endl;

    map<string, int> map1;
    map1.insert({"Jack", 25});
    showMap(map1);
    map1.insert(next(map1.begin()), {"Lucy", 26});
    showMap(map1);
    map<string, int> map2({{"LLY", 20}, {"JJC", 18}});
    map1.insert(map2.begin(), map2.end());
    showMap(map1);
    // 元素擦除
    map1.erase("Lucy");
    showMap(map1);
    map1.erase(next(map1.begin()));
    showMap(map1);


    return 0;
}