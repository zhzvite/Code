#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;
int t, n, m, k;
int a[N], b[N];
int cnt;
bool cmp(int a,int b){
    return a < b;
}
int main(){
    cin >> t;
    while(t--){
        cnt = 0;
        cin >> n >> m>>k;
        for (int i = 1; i <= n;i++)
            cin >> a[i];
        for (int i = 1; i <= m; i++)
            cin >> b[i];
        sort(a + 1, a + 1 + n, cmp);
        sort(b + 1, b + 1 + m, cmp);
        for (int i = 1; i <= n;i++){
            for (int j = 1; j <= m;j++)
            {
                if(a[i]+b[j]>k)
                    break;
                //cout << a[i] << " " << b[j] << endl;
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}