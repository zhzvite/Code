//思路:建两个二维数组
/*
a[i][j],表示顺时针距离i这个人j距离的点是:a[i][j]
b[i][j]为逆时针
在存放一个数组
每1输入一个值便更新一遍
*/
#include<iostream>
#include<queue>
#include<set>
using namespace std;
const int N = 1010;
int n, m, t;
int x;
char op;
int step;
int a[N][N];
int b[N][N];
queue<int> heap1;
queue<int> heap2;
set<int> ss,s1,s2;
void create(int n){
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;j++)
        {
            // if(i==j)
            //     a[i][j] = 0;
            // else {
                a[i][j] = (i+j)%n;
            // }
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            // if (i == j)
            //     b[i][j] = 0;
            // else
            // {
                b[i][j] = n-j+i;
            // }
        }
}

void update1(){
    if (!s1.empty())
    {
        for (std::set<int>::iterator it = s1.begin(); it != s1.end(); ++it)
        {
            s2.insert(a[*it][step]);
        }
        s1.clear();
    }
    else
    {
        for (std::set<int>::iterator it = s2.begin(); it != s2.end(); ++it)
        {
            s1.insert(a[*it][step]);
        }
        s2.clear();
    }
}
void update2()
{
    if(!s1.empty()){
        for (std::set<int>::iterator it = s1.begin(); it != s1.end(); ++it)
        {
            s2.insert(b[*it][step]);
        }
        s1.clear();
    }
    else{
        for (std::set<int>::iterator it = s2.begin(); it != s2.end(); ++it)
        {
            s1.insert(b[*it][step]);
        }
        s2.clear();
    }
    
}
void update3()
{
    if (!s1.empty())
    {
        for (std::set<int>::iterator it = s1.begin(); it != s1.end(); ++it)
        {
            s2.insert(b[*it][step]);
            s2.insert(a[*it][step]);
        //    cout << b[*it][step] << " " << a[*it][step] << endl;
        }
        s1.clear();
    }
    else
    {
        for (std::set<int>::iterator it = s2.begin(); it != s2.end(); ++it)
        {
            s1.insert(b[*it][step]);
            s1.insert(a[*it][step]);
        }
        s2.clear();
    }
}
int main(){
        cin >> t;
        while(t--){
            cin >> n >> m >> x;
            create(n);
            s1.insert(x);
            for (int i = 1; i <= m;i++){
                cin >> step;
                cin >> op;
                if(op=='1')
                    update1();    
                else if (op == '2')
                    update2();
                    else {
                        update3();
                    }
            }
            if(!s1.empty()){
                for (std::set<int>::iterator it = s1.begin(); it != s1.end(); ++it)
                {
                    std::cout << *it << ' ';
                }
                cout << endl;
            }
            else{
                for (std::set<int>::iterator it = s2.begin(); it != s2.end(); ++it)
                {
                    std::cout << *it << ' ';
                }
                cout << endl;
            }
            
        }
}
