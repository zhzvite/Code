#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=200010;
int Greater[N],lower[N];
int a[N];
int n;
int tr[N];
int lowbit(int x)
{
    return x&-x;
}
void add(int x,int c){
    for(int i=x;i<=n;i+=lowbit(i))tr[i]+=c;
}
int sum(int x){
    ll res=0;
    for(int i=x;i>0;i-=lowbit(i))res+=tr[i];
    return res;
}

int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cout<<a[i];}
     cout<<1;
    for(int i=1;i<=n;i++){
        int y=a[i];
        Greater[i]=sum(n)-sum(y);
        lower[i]=sum(y-1);
        add(y,1);

    }
    memset(tr,0,sizeof tr);
    ll res1=0,res2=0;
    for(int i=n;i>=0;i--){
        int y=a[i];
        res1+=Greater[i]*(ll)(sum(n)-sum(y));
        res2+=lower[i]*(ll)(sum(y-1));
        add(y,1);
    }
    cout<<res1<<" "<<res2;
}