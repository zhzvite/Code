#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e6 + 10;
char s[N];
int t;
int n;
int cnt;
bool st[N];
int main(){
    cin >> t;
    while(t--){
        cnt = 0;
        cin >> n;
        cin >> s + 1;
        memset(st, false, sizeof st);
        for (int i = 3; i <= n - 2;i++){
            if(s[i-2]=='m'&&s[i-1]=='a'&&s[i]=='p'&&s[i+1]=='i'&&s[i+2]=='e')
                {st[i - 1] = true;
                    st[i + 1] = true;
                    cnt++;
                }

        }
            for (int i = 2; i <= n - 1; i++)
            {

                if (s[i - 1] == 'm' && s[i] == 'a' && s[i + 1] == 'p'&&!st[i])
                    cnt++;
                if (s[i - 1] == 'p' && s[i] == 'i' && s[i + 1] == 'e'&&!st[i])
                    cnt++;
            }
        cout << cnt << endl;
    }
}
//mapie

