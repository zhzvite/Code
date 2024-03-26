#include<iostream>
#include<string>
#include<cstdio>
#include<queue>
using namespace std;
const int N=1e6+10;
struct tree{
    int fail;
    int vis[26];
    int end;
} AC[N];
int cnt=0;
void build(string s){
    int len=s.length();
    int now=0;
    for(int i=0;s[i];i++){
        int t=AC[now].vis[s[i]-'a'];
        if(!t)AC[now].vis[s[i]-'a']=++cnt;
        now=AC[now].vis[s[i]-'a'];

    }
    AC[now].end++;
}
void get_fail(){
    queue<int> Q;
    for(int i=0;i<26;i++){
        int c=AC[0].vis[i];
        if(c){
            AC[c].fail=0;
            Q.push(c);
        }
    }
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<26;i++){
            int c=AC[u].vis[i];
            if(!c){
                AC[u].vis[i]=AC[AC[u].fail].vis[i];//虚指针
            }
            else {
            int j=AC[u].fail;
            AC[c].fail=AC[j].vis[i];
            Q.push(c);

            }
        }
    }
}
int query(string s){
    int len=s.length();
    int now=0,ans=0;
    for(int i=0;s[i];i++){
        now =AC[now].vis[s[i]-'a'];
        for(int t=now;t&&AC[t].end!=-1;t=AC[t].fail){
            ans+=AC[t].end;
            AC[t].end=-1;
        }
    }
    return ans;
}
int main(){
    int n;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        build(s);
    }
    AC[0].fail=0;
    get_fail();
    cin>>s;
    cout<<query(s)<<endl;
    return 0;
}