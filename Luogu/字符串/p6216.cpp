/*
统计次数：
s1的所有长度为奇数的回文字串中s2的次数
就是找出所有的回文字符串，转换出原字符串坐标后
再套一层kmp
蠢蠢的做法O(n)
*/
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=3e6+10;
char s[N],p[N],S[N<<1];
int hw[N<<1];
int n,m;
int main(){
    scanf("%d%d%s%s",&n,&m,s+1,p+1);
    
}
