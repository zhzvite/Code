#include<iostream>
#include<cstring>
#include<map>
using namespace std;
typedef long long ll;
ll n,k;
ll mod=19930726;
const int N=1e6+100000;
char a[N],s[N*2];
ll hw[N*2];
ll cnt[N*2];
ll ans=1;
ll sum=0;
ll ksm(int x,int y) {//因为数据范围很大容易爆掉，所以就要Fast_Pow
    if(x==1) return 1;
    ll res=1,base=x;
    while(y) {
        if(y&1) res=(res*base)%mod;
        base=(base*base)%mod;
        y>>=1;
    }
    return res;
}
void init(){
    s[0]=s[1]='#';
    for(int i=0;i<n;i++){
        s[i*2+2]=a[i];
        s[i*2+3]='#';
    }
    n=n*2+2;
    s[n]=0;//两边字符不一样就好了
    // ##a#a#a#0
}
void manacher(){
    ll mid=0,maxright=0;
    for(int i=1;i<n;i++){
        if(i<maxright)hw[i]=min(hw[(mid<<1)-i],hw[mid]+mid-i);
        else hw[i]=1;
        for(;s[i-hw[i]]==s[i+hw[i]];++hw[i]);
        if(hw[i]+i>maxright){
            maxright=hw[i]+i;
            mid=i;
          // cout<<mid<<" "<<maxright<<endl;
        }
        if((hw[i]-1)%2)cnt[hw[i]-1]++;//为什么hw要设为两倍的？因为字符串扩张，hw的点会扩展为两倍
        //但是为什么cnt要扩展为两倍呢？cnt指的是半径，但是我们知道hw[i]的最大值就是n，所以为什么要定两倍的N？

    }
}
int main(){
    scanf("%lld%lld",&n,&k);
    scanf("%s",a);
    init ();
    manacher();
    for(int i=n;i>=1;i--){
        if(i%2==0)continue;
        sum+=cnt[i];
        if(k>=sum){
            ans=ans*ksm(i,sum)%mod;
            k-=sum;
        }
        else {
            ans=ans*ksm(i,k)%mod;
            k-=sum;
            break;
        }
    }
    if(k>0)
    cout<<-1;
    else 
    cout<<ans%mod;
    
}
