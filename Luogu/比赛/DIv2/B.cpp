#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=2e3+10;
typedef pair<int,int> pii;
int  g[N][N],d[N][N];
pii q[N*N],p[N][N];
char xp[N*N];
int n,m;
int t;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int cnt=0;
int  bfs(){
 int hh=0,tt=0;
//  memset(d,-1,sizeof d);
for(int i=0;i<=n;i++)
for(int j=0;j<=m;j++)d[i][j]=-1;
 q[0]={0,0};
 d[0][0]=0;
 while(hh<=tt){
    auto t=q[hh++];
    for(int i=0;i<4;i++){
        int x=t.first+dx[i],y=t.second+dy[i];
        if(x>=0&&x<n&&y>=0&&y<m&&g[x][y]!=g[t.first][t.second]&&d[x][y]==-1){
            d[x][y]=d[t.first][t.second]+1;
            p[x][y]=t;
            q[++tt]={x,y};
        }
    }
 }
return d[n-1][m-1];
}

int main(){
    cin>>t;
    while(t--){
        cnt=0;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char c;
                cin>>c;
                if(c=='0')g[i][j]=0;
                else g[i][j]=1;
                }
        }

      int ttt=bfs();
       cout<< ttt<<endl;
       int xx,yy,x,y;
       if(ttt!=-1){
          x=n-1,y=m-1;
         while(x||y){
        auto t=p[x][y];
        xx=t.first,yy=t.second;
        if(xx-x==-1)xp[cnt++]='D';
        else if(xx-x==1)xp[cnt++]='U';
        else if (yy-y==1)xp[cnt++]='L';
        else xp[cnt++]='R';
        //cout<<xx<<" "<<yy<<endl;
        x=xx,y=yy;
        
      }
      for(int i=cnt-1;i>=0;i--)cout<<xp[i];
      cout<<endl;
       }
    }
}