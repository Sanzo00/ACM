## CF-85E.Guard Towers(二分+染色)

[题目链接](https://codeforces.com/contest/85/problem/E)

#### 题意

$n$个灯塔分成2分,求出最小的曼哈顿距离和其方案树

#### 题意

二分+染色

二分枚举最小值$mid$,判断能否将$n$个灯塔分为最大曼哈顿值不超过$mid$的两份

方案数=$2^{联通块个数}$

```cpp
#include <bits/stdc++.h>
const int maxn = 5e3 + 5;
const int mod = 1e9 + 7;
using namespace std;
pair<int,int> a[maxn];
int cnt, vis[maxn], n;
long long Pow(long long a, long long b) {
    long long ans = 1;
    while (b) {
        if (b & 1) {
            ans *= a;
            ans %= mod;
        }
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return ans;
}
int dfs(int u, int c, int mid) {
    for (int i = 0; i < n; ++i) {
        int len = abs(a[i].first - a[u].first) + abs(a[i].second - a[u].second);
        if (len <= mid || vis[i] == (c^1)) continue;
        if (vis[i] == c) return -1;
        vis[i] = c ^ 1;
        if (dfs(i, c^1, mid) == -1) return -1; 
    }
    return 1;
}
int check(int mid) {
    fill(vis, vis+maxn, -1);
    cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (vis[i] == -1) {
            cnt++;
            vis[i] = 0;
            if (dfs(i, 0, mid) == -1) return -1;
        }   
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a[i].first, &a[i].second);
    }
    int l = 0, r = 1e4;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid) == -1) l = mid + 1;
        else r = mid - 1;       
    }
    check(l);
    printf("%d\n%lld\n", l, Pow(2, cnt));
    return 0;
}
```

