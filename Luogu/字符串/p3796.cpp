#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
const int N=1e6+10;
struct tree{
    int fail;
    int vis[26];
    int end;
}AC[N];
int cnt=0;
int t;
void build(string s){
    int p=0;
    for(int i=0;s[i];i++){
        int t=s[i]-'a';
        if(!AC[0].vis[t])AC[0].vis[t]==++cnt;
        now=AC[now].vis[t];
    }
}
int main(){
    int t ;
    while(cin>>t&& t){
        cnt=0;
        memset()
    }
}
