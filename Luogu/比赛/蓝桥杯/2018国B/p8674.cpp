#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
typedef pair<int,int> pii;
const int N=1e5+10;
int dist[N],k,st[N];
int n;
priority_queue<pii,vector<pii>,greater<pii> >heap;
int main(){
    cin>>n>>k;
    memset(dist,0x3f,sizeof dist);
    dist[0]=0;
    heap.push({0,0});
    while(!heap.empty()){
        auto tt=heap.top();
        heap.pop();
        int distance=tt.first,val=tt.second;
        if(st[val])continue;
        st[val]=true;
        int y1=(val+1)%n,y2=(val+k)%n;
      if(dist[y1]==0x3f3f3f3f)
       { dist[y1]=distance+1;
       heap.push({dist[y1],y1});}
        if(dist[y2]==0x3f3f3f3f)
       { dist[y2]=distance+1;
       heap.push({dist[y2],y2});}


    }
    int ans=0;
    for(int i=1;i<n;i++)ans=max(ans,dist[i]);
   // cout<<i<<" "<<dist[i]<<endl;
   cout<<ans;

}
