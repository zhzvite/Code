//反素数
#include<iostream>
using namespace std;
typedef long long ll;
int primes[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47
};
ll sum,minnum,maxsum;
ll n;
void dfs(ll num,ll sum,int k,int limit){
    if(sum>maxsum){
        maxsum=sum;
        minnum=num;
    }
   else  if(sum==maxsum&&num<minnum)minnum=num;
    else if(num>=minnum)return ;
    if(k==15)return ;
    for(int i=1;i<=limit;i++){
        num*=primes[k];
        if(num>n)break;
        dfs(num,sum*(i+1),k+1,i);
    }
}
int main(){
    while(cin>>n){
        maxsum=0;
        dfs(1,1,0,1000);
        cout<<minnum<<endl;
    }
}