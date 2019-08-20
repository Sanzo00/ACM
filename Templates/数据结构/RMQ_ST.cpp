// 预处理
int dp[maxn][30];
void ST(int n) {
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = a[i];
    }
    for (int j = 1; j <= log2(n); ++j) {
	    for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
	        dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
	    }
	}
}
// 查询
int RMQ(int l, int r) {
    int len = r - l + 1;
    int x = log2(len);
    // 将查询的区间分为两个区间进行查询
    return min(dp[l][x], dp[r - (1 << x) + 1][x]);
}
