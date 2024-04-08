#include<iostream>
using namespace std;
const int N=210;
int a[N][N],dp[N];
int n;
int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++)
        cin>>a[i][j];
        dp[i]=0x3f3f3f3f;
    }
    for(int i=n-1;i>=1;i--){
        for(int j=i;j<=n;j++){
            dp[i]=min(dp[i],a[i][j]+dp[j]);
        }
    }
    cout<<dp[1];
}