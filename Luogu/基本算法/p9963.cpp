#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    double n, p, l, r;
    cin >> n >> p >> l >> r;
    cout << fixed << setprecision(6) << (r - l + 1) * p;
}