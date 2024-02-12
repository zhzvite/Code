//单点修改,区间查询最大值
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int m,n,p,last;
struct node{
    int l,r;
    int v;
}tr[4*N];
void pushup(int u){
    tr[u].v=max(tr[u<<1].v,tr[u<<1|1].v);//更新父节点
}
void build(int u,int l,int r){//初始化这一颗树
    // tr[u].l=l;
    // tr[u].r=r;
    tr[u]={l,r};
    if(l==r)return ;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
}
int query(int u,int l,int r){//查询队列
    if(tr[u].l>=l&&tr[u].r<=r)return tr[u].v;
    int mid=tr[u].l+tr[u].r>>1;
    int v=0;
    if(l<=mid)v=query(u<<1,l,r);
    if(r>mid)v=max(v,query(u<<1|1,l,r));//其实感觉这里你把区间划分了也是能过的
    return v;
}

void modify(int u,int x,int v){//修改单点
    if(tr[u].l==x&&tr[u].r==x)tr[u].v=v;
    else{
        int mid=tr[u].l+tr[u].r>>1;
        if(x<=mid)modify(u<<1,x,v);
        if(x>mid)modify(u<<1|1,x,v);
        pushup(u);//把当前儿子的最大值信息回溯以下,更新他的父节点
    }
}
int main(){
  scanf("%d%d",&m,&p);
  build(1,1,m);
  while(m--){
    char op[2];
    ll x;
    scanf("%s%lld",op,&x);
    if(*op=='Q'){
       last= query(1,n-x+1,n);
       printf("%d\n",last);
    }
    else {
        x=(x+last)%p;
        modify(1,n+1,x);
        n++;
    }
  }
} 