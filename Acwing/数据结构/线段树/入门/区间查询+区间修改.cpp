#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e5+10;
typedef long long ll;
struct node{
    int l,r;
    ll sum,add;
}tr[4*N];
int n,m;
ll w[N];
void pushup(int u){
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}
void pushdown(int u){
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if(root.add){
    left.add+=root.add,right.add+=root.add;
    left.sum+=(ll)(left.r-left.l+1)*root.add,right.sum+=(ll)(right.r-right.l+1)*root.add;
    root.add=0;
    }
}
void modify(int u,int l,int r,ll d){
    if(tr[u].l>=l&&tr[u].r<=r){tr[u].add+=d;
    tr[u].sum+=(ll)(tr[u].r-tr[u].l+1)*d;
    }
    else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if(l<=mid)modify(u<<1,l,r,d);
        if(r>mid)modify(u<<1|1,l,r,d);
        pushup(u);
    }
}
ll query(int u,int l,int r){
    if(tr[u].l>=l&&tr[u].r<=r)return tr[u].sum; 
    //查不到就拆分add
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    ll summ=0;
    if(l<=mid)summ=query(u<<1,l,r);
    if(r>mid)summ+=query(u<<1|1,l,r);
    return summ;
}
void build (int u,int l,int r){
    if(l==r)tr[u]={l,r,w[l],0};
    else {
        tr[u]={l,r,0,0};
        int mid=l+r>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        pushup(u);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&w[i]);
    build(1,1,n);
    int t,l,r;
    ll d;
    while(m--){
    scanf("%d%d%d",&t,&l,&r);
    if(t==1){
        scanf("%lld",&d);
        modify(1,l,r,d);
    }
    else {
        printf("%lld\n",query(1,l,r));
    }
    }
}
