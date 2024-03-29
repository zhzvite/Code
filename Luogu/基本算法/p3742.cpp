#include<iostream>
#include<string>
using namespace std;
int n;
char s1[110], s2[110],s3[110];
int main(){
    cin >> n >> s1 >> s2;
    //字符串s1,s2,s3.
    //s1和s3挨个取最小得到s2
    //s1[i]要是有比s2[i]小就直接输出-1
    //s1[i]>=s2[i],s3[i]=s2[i]
    for (int i = 0; i<n;i++){
        if(s1[i]<s2[i]){
            cout << "-1" << endl;
           return 0;
        }
        else{
            s3[i] = s2[i];
        }
    }
    for (int i = 0; i < n;i++)
        cout << s3[i];
}