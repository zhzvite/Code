/*
你会得到一个2 × n的网格，里面充满了0和1。
令第i行和第j列的交点处的数字为a[i,j]。左上角的单元格(1, 1) 
有一个蚱蜢，只能向右或向下跳一个单元格。它想要到达右下角的单元格(2，n)。考虑长度为n + 1的二进制字符串，该字符串由在路径的单元中写入的数字组成，而不改变它们的顺序。
您的目标是 : 通过选择任何可用的路径，找到您可以获得的字典式最小字符串;
           找到产生这个字典式最小字符串的路径数。
如果两个字符串s和t具有相同的长度，当且仅当在s和t不同的第一个位置时，s在字典序上小于t，字符串s的元素小于t中相应的元素。
输入每个测试包含多个测试用例。第一行包含测试用例的数量t(1 ≤ t ≤ 1e4)。
测试用例的描述如下。每个测试用例的第一行包含一个整数n(2 ≤ n ≤ 2 ⋅ 105)。每个测试用例的第二行包含一个二进制字符串a11a12…a1n(a1i为0或1)。每个测试用例的第三行包含一个二进制字符串a21a22…a2n(a2i为0或1)。保证所有测试用例的n之和不超过2 ⋅ 1e5
输出对于每个测试用例，
输出两行:    通过选择任何可用路径可以获得的字典最小的字符串;
            产生此字符串的路径数。
*/
#include<iostream>
using namespace std;
const int N = 2e5 + 10;
int n, t;
char a1[N], a2[N];
char a[N];
int cnt = 0;
void find(int x,int y){
    if(x==1){
        if (((a1[y + 1] == '1' && a2[y] == '1') || (a1[y + 1] == '0' ) )&& y + 1 <= n)
        {
            a[cnt++] = a1[y + 1];
            find(1, y + 1);
        }
        if(y+1>n)
            {a[cnt++] = a2[y];
        return;}
        if((a1[y+1]=='1'&&a2[y]=='0')&&y+1<=n){
            for (int i = y; i <= n;i++)
                a[y + 1] = a2[y];
            return;
        }
    }
    
}

int main(){
    cin >> t;
    while(t--){
        cnt = 1;
        cin >> n;
        //cout << 1;
        for (int i = 1; i <= n;i++)
            {
                cin >> a1[i];
            }
        for (int i = 1; i <= n;i++)
            {
                cin >> a2[i];
            }
        //cout << 1;
        a[cnt++] = a1[1];
        find(1, 1);
        
    }
}
