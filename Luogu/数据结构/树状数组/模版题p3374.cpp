//单点修改,区间查询
#include<iostream>
#include<cstdio>
using namespace std;
const int N=5e5+10;
typedef long long LL;
int a[N];
LL tr[N];
int n,m;
int lowbit(int x){
    return x&-x;
}
void add(int x ,int c){
    for(int i=x;i<=n;i+=lowbit(i))tr[i]+=c;
}
LL sum(int x){
   LL res=0;
   for(int i=x;i;i-=lowbit(i))res+=tr[i];
   return res;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        add(i,a[i]);
        }
    while(m--){
        int t,l,r;
        scanf("%d%d%d",&t,&l,&r);
        if(t==1)add(l,r);
        else   printf("%lld\n",sum(r)-sum(l-1)); 
    }   
}