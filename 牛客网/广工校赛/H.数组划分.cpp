#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 3e6 + 10;
int tot = 1, last = 1;
struct Node
{
    int len, fa;
    int ch[26];
} node[N];
char str[N];
ll f[N], ans;
void extend(int c)
{
    int p = last, np = last = ++tot;
    node[np].len = node[p].len + 1;
    f[tot] = 1;
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
            node[np].fa = node[q].fa = copy; // 父节点重定向
            for (; p && node[p].ch[c] == q; p = node[p].fa)
                node[p].ch[c] = copy; // 边重定向
        }
    }
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        for (int i = 1; i <= tot; i++)
        {
            f[i] = 0;
            node[i].fa = 0;
            node[i].len = 0;
            memset(node[i].ch, 0, sizeof node[i].ch);
        }
        ans = 0;
        tot = 1, last = 1;

        scanf("%s", str);
        for (int i = 0; str[i]; i++)
            extend(str[i] - 'a');
        for (int i = 2; i <= tot; i++)
            ans += node[i].len - node[node[i].fa].len;
        cout << ans << endl;
    }
}