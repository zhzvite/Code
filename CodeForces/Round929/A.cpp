#include<iostream>
using namespace std;
int n;
int sum, res;
int main(){
    int t;
    cin >> t;
    while(t--){
         cin >> n;
         sum = 0;
         res = 0;
         for (int i = 1; i <= n; i++)
         {
             int a;
             cin >> a;
             sum += a;
             if(a<0)
                 res += a;

        }
        cout << sum - 2 * res << endl;
    }
}