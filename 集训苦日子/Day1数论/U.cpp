#include<iostream>
using namespace std;
typedef long long ll;
ll n,m;
const double lorry=(sqrt(5.0)+1.0)/2.0;
int main(){
    while(cin>>n>>m){
  //  cin>>n>>m;
    if(n>m)swap (n,m);
    ll a=m-n;
    if(n==int (lorry*(double)a))
    cout<<0<<endl;
    else cout<<1<<endl;}
}