//循环同构串
//最小表示法
#include<iostream>
#include<string>
using namespace std;
const int N=3e5+10;
int a[N];
int n;
int ans;
int fuck(){
    int i=0,j=1,k=0;
    while(i<n&&j<n&&k<n){
        if(a[(i+k)%n]==a[j+k]%n)k++;
        else {
            if(a[(i+k)%n]<a[(j+k)%n])
            j+=k+1;
            else i+=k+1;
            k=0;
        }
        if(i==j)i++;
    }
   // cout<<i<<" "<<j;
    return min(i,j);


}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    ans=fuck();
    for(int i=0;i<n;i++){
        cout<<a[(i+ans)%n]<<" ";
    }
}