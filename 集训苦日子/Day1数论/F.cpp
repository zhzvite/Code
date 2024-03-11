#include<iostream>
#include<cmath>
using namespace std;
int t;
int t1;
int euler_phi(int n){
    int ans=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            ans=ans/i*(i-1);
            while(n%i==0)n/=i;
        }
    }
     if(n>1)ans=ans/n*(n-1);
        return ans;

}
const int N=1010;
int size[N];
int cnt=0;
int n;
void solve(int x){
   if(x==n+1){
    cout<<t1-t<<" "<<n<<" "<<cnt+1<<endl;
    return;
   }
   else{
    cnt+=2*euler_phi(x);
    solve(x+1);
   }
}
int main(){
    cin>>t;
    t1=t;
    while(t--){
        cnt=0;
        cin>>n;
        solve(1);
      //cout<<euler_phi(1);

    }
}