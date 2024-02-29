#include<iostream>
using namespace std;
typedef long long ll;
ll n;
void find(ll x){
    //找到小于x的最大2的倍数
    ll res = 1;
    for (int i = 1; i <= 1000;i++)
    {
        if(res<=x)
        res *= 2;
        else{
            cout << res / 2<<endl;
            return;
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        find(n);
    }
}