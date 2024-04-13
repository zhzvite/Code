#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 2000010;
int tot = 1, last = 1,e[N], ne[N], h[N], idx;
struct Node
{
    int len, fa;
    int ch[26];
} node[N];
char str[N];
ll f[N], ans;
void extend(int c){
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
        else{
            int copy = ++tot;
            node[copy] = node[q];
            node[copy].len = node[p].len + 1;
            node[np].fa = node[q].fa = copy; // 父节点重定向
            for (; p && node[p].ch[c] == q; p = node[p].fa)
                node[p].ch[c] = copy; // 边重定向
        }
    }
}
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int u){
    for (int i = h[u]; ~i; i = ne[i])
    {
        dfs(e[i]);
        f[u] += f[e[i]];
    }
    if (f[u] > 1)
        ans = max(ans, f[u] * node[u].len);
}
int main(){
    scanf("%s", str);
    for (int i = 0; str[i]; i++)
        extend(str[i] - 'a');
    memset(h, -1, sizeof h);
    for (int i = 2; i <= tot; i++)
        add(node[i].fa, i);
    dfs(1);
    cout << ans;
    return 0;
}