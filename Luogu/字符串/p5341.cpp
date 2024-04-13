//SAM
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2e5+10;
char s[N];
int k;
struct Node{
    int len,fa;
    int ch[26];
}node[N];
int last=1,cnt=1;
int mxl;
int f[N];
int e[N],ne[N],h[N],idx,ans[N];
void init (){
    for(int i=1;i<=cnt;i++){
        node[i].len=node[i].fa=0;
        memset(node[i].ch,0,sizeof node[i].ch);
    }
    last=cnt=1;
    mxl=0;
    for(int i=1;i<=cnt;i++)f[i]=0;
    memset(ans,0,sizeof ans);
    idx=0;
    // memset(h,-1,sizeof h);
    // memset(e,0,sizeof e);
    // memset(ne,0,sizeof ne);
    
}
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void extend(int c){
    int p=last,np=last=++cnt;
    node[np].len=node[p].len+1;
    f[cnt]=1;
    for(;p&&!node[p].ch[c];p=node[p].fa)node[p].ch[c]=np;
    if(!p)node[np].fa=1;
    else{
        int q=node[p].ch[c];
        if(node[q].len==node[p].len+1)node[np].fa=q;
        else{
            int copy=++cnt;
            node[copy]=node[q];
            node[copy].len=node[p].len+1;
            node[np].fa=node[q].fa=copy;
            for(;p&&node[p].ch[c]==q;p=node[p].fa)node[p].ch[c]=copy;
        }
    }
}
void dfs(int u){
    for(int i=h[u];~i;i=ne[i]){
        dfs(e[i]);
        f[u]+=f[e[i]];
    }
}
void solve(){
    for(int i=1;s[i];i++){
        int c=s[i]-'a';
        extend(c);
    }
    for(int i=2;i<=cnt;i++)add(node[i].fa,i);
    dfs(1);
 //  for(int i=2;i<=cnt;i++)cout<<f[i]<<"~~~"<<node[node[i].fa].len+1<<"----"<<node[i].len<<endl;
    for(int i=2;i<=cnt;i++){
        if(f[i]==k){ans[node[node[i].fa].len+1]++,ans[node[i].len+1]--;
   //     cout<<f[i]<<"~~~"<<node[node[i].fa].len+1<<"----"<<node[i].len<<endl;
        mxl=max(mxl,node[i].len);
        }
    }
    for(int i=1;i<=mxl;i++)ans[i]+=ans[i-1];
  //  for(int i=1;i<=mxl;i++)cout<<ans[i]<<" ";
    int mmxl=0,tail=-1;
    for(int i=1;i<=mxl;i++){
        if(ans[i]>mmxl){
        mmxl=ans[i];
        tail=i;
        }
        else if(ans[i]==mmxl){
            tail=i;
        }
    }
    cout<<tail<<endl;
    init();
}
int main(){
    int t;
    cin>>t;
    while(t--){
        memset(h,-1,sizeof h);
        memset(e,0,sizeof e);
    memset(ne,0,sizeof ne);
        cin>>(s+1)>>k;
        solve();
    }
}