#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
ll base=131;
ll a[10010];
int n;
string s;
int ans=1;
int prime=233317; 
ll mod=2123704401301379;
ll hashe(string s){
    int len=s.length();
    ll ans=0;
    for(int i=0;i<len;i++)
    ans=(ans*base+ll(s[i]))%mod+prime;
    return ans;

}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        a[i]=hashe(s);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<n;i++)
    {
        if(a[i]!=a[i+1])
        ans++;
    }
    cout<<ans;
}