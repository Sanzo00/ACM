---
CF-477C(Dreamoon and Strings)
---

[题目链接](https://codeforces.com/contest/477/problem/C)

#### 题意

两个串$S,T$,问$S$中删除$[1,|S|]$个字符之后,最多有多少个不重叠的T串

#### 思路

$dp$

$dp[i][j]$: 位置$i$前删除$j$个字符之后的最大值

$del$: 表示位置$i$前至少删除多少个字符出现串$T$

$dp[i][j] = max(dp[i-1][j], dp[i-|T|-del]+1)$

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 5;
const int inf = 0x3f3f3f3f;
char s[maxn], t[maxn];
int lens, lent;
int dp[maxn][maxn];
int calc(int x) {
    if (x < lent) return inf;
    int len = lent, cnt = 0;
    while (len && x) {
        if (s[x] == t[len]) x--, len--;
        else cnt++, x--;
    }
    if (len == 0) return cnt;
    else return inf;
}
int main() {
    scanf("%s%s", s+1, t+1);
    lens = strlen(s+1);
    lent = strlen(t+1);
    for (int i = 1; i <= lens; ++i) {
        int del = calc(i);
        for (int j = 0; j <= i; ++j) {
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if (i-lent-del < j-del || j-del < 0) continue;
            if(j-del >= 0) dp[i][j] = max(dp[i][j], dp[i-lent-del][j-del]+1);
        }
    }
    for (int i = 0; i <= lens; ++i) printf("%d ", dp[lens][i]);
    return 0;
}
```



