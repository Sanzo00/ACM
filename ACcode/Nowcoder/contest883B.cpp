#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;
int a[maxn], pre[maxn], first[maxn];
char s[maxn]; 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	scanf("%d", &n);
	scanf("%s", s+1);
	int ans = 0, cnt = 0;
	for (int i = 1; i <= n; ++i) {
		a[i] = s[i] == '0' ? -1 : 1;
		if (a[i] == 1) cnt++;
		pre[i] = pre[i-1] + a[i]; 
		if (first[pre[i]] == 0) first[pre[i]] = i;
		if (pre[i] == 0) ans = max(ans, i);
		else if(first[pre[i]]) ans = max(ans, i - first[pre[i]]);
	}
	if (n - cnt < cnt) cnt = n - cnt;
	cout << ans << " " << cnt * 2 << endl;
	return 0;
}