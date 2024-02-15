#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,q,m=571373;
struct node{
    int l,r;
    ll sum,add,mul;
}tr[4*N];
ll w[N];
void eval(node &t,ll add,ll mul){//在这里负责执行sum,mul,add的更新操作,每次执行先乘后加的顺序即sum*mul+add
    t.sum=(ll)(t.sum*mul+(t.r-t.l+1)*add)%m;
    t.mul=(t.mul*mul)%m;
    t.add=(t.add*mul+add)%m;
}
void pushup(int u){
    tr[u].sum=(tr[u<<1].sum+tr[u<<1|1].sum)%m;//把子节点信息向上传递,只用传递sum
}
void pushdown(int u){
     eval(tr[u<<1],tr[u].add,tr[u].mul),eval(tr[u<<1|1],tr[u].add,tr[u].mul);//拆分
     tr[u].add=0,tr[u].mul=1;//重置父节点的add和mul懒标记
}
void build(int u,int l,int r){
    if(l==r)tr[u]={l,r,w[l],0,1};
    else{
        tr[u]={l,r};
        tr[u].mul=1;
        int mid=l+r>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        pushup(u);//更新完子节点要更新父节点
    }
}
void modify(int u,int l,int r,ll ADD,ll MUL){
    if(tr[u].l>=l&&tr[u].r<=r)eval(tr[u],ADD,MUL);//符合情况的直接修改add和mul和sum
    else{
        pushdown(u);//拆分
        int mid=tr[u].l+tr[u].r>>1;
        if(l<=mid)modify(u<<1,l,r,ADD,MUL);
        if(r>mid)modify(u<<1|1,l,r,ADD,MUL);
        pushup(u);//修改完回溯更新
    }
}
ll query(int u,int l,int r){
    if(tr[u].l>=l&&tr[u].r<=r)return tr[u].sum;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    ll summ=0;
    if(l<=mid)summ=query(u<<1,l,r);
    if(r>mid)summ+=query(u<<1|1,l,r);
    return summ;
}
int main(){
    scanf("%d%d%d",&n,&q,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&w[i]);
    build (1,1,n);
    while(q--){
       int t;
        ll l,r,k;
        scanf("%d%lld%lld",&t,&l,&r);
        if(t==1){
            scanf("%lld",&k);
            modify(1,l,r,0,k);//只乘不加则add=0
        }
        else if(t==2){
             scanf("%lld",&k);
            modify(1,l,r,k,1);//只加不乘则mul=1
        }
        else{
            printf("%lld\n",query(1,l,r)%m);//这里还是要取模
        }
    }
}