#include<iostream>
using namespace std;
int f(int x) {//小于等于x的奇数个数 
	if (!x) return 0;
	return (x + 1) / 2;
}
int g(int x) {//小于等于x的4的倍数个数 
	return x / 4;
}
int main() {
	int l, r; cin >> l >> r;
	cout << f(r) - f(l - 1) + g(r) - g(l - 1);
	return 0;
}
