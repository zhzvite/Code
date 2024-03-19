/*
00001111
11100111
010101
-->
101010
-->
010101
//建立一个数组表示对立关系
*/
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n;
int tot=1;
char s[N<<1],a[N],to[500];
ll hw[N<<1];
ll ans=0;
void manacher(){
    ll mid=0,maxright=0;
    for(int i=1;i<=tot;i+=2){
        if(i<maxright)hw[i]=min(hw[(mid<<1)-i],maxright-i);
        else hw[i]=1;
        for(;s[hw[i]+i]==to[s[i-hw[i]]];++hw[i]);
        if(hw[i]+i>maxright){
            mid=i;
            maxright=hw[i]+i;
        }
        ans+=hw[i]>>1;
    }

}
int main(){
    scanf("%d%s",&n,a+1);
    s[0]='$';
    s[1]='#';
    for(int i=1;i<=n;i++){
        s[++tot]=a[i];
        s[++tot]='#';
    }
    //设立一个对应数组
    to['1']='0';
    to['0']='1';
    to['#']='#';
    to['$']='$';
    manacher();
    //for(int i=1;i<=tot;i++)cout<<s[i]<<" ";
    //cout<<endl;
    //for(int i=1;i<=tot;i++)cout<<hw[i]<<" ";
    cout<<ans;
}