/*
统计次数：
s1的所有长度为奇数的回文字串中s2的次数
就是找出所有的回文字符串，转换出原字符串坐标后
再套一层kmp
蠢蠢的做法
*/
//30分，tle了一堆
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
const int  N =4e6+10;
ll mod=pow(2,32);
char s[N],p[N],S[N<<1];
int cnt=0;
ll tr[N];
int hw[N<<1];
int n,m;
int tot=1;
int ne[N];
unsigned int ans=0;
int match[N];
int ss[N];
void kmp(){
    for(int i=2,j=0;i<=m;i++){
        while(j&&p[i]!=p[j+1])j=ne[j];
        if(p[i]==p[j+1])j++;
        ne[i]=j;
    }
    for(int i=1,j=0;i<=n;i++){
        while(j&&s[i]!=p[j+1])j=ne[j];
        if(s[i]==p[j+1])j++;
        if(j==m){
            match[i-m+1]=1;
            j=ne[j];
        }
    }  
}
void difference(){
    for(int i=1;i<=n;i++){
        match[i]=match[i]+match[i-1];
    }
    for(int i=1;i<=n;i++){
        ss[i]=match[i]+ss[i-1];
    }
}
void solve(){
        int mid=(ceil(m+1)/2);
for(int i=1;i<=n;i++){
    if(2*tr[i]-1<m)continue;
    ll a=ss[i+tr[i]-m]-ss[i+mid-m-1];
    ll b=ss[i-mid]-ss[i-tr[i]-1];
    ans+=(a-b);
    
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
        tr[i/2]=(r-l)/2+1;
        
        }
        
    }
}
int  main(){
    cin>>n>>m;
    scanf("%s",s+1);
    scanf("%s",p+1);
    manacher();
     kmp();
     difference();
     solve();

    printf("%u\n",ans);
}
