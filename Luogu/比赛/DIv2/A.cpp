#include<iostream>
#include<string>
using namespace std;
string s;
int t;
int l,r;
int q;
const int N=1e7+10;
int a[N];
int main(){
    cin>>t;
    while(t--){
cin>>s;
s="#"+s;
int len=s.length()-1;
for(int i=1;i<=len;i++){
    if(s[i]=='P')a[i]=a[i-1]+3;
   else  if(s[i]=='p')a[i]=a[i-1]+2;
   else  if(s[i]=='G')a[i]=a[i-1]+1;
    else a[i]=a[i-1];
}
cin>>q;
//for(int i=0;i<=5;i++)cout<<a[i]<<endl;

while(q--){
    int l,r;
    cin>>l>>r;
  //  cout<<a[r]<<" "<<a[l-1];
    cout<<a[r]-a[l-1]<<endl;
}
}


}
