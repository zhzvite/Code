//manacher
#include<iostream>
#include<cmath>
#include<cstring>
#include<stdio.h>
using namespace std;
const int N=2e5+10;
int n,hw[N<<1],ans,m,t;
char a[N],s[N<<1];
void init(){
    s[0]=s[1]='#';
    for(int i=0;i<n;i++){
        s[i*2+2]=a[i];
        s[i*2+3]='#';
    }
    n=n*2+2;
    s[n]=0;//两边字符不一样就好了
}
void manacher(){
    int maxright=0,mid;
    for(int i=1;i<n;i++){
        if(i<maxright)
        hw[i]=min(hw[(mid<<1)-i],hw[mid]+mid-i);
        //hw[mid]+mid-i表示由中心点往外的最大辐射半径得到坐标-i
        //能够保证取到的hw[i]是正解hw[i]的一部分值,即他的子集
        else 
            hw[i]=1;//如果没有任何已知信息,则hw[i]=1
        for(;s[i+hw[i]]==s[i-hw[i]];++hw[i]);
        if(hw[i]+i>maxright){
            maxright=hw[i]+i;
            mid=i;
        }       
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
    scanf("%d%d",&n,&m);
     scanf("%s",a);
    init();
    manacher();
    // for(int i=1;i<=n;i++)cout<<s[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=n;i++)cout<<hw[i]<<" ";
    int aa[N],ab[N],l,r,len1,len2;
    char tt,hh;
    for(int i=1;a[i];i++){
        if(a[i-1]==a[i]){
            len1++;
            if(l==-1)l=i-1;
        }
        if(a[i-1]!=a[i]){
            aa[l]=len1+l;
            len1=0,l=-1;
        }
    }
    
    }

    return 0;

}