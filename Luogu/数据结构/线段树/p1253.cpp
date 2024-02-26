// 初步估计需要l,r,maxn,add蓝标记和cha懒标记
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
struct node
{
    int l, r;
    ll maxn, add, cha;
    bool used;
} tr[4 * N];
ll w[N], n, m;
ll inf = -1e18;
void test()
{
    for (int u = 1; u <= 13; u++)
        printf("----%lld---%lld---%lld---%lld---%lld---%lld---%d---\n", u, tr[u].l, tr[u].r, tr[u].maxn, tr[u].add, tr[u].cha, tr[u].used);
}
void pushup(int u)
{
    tr[u].maxn = max(tr[u << 1].maxn, tr[u << 1 | 1].maxn);
}
void pushdown(int u)
{

    if (tr[u].add == 0 && tr[u].used == false)
        return;
    
    if (tr[u].used == true)
    { // 父节点change了
        tr[u << 1].used = tr[u << 1 | 1].used = true;
        tr[u << 1].maxn = tr[u << 1 | 1].maxn = tr[u].cha;
        tr[u << 1].cha = tr[u << 1 | 1].cha = tr[u].cha;
        tr[u].cha = 0;
        tr[u].used = false;
        // 覆盖子节点的同时要把子节点的所有标记给清空
        tr[u << 1].add = tr[u << 1 | 1].add = 0;
    }
    if (tr[u].add != 0)
    {
        tr[u << 1].add += tr[u].add, tr[u << 1 | 1].add += tr[u].add;
        tr[u << 1].maxn += tr[u].add, tr[u << 1 | 1].maxn += tr[u].add;
        tr[u].add = 0;
    }
    //    pushup(u);
}
void modify1(int u, int l, int r, ll d) // 覆盖标记
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].used = true; // 清除这个区间之前的所有标记
        tr[u].cha = d;
        tr[u].maxn = d;
        tr[u].add = 0;
    }
    else
    {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid)
            modify1(u << 1, l, r, d);
        if (r > mid)
            modify1(u << 1 | 1, l, r, d);
        pushup(u);
    }
}

void modify2(int u, int l, int r, ll d)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].add += d;
        tr[u].maxn += d;
    }
    else
    {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid)
            modify2(u << 1, l, r, d);
        if (r > mid)
            modify2(u << 1 | 1, l, r, d);
        pushup(u);
    }
}
void build(int u, int l, int r)
{
    if (l == r)
        tr[u] = {l, r, w[l], 0, 0, false};
    else
    {
        tr[u] = {l, r, 0, 0, 0, false};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}
ll query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u].maxn;
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    ll res = inf;
    if (l <= mid)
        res =max(res, query(u << 1, l, r));
    if (r > mid)
        res = max(res, query(u << 1 | 1, l, r));
    return res;
}
int main()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &w[i]);
    build(1, 1, n);
    //    test();
    while (m--)
    {
        ll tag, l, r, x;
        scanf("%lld%lld%lld", &tag, &l, &r);
        if (tag == 1)
        {
            scanf("%lld", &x);
            modify1(1, l, r, x);
            //    test();
        }
        if (tag == 2)
        {
            scanf("%lld", &x);
            modify2(1, l, r, x);
            // test();
        }
        if (tag == 3)
        {
            printf("%lld\n", query(1, l, r));
        }
    }
    return 0;
}
