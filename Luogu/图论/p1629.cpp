#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1010;
int n,m;
int g[N][N];
int dist[N];
bool st[N];
int ans;
void dijkstra() {
	memset(st, false, sizeof st);
	dist[1] = 0;
	for (int i = 0; i < n; i++)
	{
        int t = -1;
		for (int j =1; j <=n; j++) {
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		}
		st[t] = true;
		for (int j = 1; j <= n; j++) {
			dist[j] =min(dist[j], dist[t] + g[t][j]);
		}
	}
	// if (dist[n] == 0x3f3f3f3f)return -1;
	// else return dist[n];
}
int main() {
	cin >> n >> m;
	memset(dist, 0x3f, sizeof dist);
	memset(g, 0x3f, sizeof g);
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        g[x][y]=min(g[x][y],z);
    }
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a][b] = min(g[a][b], c);
	}
	dijkstra();
	for(int i=1;i<=n;i++){
        ans+=dist[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            swap(g[i][j],g[j][i]);
        }
    }
    memset(dist,0x3f,sizeof dist);
    dijkstra();
    for(int i=1;i<=n;i++){
        ans+=dist[i];
    }
    cout<<ans;

}