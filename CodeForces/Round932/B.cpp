#include<iostream>
#include<queue>
using namespace std;
const int N=2e5+10;
int t;
int a[N],mex1[N],mex2[N];
int n;
int MEX;
priority_queue<int ,vector<int>,greater<int> > heap;
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
           MEX=0;      
        for(int i=1;i<=n;i++){
            if(MEX<=a[i])
            heap.push(a[i]);
            while(MEX==heap.top()&&!heap.empty()){
                MEX++;
                while(MEX>heap.top()&&!heap.empty())
                heap.pop();   
            }
            mex1[i]=MEX;
        }
        while(!heap.empty())heap.pop();
         MEX=0;      
        for(int i=n;i>=1;i--){
            if(MEX<=a[i])
            heap.push(a[i]);
            while(MEX==heap.top()&&!heap.empty()){
                MEX++;
                while(MEX>heap.top()&&!heap.empty())
                heap.pop();   
            }
            mex2[n-i+1]=MEX;
        }
                while(!heap.empty())heap.pop();  

        for(int i=1;i<=n-1;i++){
            if(mex1[i]==mex2[n-i]){
                cout<<2<<endl;
                cout<<1<<" "<<i<<endl;
                cout<<i+1<<" "<<n<<endl;
                break;
            }
            if(i==n-1)cout<<"-1"<<endl;
        }

    }
}