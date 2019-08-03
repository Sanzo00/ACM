#include <bits/stdc++.h>
#define endl '\n'
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
struct Palindrome_Tree{
    int nex[maxn][26];
    int fail[maxn], cnt[maxn], num[maxn]; // num 记录每个节点右端点的表示回文串的个数
    int len[maxn], S[maxn];                 // cnt 记录每个节点表示的回文串出现的次数
    int last, n, p;
    int sz[maxn], c[maxn], vis[maxn];
    int newnode(int l) { // 新建节点
        for (int i = 0; i < 26; ++i) nex[p][i] = 0;
        cnt[p] = num[p] = 0;
        len[p] = l;
        return p++;
    }
    void init() { // 初始化
        p = 0;
        newnode(0), newnode(-1); // 新建奇根和偶根
        last = n = 0;
        S[n] = -1;
        fail[0] = 1; // 偶根指向
    }
    int get_fail(int x) { // 求fail
        while (S[n - len[x] - 1] != S[n]) x = fail[x];
        return x;
    }
    void add(int c) { // 添加节点
        c -= 'a';
        S[++n] = c;
        int cur = get_fail(last);
        if (!nex[cur][c]) {
            int now = newnode(len[cur] + 2);
            fail[now] = nex[get_fail(fail[cur])][c];
            nex[cur][c] = now;
            num[now] = num[fail[now]] + 1;
        }
        last = nex[cur][c];
        cnt[last]++;
    }
    void count() { // 求cnt
        for (int i = p - 1; i >= 2; --i) cnt[fail[i]] += cnt[i];
    }
	int dfs(int u) {
		sz[u] = 1;
		c[u] = 0;
		for (int t = u; !vis[t] && t > 1; t = fail[t]) {
			vis[t] = u;
			c[u]++;
		}
		for (int i = 0; i < 26; ++i) {
			if (nex[u][i] == 0) continue;
			sz[u] += dfs(nex[u][i]); 
		}
		for (int t = u; vis[t] == u && t > 1; t = fail[t]) {
			vis[t] = 0;
		}
		return sz[u];
	}
	long long solve() {
		dfs(0), dfs(1);
		long long ans = 0;
		for (int i = 2; i < p; ++i) {
			ans += 1ll * sz[i] * c[i];
		}
		return ans - p + 2;
	}
}Tree;
char s[maxn];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T, Case = 1;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        Tree.init();
        for (int i = 0; s[i]; ++i) {
            Tree.add(s[i]);
        }
        printf("Case #%d: %lld\n", Case++, Tree.solve());
    }
    return 0;
}