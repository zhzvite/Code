//如果从 （0， 0） 到 （x， y） 的线没有穿过任何其他晶格点，则从原点可以看到第一象限
//（x 和 y 是大于或等于 0 的整数）中的晶格点 （x， y）。例如，点 （4， 2） 不可见，
//因为原点的线穿过 （2， 1）。下图显示了 0 ≤ x 的点 （x， y）、y ≤ 5 以及从原点到可见点的线。
//编写一个程序，给定大小 N 的值，计算 0 ≤ x、y ≤ N 的可见点数 （x， y）。
//输入的第一行包含一个整数 C（1 ≤ C ≤ 1000），这是后面的数据集数。

//每个数据集由一行输入组成，其中包含一个整数 N（1 ≤ N ≤ 1000），即大小。
//对于每个数据集，将有一行输出，包括：从 1 开始的数据集编号、大小、以及该大小的可见点数。
/*
. . .
. . .
. . .  
*/
// 算斜率
#include<iostream>
#include<map>
#include<queue>
using namespace std;
int n;
int t;
int cnt;
map<double ,int> mp;
priority_queue<int ,vector<int>,less<int> >heap;

int main(){
    cin>>t;
    int t1=t;
    while(t--){
        cnt=0;
        cin>>n;
        if(heap.top()>n){
            for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
            mp[(double)j/i]++;
        }
        }
       
        // for(auto tt:mp){
        //     if(tt.second>0)cnt++;}
        //     cout<<t1-t<<" "<<n<<" "<<cnt+2<<endl;
        map<double ,int >::iterator it;
        for(it =mp.begin();it!=mp.end();it++)
        if(it->second>0)cnt++;
        cout<<t1-t<<" "<<n<<" "<<cnt+2<<endl;
           // mp.clear();
    }
}
