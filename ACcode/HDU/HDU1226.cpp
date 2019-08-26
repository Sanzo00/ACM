#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
using namespace std;
char a[maxn], vis[maxn];
int n, c, m;
struct ac{
	char s[511];
	int len, val;
};
void solve() {
	fill(vis, vis+n+1, 0);
	queue<ac> que;
	for (int i = 0; i < m; ++i) {
		if (a[i] == '0') continue;
		ac t;
		t.len = t.val = 0;
		t.s[t.len++] = a[i];
		int val = a[i] <= '9' ? a[i]-'0' : a[i] - 'A' + 10;
		t.val = val % n; 
		if (vis[t.val]) continue;
		vis[t.val] = 1;
		que.push(t);
		if (t.val == 0) {
			t.s[t.len] = 0;
			puts(t.s);
			return; 
		}
	}
	while (!que.empty()) {
		ac f = que.front();
		que.pop();
		if (f.len >= 500) {
			puts("give me the bomb please");
			return;
		}
		int val = f.val;
		vis[val] = 0;
		for (int i = 0; i < m; ++i) {
			int t = a[i] <= '9' ? a[i]-'0' : a[i] - 'A' + 10;
			t = val * c + t;
			t %= n;
			if (vis[t]) continue;
			vis[t] = 1;
			f.s[f.len++] = a[i];
			f.val = t; 
			que.push(f);
			if (t == 0) {
				f.s[f.len] = 0;
				puts(f.s);
				return;
			}
			f.len--;
			f.val = val;
		}
	}
	puts("give me the bomb please");
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &c, &m);
		for (int i = 0; i < m; ++i) scanf(" %c", &a[i]);
		sort(a, a + m);
		if (n == 0 && a[0] == '0') {
			puts("0");
			continue;
		}
		if (n == 0 && a[0] != '0') {
			puts("give me the bomb please");
			continue;
		}
		solve();
	}
	return 0;
}