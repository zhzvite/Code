/*
统计次数：
s1的所有长度为奇数的回文字串中s2的次数
就是找出所有的回文字符串，转换出原字符串坐标后
再套一层kmp
蠢蠢的做法O(n)
*/
//30分，tle了一堆
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
const int  N =3e6+10;
ll mod=pow(2,32);
char s[N],p[N],S[N<<1];
int cnt=0;
struct node{
    int l,r;
}tr[N<<1];
int hw[N<<1];
int n,m;
int tot=1;
int ne[N];
ll ans=0;
void kmp(int l,int r){
    for(int i=l,j=0;i<=r;i++){
        while(j&&s[i]!=p[j+1])j=ne[j];
        if(s[i]==p[j+1])j++;
        if(j==m){
           // cout<<i<<endl;
            ans++;
            ans=ans%mod;
        j=ne[j];
        }
    }
}
void kmp(){
    for(int i=2,j=0;i<=m;i++){
        while(j&&p[i]!=p[j+1])j=ne[j];
        if(p[i]==p[j+1])j++;
        ne[i]=j;
    }
    for(int i=1;i<=cnt;i++){
      //  cout<<tr[i].l<<" "<<tr[i].r<<endl;
            int l=tr[i].l,r=tr[i].r;
         //   cout<<endl;
        while(l!=r&&l>0&&r>0&&r-l+1>=m){
          //  cout<<l<<" "<<r<<endl;
          //  cout<<endl;
            kmp(l,r);
            l++;
            r--;
        }
        }
    
}

void manacher(){
    S[0]='~',S[1]='#';
    for(int i=1;i<=n;i++){
        S[++tot]=s[i];
        S[++tot]='#';
    }
    int mid=0,maxright=0;
    for(int i=1;i<tot;i++){
        if(i<maxright)hw[i]=min(hw[(mid<<1)-i],maxright-i);
        else hw[i]=1;
        for(;S[i+hw[i]]==S[i-hw[i]];++hw[i]);
        if(hw[i]+i>maxright){
            maxright=hw[i]+i;
            mid=i;
        }
        //记录回文子串
        if(i%2==0){
        int l=(i>>1)-((hw[i]-1)>>1);
        int r= (i>>1)+((hw[i]-1)>>1);
        tr[++cnt]={
         l,r
        };
        }
        
    }
}
int main(){
    scanf("%d%d%s%s",&n,&m,s+1,p+1);
    manacher();
      // for(int i=1;i<=cnt;i++)cout<<tr[i].l<<" "<<tr[i].r<<endl;
     kmp();
    cout<<ans;
}
