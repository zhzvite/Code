#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n;
vector<ll> ys;
struct segment{
ll x,y1,y2;
int k;//权值
bool operator< (const segment &t)const {
    return x<t.x;
}
}seg[N*2];//存的是点,在sort中会将点以x从小往大的顺序排序
struct node{
    int l,r,cnt;
    ll len;//在这里面存的是边,ys[tr[u].r+1]~ys[tr[u].l]的边
}tr[N*8];
int find(ll y){
    return lower_bound(ys.begin(),ys.end(),y)-ys.begin();//返回第一个不小于给定值的迭代器-开头迭代器===>返回元素所在位置
}
void pushup(int u){
   if(tr[u].cnt)tr[u].len=ys[tr[u].r+1] -ys[tr[u].l];
   else if(tr[u].l!=tr[u].r){tr[u].len=tr[u<<1|1].len+tr[u<<1].len;
   }
   else tr[u].len=0;//叶节点,当cnt=0归零时,len要重置
}
void build(int u,int l,int r){
    tr[u]={l,r,0,0};
    if(l!=r){
        int mid=r+l>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
    }
}
void modify(int u,int l,int r,int k){
    if(tr[u].l>=l&&tr[u].r<=r){
        tr[u].cnt+=k;
        pushup(u);
    }
    else {
        int mid=tr[u].l+tr[u].r>>1;
        if(l<=mid)modify(u<<1,l,r,k);
        if(r>mid)modify(u<<1|1,l,r,k);
        pushup(u);
    }
}
int main(){
        scanf("%d",&n);
        for(int i=0,j=0;i<n;i++){
            ll x1,x2,y1,y2;
            scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
            seg[j++]={x1,y1,y2,1},seg[j++]={x2,y1,y2,-1};//把所有的点都存进去
            ys.push_back(y1),ys.push_back(y2);//离散化准备
        }
        sort(ys.begin(),ys.end());//从小到大排序
        ys.erase(unique(ys.begin(),ys.end()),ys.end());//去重,离散化完成
         build(1,0,ys.size()-2);//tr中存的是边,一共有2n个点,从零开始建树,树中的每一个节点表示的都是一个区间,最右是ys大小-2
        sort(seg,seg+2*n);//以x升序排序
        ll res=0;//准备计数
        for(int i=0;i<n*2;i++){
           if(i>0)res+=tr[1].len*(seg[i].x-seg[i-1].x);
           modify(1,find(seg[i].y1),find(seg[i].y2)-1,seg[i].k);//右端点要减一
        }
        printf("%lld\n",res);
    }
