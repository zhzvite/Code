/*
有一个长度为n的数组a，你想把它分成k > 1个子段 †，这样每个子段上的MEX‡ 等于相同的整数。帮助Nyam - Nyam找到任何合适的除法，或确定它不存在。将数组划分为k个子段定义为k对整数(l1，r1)，(l2，r2)，…，(lk，rk)使得li ≤ ri并且对于每个1 ≤ j ≤ k - 1，lj + 1 = rj + 1，并且l1 = 1并且rk = n。这些对表示子段本身。‡ 数组的mex是不属于该数组的最小非负整数。例如 : 数组[2, 2，1] 的MEX为0，因为0不属于数组。数组[3, 1，0, 1] 的MEX是2，因为0和1属于数组，但2不属于。数组[0, 3，1, 2] 的MEX为4，因为0、1、2和3属于数组，但4不属于数组。输入每个测试由多个测试用例组成。第一行包含单个整数t(1 ≤ t ≤ 104) - 测试用例的数量。测试用例的描述如下。每个测试用例的第一行包含一个整数n(2 ≤ n ≤ 105) - 数组a的长度。每个测试用例的第二行包含n个整数a1，a2，…，an(0 ≤ ai < n) - 数组a的元素。保证所有测试用例的n之和不超过105。输出对于每个测试用例，如果不存在合适的除法，则输出单个整数 - 1。否则，在第一行上，输出整数k(2 ≤ k ≤ n) - 划分中的子段的数量。然后输出k行 - 分割成子段。第i行应包含两个整数li和ri(1 ≤ li ≤ ri ≤ n) - 第i个子段的边界。必须满足以下条件 : 对于所有1 ≤ j ≤ k - 1，lj + 1 = rj + 1;
l1 = 1，rk = n。如果有多个可能的解决方案，则输出其中任何一个。*/
#include<iostream>
using namespace std;
const int N = 2e5 + 10;
int t, n;
int a[N];
int k;
struct node{
    int l, r;
    int mex;
} tr[4 * N];
void pushup(int u){
    tr[u].mex
}

void build(int u,int l,int r){
    if(l==r){
        tr[u] = {l, l, a[l]};
    }
    else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n;i++)
            cin >> a[i];
    }
}