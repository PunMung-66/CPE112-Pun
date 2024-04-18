 #include <iostream>
//#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

int main() {
    // test
    // cout << "Hello World\n";
    // int a;
    // cin >> a;
    // cout << a << endl; // end line = \n
    // queue<int> qq;
    // for (int i = 0; i < 10; i++) {
    //     qq.push(i);
    // }
    // cout << qq.size() << endl;
    // while (!qq.empty()) {
    //     cout << qq.front() << " ";
    //     qq.pop();
    // }

    // vector <int> li;
    // for (int i = 0; i < 10; i++) {
    //     li.push_back(i);
    // }
    // cout << li.size() << endl;
    // for (int i = 0; i < li.size(); i++) {
    //     cout << li[i] << " ";
    // }

    vector < vector <int> > li2;
    for (int i = 0; i < 10; i++) {
        vector <int> temp;
        for (int j = 0; j < 12; j++) {
            temp.push_back(j);
        }
        li2.push_back(temp);
    }
    cout << li2.size() << endl;
    cout << li2.at(0).size() << endl;
    cout << li2.at(0)[11] << endl;
    return 0;
}