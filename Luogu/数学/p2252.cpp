#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
ll n,m;
ll a;
const double lorry=(sqrt(5.0)+1.0)/2.0;
int main(){
    cin>>n>>m;
    if(n>m)swap (n,m);
     a=m-n;
    if(n==ll (lorry*(double)a))
    cout<<0<<endl;
    else cout<<1<<endl;
}