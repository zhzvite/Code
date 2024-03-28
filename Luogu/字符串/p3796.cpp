#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
#include<map>
using namespace std;
const int N = 1e5 + 10;
string s[N];
struct tree
{
    int fail;
    int vis[26];
    int end;
} AC[N];
int cnt = 0;
int t;
void clean(int x){
    memset(AC[x].vis,0,sizeof (AC[x].vis));//清空子节点
    AC[x].fail=0;
    AC[x].end=0;
}
void build(string s,int num)
{
    int p = 0;
    for (int i = 0; s[i]; i++)
    {
        int t = s[i] - 'a';
        if (!AC[p].vis[t])
            {
            AC[p].vis[t] = ++cnt;
            clean(cnt);
            }
        p = AC[p].vis[t];
    }
    AC[p].end=num;
}
struct result{
    int num;
    int pos;
}ans[N];
bool operator <(result a,result b){
    if(a.num!=b.num){
        return a.num>b.num;
    }
    else {
        return a.pos<b.pos;
    }
}
void get_fail()
{
    queue<int> Q;
    for (int i = 0; i < 26; i++)
    {
        if (AC[0].vis[i])
        {
            Q.push(AC[0].vis[i]);
            AC[AC[0].vis[i]].fail = 0;
        }
    }
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int i = 0; i < 26; i++)
        {
            int c = AC[u].vis[i];
            if (!c)
            {
                AC[u].vis[i] = AC[AC[u].fail].vis[i];
            }
            else
            {
                int j = AC[u].fail;
                AC[c].fail = AC[j].vis[i];
                Q.push(c);
            }
        }
    }
}
void query(string s)
{
    int now = 0;
    for (int i = 0; s[i]; i++)
    {
        now = AC[now].vis[s[i] - 'a'];
        for (int t = now; t; t = AC[t].fail)
        {
           // cout<<AC[t].end;
            ans[AC[t].end].num++;
        }
    }
    
}
int main()
{
    int n;
    while (cin >> n && n)
    {
        cnt = 0;
        clean(0);
        for (int i = 1; i <= n; i++)
        {
            cin >> s[i];
            ans[i].num=0;
            ans[i].pos=i;
            build(s[i],i);
        }
        AC[0].fail = 0;
        get_fail();
        cin>>s[0];
        query(s[0]);
        sort(&ans[1],&ans[n+1]);
        cout<<ans[1].num<<endl;
        cout<<s[ans[1].pos]<<endl;
        for(int i=2;i<=n;i++){
            if(ans[i].num==ans[i-1].num){
                cout<<s[ans[i].pos]<<endl;

            }
            else 
            break;
        }

    }
}
