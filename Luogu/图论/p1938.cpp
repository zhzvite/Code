#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N=1000;
int ne[N],e[N],h[N],idx,w[N];
int dist[N];
bool st[N];
int n,m1,m2,f;
int val;
int cnt[N];
void add(int a,int b,int c){
    e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
}
void spfa(){
    //memset(dist,-0x3f ,sizeof dist);
    memset(st,false ,sizeof st);
    dist[f]=val;
    cnt[f]++;
    queue<int> q;
    q.push(f);
    st[f]=true;
    while(q.size()){
        int t=q.front();
        q.pop();
        st[t]=false;
        // if(++cnt[t]>n){
        //     cout<<"-1"<<endl;
        //     exit(0);
        // }
        for(int i=h[t];~i;i=ne[i] ){
            int j=e[i];
           // cout<<j<<" "<<dist[j]<<endl;
            if(dist[j]<dist[t]+w[i]){
                dist[j]=dist[t]+w[i];
               // cout<<"j="<<j<<" "<<dist[j]<<endl;
            if(!st[j]){
            //    cout<<"j="<<j<<" "<<dist[j]<<endl;
                q.push(j);
                st[j]=true;
            }
            }
        }
    }

}
int main(){
    cin>>val>>m1>>n>>m2>>f;
    memset(h,-1,sizeof h);
    while(m1--){
        int a,b;
        cin>>a>>b;
        add(a,b,val);
    }
    while(m2--){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,val-c);
    }
    //for(int i=h[1];i!=-1;i=ne[i])cout<<e[i]<<endl;
    spfa();
    int ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,dist[i]);
    cout<<ans;

}