#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>

using namespace std;

const int maxn = 1000005;

char str[maxn];
int ans;
struct Suffix_Automaton
{
    int len[maxn << 1], link[maxn << 1];
    int ch[maxn << 1][26];
    int f[maxn << 1];
    std::vector<int> v[maxn << 1];
    int last, siz;
    inline const void init()
    {
        for (int i = 0; i <= maxn * 2 - 5; ++i)
            v[i].clear();
        memset(len, 0, sizeof len);
        memset(link, 0, sizeof link);
        memset(ch, 0, sizeof ch);
        link[0] = -1;
        siz = last = 0;
    }
    inline const void extend(char *str)
    {
        int n = std::strlen(str);
        for (int _ = 0; _ < n; ++_)
        {
            int c = str[_] - 'a', p = last, cur = ++siz;
            len[cur] = len[p] + 1;
            f[cur] = 1;
            while (p != -1 && !ch[p][c])
            {
                ch[p][c] = cur;
                p = link[p];
            }
            if (p == -1)
                link[cur] = 0;
            else
            {
                int q = ch[p][c];
                if (len[q] == len[p] + 1)
                    link[cur] = q;
                else
                {
                    int copy = ++siz;
                    len[copy] = len[p] + 1;
                    link[copy] = link[q];
                    for (int i = 0; i < 26; ++i)
                        ch[copy][i] = ch[q][i];
                    while (p != -1 && ch[p][c] == q)
                    {
                        ch[p][c] = copy;
                        p = link[p];
                    }
                    link[q] = link[cur] = copy;
                }
            }
            last = cur;
        }
        for (int i = 1; i <= siz; ++i)
            v[link[i]].push_back(i);
    }
    inline const int dfs(const int x)
    {
        for (int i = 0; i < v[x].size(); ++i)
        {
            int y = v[x][i];
            dfs(y);
            f[x] += f[y];
        }
        if (f[x] > 1)
            ans = std::max(ans, f[x]);
        return f[x];
    }
} sam;

signed main()
{
    scanf("%s", str);
    sam.init();
    sam.extend(str);
    sam.dfs(0);
    cout<<ans, putchar('\n');
    return 0;
}