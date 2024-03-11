#include<iostream>
using namespace std;
const int N = 2e5 + 10;
typedef long long ll;
ll  a[N];
int t;
int n;
bool flag;
int ans, res;
int main(){
    cin >> t;
    while(t--){
        flag=true;
        cin >> n;
        for (int i = 1;i<=n;i++){
            cin >> a[i];
        }
        
        for (int i = 2; i <= n-1;i++){
            if(a[i-1]<0||a[i]<0||a[i+1]<0){
                flag = false;
                break;
            }
            a[i] = a[i] - 2 * a[i-1];
            a[i + 1] = a[i + 1] - a[i - 1];
            a[i - 1] = a[i - 1] - a[i - 1];
        }
        a[1] = 0;
        for (int i = 1; i <= n;i++)if(a[i]!=0){
                //cout << i << " " << a[i] << endl;
                flag = false;
                break;
        }
            if (flag)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
    }
}
// 1 3 5 5 2
// 0 1 4 5 2
// 0 0 2 4 2
// 0 0 0 0 0 
