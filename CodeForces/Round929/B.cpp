#include<iostream>
using namespace std;
int t;
int n;
const int N = 2e5 + 10;
int sum;
int cnt1, cnt2;
//2 2 1 2,计几个1,几个2,可以选择丢掉一个数,或者是增加一
int main(){
    cin >> t;
    while(t--){
        cnt1 = 0, cnt2 = 0;
        cin >> n;
        sum = 0;
        for (int i = 1; i <= n;i++){
            int a;
            cin >> a;
            a = a % 3;
            if(a==1)
                cnt1++;
            if(a==2)
                cnt2++;
        }
        if((cnt1+2*cnt2)%3==0)
            cout << "0" << endl;
        else  if ((cnt1 + 2 * cnt2) % 3 == 1&&cnt1>0)
                cout << "1" << endl;
        else if ((cnt1 + 2 * cnt2) % 3 == 2 )
            cout << "1" << endl;
        else
            cout << "2" << endl;
    }
}