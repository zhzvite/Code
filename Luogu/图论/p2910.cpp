#include<iostream>
using namespace std;
int dist[110][110],a[10010],n,m,ans=0;
void floyd(){
    for(int k=1;k<=n;k++)
        for(int j=1;j<=n;j++)
            for(int i=1;i<=n;i++)
            dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)cin>>dist[i][j];
    floyd();
    for(int i=2;i<=m;i++)
    ans+=dist[a[i-1]][a[i]];
    cout<<ans;
}