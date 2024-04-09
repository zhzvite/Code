#include<iostream>
#include<cstdio>
#include<map>
#include<unordered_map>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
ll ans = 0;
struct NODE{
    int  fa, len;
    //unordered_map<int, int> ch;
    map<int, int> ch;
} node[N];
int n, tot = 1, last = 1;
void extend(ll c){
    int p = last, np = last = ++tot;
    node[np].len = node[p].len + 1;
    for (; p && !node[p].ch[c];p=node[p].fa)
        node[p].ch[c] = np;
    if(!p)
        node[np].fa = 1;
    else{
        int q = node[p].ch[c];
        if(node[q].len==node[p].len+1)
            node[np].fa = q;
        else{
            int copy = ++tot;
            node[copy] = node[q];
            node[copy].len = node[p].len + 1;
            node[q].fa = node[np].fa = copy;
            for (; p && node[p].ch[c] == q;p=node[p].fa)
                node[p].ch[c] = copy;    
        }
    }
    ans += node[np].len - node[node[np].fa].len;
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        ll x;
        scanf("%lld", &x);
        extend(x);
        printf("%lld\n", ans);
    }

}