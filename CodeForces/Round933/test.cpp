#include<iostream>
#include<queue>
using namespace std;
queue<int> s;
int main(){
    s.push(2);
    s.push(4);
    s.push(1);
    while(!s.empty()){
        cout << s.front() << endl;
        s.pop();
    }
}