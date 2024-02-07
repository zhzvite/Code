#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e5+10;
typedef long long LL;
int a[N];
LL tr1[N],tr2[N];
int n,m;
int lowbit(int x){
    return x&-x;
}

void add(LL tr[],int x,int c){
    for(int i=x;i<=n;i+=lowbit(i))tr[i]+=c;   
}

LL sum(LL tr[],int x){
    LL res=0;
    for(int i=x;i>0;i-=lowbit(i))res+=tr[i];
    return res;
}
LL psum(int x){
    return sum(tr1,x)*(x+1)-sum(tr2,x);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    
    for(int i=1;i<=n;i++){
        int b=a[i]-a[i-1];
        add(tr1,i,b);
        add(tr2,i,(LL)b*i);
    }
    while(m--){
        char op[2];
        int l,r,d;
        scanf("%s%d%d",op,&l,&r);
        if(*op=='Q')printf("%lld\n",psum(r)-psum(l-1));
        else {
            scanf("%d",&d);
            add(tr1,l,d);
            add(tr2,l,(LL)l*d);
            add(tr1,r+1,-d);
            add(tr2,r+1,-(LL)(r+1)*d);
        }
    } 
}