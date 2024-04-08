#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
const int N=1e4+10;
int n,m;
int ne[N],e[N],h[N],w[N],idx;
int dist[N];
bool st[N];
int tot[N];
queue<int> q;
void add(int a,int b,int c){
    e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
}
bool spfa(int s){
    memset(st,false,sizeof st);
    memset(dist,0x3f,sizeof dist);
    dist[s]=0;
    q.push(s);
    st[s]=true;
    while(q.size()){
        int t=q.front();
        q.pop();
        st[t]=false;
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(dist[j]>dist[t]+w[i]){
            dist[j]=dist[t]+w[i];
          //  cout<<dist[j]<<endl;
            if(!st[j]){
                q.push(j);
                st[j]=true;
                tot[j]++;
                if(tot[j]==n+1)return false;
            }
            }
        }
    }
    return true;

}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++)add(0,i,0);
    while(m--){
            int a,b,c;
            cin>>a>>b>>c;
            add(b,a,c);
    }
    if(!spfa(0))cout<<"NO"<<endl;
    else 
    for(int i=1;i<=n;i++)cout<<dist[i]<<" ";
    

}