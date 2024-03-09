/*
当n>=4,n=p1+p2
output :the number of pairs;
6=3+3
10 =3+7=5+5
12=5+7
把素数筛出来,然后遍历每一个在2~n/2,之间的素数a[i],若n-a[i]还是素数,那cnt++
*/
#include<iostream>
#include<map>
using namespace std;
const  int N=2e5+10;
int cnt;
int p[N];
bool st[N];
map<int,int >mp;
void get_primes(int n){
for(int i=2;i<=n;i++){
    if(!st[i]){p[cnt++]=i;
    mp[i]++;
    }
    for(int j=0;p[j]<=n/i;j++){
        st[p[j]*i]=true;
        if(i%p[j]==0)break;
    }
}
}
int main(){
    int n=2e5+10;
    get_primes(n);
    int res;
    while(cin>>n&&n!=0){
        res=0;
        for(int i=1;i<=cnt;i++){
            if(p[i]>n/2)break;
            if(mp[n-p[i]]>0)res++;
        }
        cout<<res<<endl;
    }
}