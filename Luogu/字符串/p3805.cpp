//manacher
#include<iostream>
#include<cmath>
#include<cstring>
#include<stdio.h>
using namespace std;
const int N=2e7;
int n,hw[N<<1],ans;
char a[N],s[N<<1];
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
    scanf("%s",a);
    n=strlen(a);
    init();
    manacher();
    ans=1;
    for(int i=0;i<n;i++)
    ans=max(ans,hw[i]);
    printf("%d",ans-1);
    return 0;

}