#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll tr1[N],tr2[N];
int n,m;
ll a[N];
ll l,r;
int lowbit(int x){
    return x&-x;
}
ll sum(ll tr[],int x){
   ll res=0;
   for(int i=x;i>0;i-=lowbit(i))res+=tr[i];
   return res;
}
ll p_sum(int l,int r){
    return sum(tr1,r)*(r+1)-sum(tr2,r)-sum(tr1,l-1)*l+sum(tr2,l-1);
}
void add(ll tr[],int x,ll c){
    for(int i=x;i<=n;i+=lowbit(i))tr[i]+=c;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        add(tr1,i,a[i]-a[i-1]),add(tr2,i,(ll)i*(a[i]-a[i-1]));
    }
    while(m--){
       int tag;
    scanf("%d",&tag);
    if(tag==1){
        ll c;
        scanf("%lld%lld%lld",&l,&r,&c);
        add(tr1,l,c),add(tr1,r+1,-c),add(tr2,l,l*c),add(tr2,r+1,(r+1)*-c);
    }
    if(tag==2){
    scanf("%lld%lld",&l,&r);
   printf("%lld\n",p_sum(l,r));
    }  
    }
   
}