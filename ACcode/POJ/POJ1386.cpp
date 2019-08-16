#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int n, all, num, in[maxn], out[maxn], pre[maxn];
char s[maxn];
int check() {
	int cnt1 = 0, cnt2 = 0;
	for (int i = 1; i < num; ++i) {
		int t = out[i] - in[i];
		if (fabs(t) > 1) return 0;
		if (t == 1) cnt1++;
		if (t == -1) cnt2++;
		if (cnt1 > 1 || cnt2 > 1) return 0;
	}
	return 1;
}
int find(int x) {
	int t = x;
	while (x != pre[x]) x = pre[x];
	while (pre[t] != x) {
		int fa = pre[t];
		pre[t] = x;
		t = fa;
	}
	return x;
}
void join(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if (fx == fy) return;
	pre[fy] = fx;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		fill(in, in+30, 0);
		fill(out, out+30, 0);
		for (int i = 1; i <= 30; ++i) pre[i] = i;
		map<char,int> mp;
		num = 1;
		for (int i = 0; i < n; ++i) {
			scanf("%s", s);
			int len = strlen(s);
			if (mp[s[0]] == 0) mp[s[0]] = num++;
			if (mp[s[len-1]] == 0) mp[s[len-1]] = num++;
			in[mp[s[len-1]]]++;
			out[mp[s[0]]]++;
			join(mp[s[0]], mp[s[len-1]]);
		}
		all = 1;
		for (int i = 1; i < num; ++i){
			if (find(i) != find(1)) all = 0;
		}
		puts(check() && all ? "Ordering is possible." : "The door cannot be opened.");
	}

	return 0;
}