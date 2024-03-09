#include<iostream>
using namespace std;
const int N=2e5+10;
int t,n;
char a1[N],a2[N],a[N];
int main(){
    cin>>t;
    while(t--){
        cin >> n;
        for (int i = 1; i <=n;i++)
            cin >> a1[i];
        for (int i = 1; i <= n;i++)
            cin >> a2[i];
        int c = 0, i, l = 0, r = 0;
        for (i = 1; i < n;i++){
            if(a1[i+1]==a2[i])
                c++, r++;
            else if(a1[i+1]>a2[i])
                break;
            else
                c = 0, r = l = i + 1;
        }
        if(i<=n){
            for (int j = 1; j <= i;j++)
                printf("%c", a1[j]);
            for (int j = i; j <= n; j++)
                printf("%c", a2[j]);
        }
        else
        {
            printf("%s", a1+ 1);
            printf("%c", a2[n]);
        }
        printf("\n%d\n", c + 1);
    }
}