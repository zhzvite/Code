#include<iostream>
#define int long long 
using namespace std;
const int N=1e6+10;
int n,m;
int f[N];
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int v1,v2,c;
        cin>>v1>>v2>>c;
        for(int j=m;j>=c;j--){
            f[j]=max(f[j]+v1,f[j-c]+v2);
        }
        for(int j=c-1;j>=0;j--){
            f[j]+=v1;//考虑打不过的时候价值直接加v1就行
        }
    }
    cout<<5*f[m];
}
