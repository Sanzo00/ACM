#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;
vector<int>g[maxn*3];
int col[maxn*3], row[maxn*3], sum[maxn];
multiset<int, greater<int>> st;
int n, r;
void del(int y) {
	st.erase(st.find(sum[y])), --sum[y], st.insert(sum[y]);
	if (y - r >= 0) st.erase(st.find(sum[y-r])), --sum[y-r], st.insert(sum[y-r]);
	if (y - r - r >= 0) st.erase(st.find(sum[y-r-r])), --sum[y-r-r], st.insert(sum[y-r-r]);
}
void add(int y) {
	st.erase(st.find(sum[y])), ++sum[y], st.insert(sum[y]);
	if (y - r >= 0) st.erase(st.find(sum[y-r])), ++sum[y-r], st.insert(sum[y-r]);
	if (y - r - r >= 0) st.erase(st.find(sum[y-r-r])), ++sum[y-r-r], st.insert(sum[y-r-r]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    scanf("%d%d", &n, &r);
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        col[y]++;
        row[x]++;
    }
    st.clear();
    for (int i = 0; i < maxn; ++i) {
        sum[i] = col[i] + col[i+r] + col[i+r+r];
        st.insert(sum[i]);
    }
    int ans = 0;
    for (int i = 0; i < maxn; ++i) {
        int t = row[i] + row[i+r] + row[i+r+r];
        // del
        for (int j = 0; j < row[i]; ++j) del(g[i][j]);
        for (int j = 0; j < row[i+r]; ++j) del(g[i+r][j]);
        for (int j = 0; j < row[i+r+r]; ++j) del(g[i+r+r][j]);
        ans = max(ans, t + *st.begin());
    	// add
    	for (int j = 0; j < row[i]; ++j) add(g[i][j]);
        for (int j = 0; j < row[i+r]; ++j) add(g[i+r][j]);
        for (int j = 0; j < row[i+r+r]; ++j) add(g[i+r+r][j]);
    }
    printf("%d\n", ans);
    return 0;
}