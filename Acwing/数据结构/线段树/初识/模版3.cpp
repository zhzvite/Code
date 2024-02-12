#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=5e5+10;
LL w[N];
struct node{
    int l,r;
    LL  sum,d;
}tr[4*N];
int n,m;

LL gcd(LL a,LL b){
  return b?gcd(b,a%b): a;
}
void pushup(node &u,node &l,node &r){
    u.sum=l.sum+r.sum;
    u.d=gcd(l.d,r.d);
}
void pushup(int u){
    pushup(tr[u],tr[u<<1],tr[u<<1|1]);
}
void build(int u,int l,int r){
    if(l==r){
        LL b=w[l]-w[l-1];
        tr[u]={l,r,b,b};
    }
    else {
        tr[u]={l,r};
        int mid=l+r>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        pushup(u);
    }
}
void modify(int u,int x,LL v){
    if(tr[u].l==x&&tr[u].r==x){
        LL b=tr[u].sum+v;
        tr[u]={x,x,b,b};
    }
    else {
        int mid=tr[u].l+tr[u].r>>1;
        if(x<=mid)modify(u<<1,x,v);
        else modify(u<<1|1,x,v);
        pushup(u);
    }
}
node query(int u,int l,int r){
    if(l>r)return {0};
    if(tr[u].l>=l&&tr[u].r<=r)return tr[u];
    int mid=tr[u].l+tr[u].r>>1;
    if(r<=mid)return query(u<<1,l,r); 
    else if(l>mid)  return  query(u<<1|1,l,r);
    else {
        auto left=query(u<<1,l,r),right=query(u<<1|1,l,r);
        node res;
        pushup(res,left,right);
        return res; 
    }
}
int main(){
   scanf("%d%d",&n,&m);
   for(int i=1;i<=n;i++)scanf("%lld",&w[i]);
   build(1,1,n);
   int l,r;
   LL d;
   char op[2];
   while(m--){
       scanf("%s%d%d",op,&l,&r);
   if(*op=='Q'){
      auto left=query(1,1,l),right=query(1,l+1,r);
      printf("%lld\n",abs(gcd(left.sum,right.d)));//这里搞不明白公约数求法,为什么要分段再求一遍gcd,还有不能理解gcd还能是负数
   }
   else {
    scanf("%lld",&d);
    modify(1,l,d);
    if(r+1<=n)modify(1,r+1,-d);
   }
   }
}