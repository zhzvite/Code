#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll ans=0;
struct point{
    int val,num;
}a[N];
ll  tr[N];
int n;
bool cmp(point x,point y){
    if(x.val==y.val)
    return x.num<y.num;
    return x.val<y.val;
}
int lowbit(int x){
    return x&-x;
}
void add(int x ,int c){
    for(int i=x;i<=n;i+=lowbit(i))tr[i]+=c;
}
ll sum(int x){
    ll res=0;
    for(int i=x;i>0;i-=lowbit(i))res+=tr[i];
    return res;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].val);
        a[i].num=i;
    } 
    sort(a+1,a+1+n,cmp);
     for(int i=1;i<=n;i++){
      ans+=(ll)sum(n)-sum(a[i].num-1);
      add(a[i].num,1);
     }
    printf("%lld",ans);
}