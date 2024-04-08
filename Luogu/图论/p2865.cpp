//次短路
#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
const int N=1e6+10;
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii>>heap;
int ne[N],e[N],w[N],h[N],idx,n,m,dist_min[N],dist_nmin[N];
bool st[N];
void add(int a,int b,int c){
    e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
}
void dijkstra(){
    memset(dist_min,0x3f,sizeof dist_min);
    memset(dist_nmin,0x3f,sizeof dist_nmin);
    memset(st,false,sizeof st);
    heap.push({0,1});
    while(heap.size()){
        auto t=heap.top();
        heap.pop();
        int dis=t.first,val=t.second;
        if(st[val])continue;
        for(int i=h[val];~i;i=ne[i]){
            int j=e[i];
            if(dist_min[j]>dis+w[i]){
                dist_nmin[j]=dist_min[j];
                dist_min[j]=dis+w[i];
                heap.push({dist_min[j],j});
            
            }
            if((dist_min[j]<dis+w[i])&&(dist_nmin[j]>dis+w[i])){
                dist_nmin[j]=dis+w[i];
                heap.push({dist_nmin[j],j});
            }
            cout<<dist_min[1]<<" "<<dist_nmin[1]<<endl;
        }
    }
}
int main(){
cin>>n>>m;
memset(h,-1,sizeof h);
while(m--){
    int a,b,c;
    cin>>a>>b>>c;
    add(a,b,c);
    add(b,a,c);
}
dijkstra();
cout<<dist_nmin[n];
return 0;
} 