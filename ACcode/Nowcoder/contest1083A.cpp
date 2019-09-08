#include <bits/stdc++.h>
#define endl '\n'
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int right_triangle(long long a, long long &b, long long &c) { // 已知直角边，求另外两个边
    if (a & 1) b = a * (a/2) + a/2, c = b + 1;
    else b = a * (a/2) / 2 - 1, c = b + 2;
    return (a > 0 && b > 0 && c > 0); 
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    long long a, b, c;
    scanf("%lld", &a);
    if (right_triangle(a, b, c)) printf("%lld %lld\n", b, c);
    else puts("-1");
    return 0;
}