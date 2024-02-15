#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,m;
struct node{
    int l,r;
    int sum,add;//sum表示当前区间开灯的数目,add表示变化次数
}tr[4*N];
void test(){
    printf("------------\n");
    for(int i=1;i<=7;i++)   
    printf("----%d %d % d %d %d---- \n",i,tr[i].l,tr[i].r,tr[i].sum,tr[i].add);
    printf("------------\n");
}
void build(int u,int l,int r){
    tr[u]={l,r,0,0};
    if(l!=r){
    int mid=l+r>>1;
    build(u<<1,l,mid),build(u<<1|1,mid+1,r);
    } 
  //  test();  
}
void pushup(int u){
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}
void pushdown(int u){
    if(tr[u].add==0)return;
    tr[u].add=0;
    tr[u<<1].add=!tr[u<<1].add,tr[u<<1|1].add=!tr[u<<1|1].add;
    tr[u<<1].sum=tr[u<<1].r-tr[u<<1].l+1-tr[u<<1].sum;
    tr[u<<1|1].sum=tr[u<<1|1].r-tr[u<<1|1].l+1-tr[u<<1|1].sum;
}
int  query(int u,int l,int r){
    if(tr[u].l>=l&&tr[u].r<=r)return tr[u].sum;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int summ=0;
    if(l<=mid)summ=query(u<<1,l,r);
    if(r>mid)summ+=query(u<<1|1,l,r);
    return summ;
}
void modify(int u,int l,int r){
    if(tr[u].l>=l&&tr[u].r<=r){
        tr[u].sum=tr[u].r-tr[u].l+1-tr[u].sum;
        tr[u].add=!tr[u].add;
    }
    else {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if(l<=mid)modify(u<<1,l,r);
        if(r>mid)modify(u<<1|1,l,r);
        pushup(u);
    }
}
int main(){
scanf("%d%d",&n,&m);
build(1,1,n);
while(m--){
int  l,r,tag;
scanf("%d%d%d",&tag,&l,&r);
if(tag==0){modify(1,l,r);
//test();
}
else printf("%d\n",query(1,l,r));
}
}