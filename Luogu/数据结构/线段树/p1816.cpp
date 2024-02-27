#include<iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 1e5 + 10;
struct node{
    int l, r;
    int minn = 0x7fffffff;
} tr[4 * N];
int w[N];
int n, m;
void pushup(int u){
    tr[u].minn = min(tr[u<<1].minn, tr[u << 1 | 1].minn);
}
void build(int u, int l, int r)
{ 
    if(l==r)
        tr[u] = {l, r, w[l]};
    else{
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}
int query(int u,int l,int r){
    if(tr[u].l>=l&&tr[u].r<=r)
            return tr[u].minn;
    int mid = tr[u].l + tr[u].r >> 1;
    if (r <= mid)
        return query(u << 1, l, r); // 如果查询的区间完全在这个节点所代表的区间的左端，直接去查询左边
    if (l > mid)
        return query(u << 1 | 1, l, r); // 如果查询的区间完全在这个节点所代表的区间的右端，直接去查询右边
    return min(query(u << 1, l, mid), query(u << 1 | 1, mid + 1, r));
}
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> w[i];
    build(1, 1, n);
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        cout << query(1, x, y)<<" ";
    }
}