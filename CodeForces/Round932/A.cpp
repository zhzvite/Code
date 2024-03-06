#include<iostream>
#include<cstring>
using namespace std;
const int N = 110;
int t, n, len;
char s[N];
int flag;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        cin >> s ;
        flag = 3;
        len=strlen(s);
        if(n%2==0){
            for (int i = 0; i <= len / 2;i++){
                if(s[i]<s[len-i-1]){
                    flag = 1;
                    break;
                }
                if(s[i]>s[len-i-1]){
                    flag = 3;
                    break;
                }
                if(i==len/2)
                    flag = 2;
            }
            if(flag==1||flag==2)
                cout << s<<endl;
            if(flag==3){
                for (int i = len - 1; i >= 0;i--)
                    cout << s[i];
                cout << s;
                cout << endl;
            }
        }
    }
}