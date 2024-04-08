#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;
int dist[N], ans[N];
int cha[N][N];
bool st[N];
int n;
void dijkstra(){
    for (int i = 1; i < n;i++){
        int flg, minn = 0x3f3f3f3f;
        for (int i = 1; i <= n;i++){
            if(!st[i]&&dist[i]<minn)
                minn = dist[i], flg = i;
        }
        st[flg] = true;
        for (int i = 2; i <= n; i++)
            if(cha[i][flg]&&st[i]){
                if(dist[flg]+dist[i]==dist[cha[i][flg]])
                    ans[cha[i][flg]] += ans[i] * ans[flg];
                if(dist[flg]+dist[i]<dist[cha[i][flg]])
                    ans[cha[i][flg]] = ans[i] * ans[flg], dist[cha[i][flg]] = dist[i] + dist[flg];
            }
        
    }
}
int main(){
    cin >> n;
    for (int i = 1; i <= n;i++)
    {   cin >> dist[i];
        ans[i] = 1;
    }
    int a, b, c;
    while(cin>>a>>b>>c){
        cha[a+1][b+1] = c+1;
        cha[b+1][a+1] = c+1;
    }
    dijkstra();
    cout << dist[1] << " " << ans[1] << endl;
}