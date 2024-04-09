#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int n,m,b;
int f[N];
int maxn=0;
int e[N],ne[N],h[N],w[N],idx;
int dist[N];
bool st[N];
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii>>heap;
void add(int a,int b,int c){
    e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;

}
bool dijkstra(int x){
    if(x<f[1])return false;
    for(int i=1;i<=n;i++)dist[i]=0x3f3f3f3f,st[i]=false;
    
    dist[1]=0;
    heap.push({0,1});
    while(!heap.empty()){
        auto t=heap.top();
        heap.pop();
        int distance=t.first,val=t.second;
        //cout << distance << " " << val << "----" << endl;
        if(st[val])continue;
        st[val]=true;
        for (int i = h[val]; ~i; i = ne[i])
        {
            int j=e[i];
            if((dist[j]>distance+w[i])&&(f[j]<=x))
            {
                dist[j]=distance+w[i];
                heap.push({dist[j],j});
            }
        }
        
    }
    if(dist[n]<=b)
        return true;
    return false;
}
int main(){
    cin>>n>>m>>b;
    memset(h, -1, sizeof h);
    for(int i=1;i<=n;i++){
        cin>>f[i];
        maxn=max(maxn,f[i]);
    }
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;

        add(a,b,c),add(b,a,c);

    }
    if(!dijkstra(maxn)){
        cout<<"AFK";
        return 0;
    }
    int l=1,r=maxn,mid=(l+r)>>1;
    while(l<=r){
        if(dijkstra(mid)){
            r=mid-1;
            mid=(l+r)>>1;
        }
        else {
            l=mid+1;
            mid=(l+r)>>1;
        }
    }
    cout<<l<<endl;

}


