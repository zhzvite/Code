//给定了一个字符串S,寻找一子串T，满足以下要求：
//T是S的前缀，T是S的后缀，且S的中间有T，Tmax表示所有T中最长的
//输出Tmax
/*
fixprefixsuffix
000000123001123
fixprefixsuffi
00000012300112

*/  
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=1e6+10;
int len;
char s[N];
int maxx;
int ne[N];
int main(){
    scanf("%s",s+1);
    len=strlen(s+1);
    for(int i=2,j=0;i<=len;i++){
        while(j&&s[i]!=s[j+1])j=ne[j];
        if(s[i]==s[j+1])j++;
        ne[i]=j;
        if(i!=len)maxx=max(maxx,ne[i]);
    }
 //   for(int i=1;i<=len;i++)cout<<ne[i]<<" ";
    int x=ne[len];
    if(x==0){
    cout<<"Just a legend";
    return 0;
    }
    if(x==maxx){
        for(int i=1;i<=x;i++)
        cout<<s[i];
    }
    //ababab
    else if(x>maxx){
        while(x>maxx)x=ne[x];
        if(x==0)
        cout<<"Just a legend";
        else {
            for(int i=1;i<=x;i++)
            cout<<s[i];
        }
    }
    else if(x<maxx){
        for(int i=1;i<=x;i++)
        cout<<s[i];
        
    }
    
}
