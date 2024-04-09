#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
struct Node
{
    int len, fa;
    int ch[26];
} node[N];
int n;
char str[N];
int tot = 1, last = 1;
int ans;
void extend(int c)
{
    int p = last, np = last = ++tot;
    node[np].len = node[p].len + 1;
    for (; p && !node[p].ch[c]; p = node[p].fa)
        node[p].ch[c] = np;
    if (!p)
        node[np].fa = 1;
    else
    {
        int q = node[p].ch[c];
        if (node[q].len == node[p].len + 1)
            node[np].fa = q;
        else
        {
            int copy = ++tot;
            node[copy] = node[q];
            node[copy].len = node[p].len + 1;
            node[q].fa = node[np].fa = copy;
            for (; p && node[p].ch[c] == q; p = node[p].fa)
                node[p].ch[c] = copy;
        }
    }
}
int main()
{
    cin >> str;
    for (int i = 0; str[i]; i++)
        extend(str[i] - 'a');
    cin >> str;
    int p = 1, len = 0;
    for (int i = 0; str[i];i++){
        int c = str[i] - 'a';
        if(node[p].ch[c])
            p = node[p].ch[c], len++;
        else{
            for (; p && !node[p].ch[c];p=node[p].fa);
                if(p)
                    len = node[p].len+1,p = node[p].ch[c];
                else len = 0, p = 1;
        }
        ans = max(ans, len);
    }
        cout << ans;
}