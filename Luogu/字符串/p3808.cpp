#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
const int N=1e6+10;
string s;
struct tree{
    int fail;
    int vis[26];
    int end;
}node [N];
int m,n;
int cnt=0;
void build(string s){
    int now=0;
    for(int i=0;s[i];i++){
        int c=s[i]-'a';
        if(node[now].vis[c])now=node[now].vis[c];
        else {
            node[now].vis[c]=++cnt;
            now=node[now].vis[c];
        }
    }
    node[now].end++;
}
void get_fail(){
    queue<int> q;
    for(int i=0;i<26;++i){
        if(node[0].vis[i]){
            node[node[0].vis[i]].fail=0;
            q.push(node[0].vis[i]);
        }
    }
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int i=0;i<26;i++){
            if(!node[u].vis[i])node[u].vis[i]=node[node[u].fail].vis[i];
            else{
                node[node[u].vis[i]].fail=node[node[u].fail].vis[i];
                q.push(node[u].vis[i]);
            }
        }
    }
}
int query(string s){
            int now=0,ans=0;
    for(int i=0;s[i];i++){
        int c=s[i]-'a';
        now=node[now].vis[c];
        for(int t=now;t&&node[now].end!=-1;t=node[t].fail){
            ans+=node[t].end;
            node[t].end=-1;
        }
    }
    return ans;
}
int main(){
    cin>>m;
    while(m--){
        cin>>s;
        build(s);
    }
    node[0].fail=0;
    get_fail();
    cin>>s;
    cout<<query(s);
}