#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=1e5+10;
char a[N],s[N<<1];
int hw[N<<1];
int cnt;
inline int min(int a,int b){
    return a<b ? a:b;
}
int main(){
    while(scanf("%s",a+1)){
    int n=strlen(a+1),ans=1;
    s[0]='~';
    s[cnt=1]='#';
    for(int i=1;i<=n;i++){
        s[++cnt]=a[i];
        s[++cnt]='#';
    }
       int maxright=0,mid=0;
    for(int i=1;i<=cnt;i++){
        if(i<maxright)
        hw[i]=min(hw[(mid<<1)-i],hw[mid]+mid-i);
        else hw[i]=1;
        for(;s[i+hw[i]]==s[i-hw[i]];++hw[i]);
         if(hw[i]+i-1==cnt){
             ans=hw[i]-1;
            break;
         }
        if(hw[i]+i>maxright){
            maxright=hw[i]+i;
            mid=i;
        }
    }
    printf("%s",a+1);
    for(int i=n-ans;i>=1;i--)putchar(a[i]);
    puts("");
    }
}