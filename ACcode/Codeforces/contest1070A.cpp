#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;

bool vis[505][5005];
int pre[505][5005][3];
int d, s;
void bfs() {
	vis[0][0] = 1;
	queue<int> qmod, qsum;
	qmod.push(0);
	qsum.push(0);
	while (!qmod.empty()) {
		int fmod = qmod.front();
		int fsum = qsum.front();
		qmod.pop();
		qsum.pop();
		for (int i = 0; i <= 9; ++i) {
			int now_mod = (10 * fmod + i) % d;
			int now_sum = fsum + i;
			if (vis[now_mod][now_sum] || now_sum > s) continue;
			qmod.push(now_mod);
			qsum.push(now_sum);
			vis[now_mod][now_sum] = 1;
			pre[now_mod][now_sum][0] = fmod;
			pre[now_mod][now_sum][1] = fsum;
			pre[now_mod][now_sum][2] = i;
		}
	}
}
void out(int x, int y) {
	if (x == 0 && y == 0) return;
	out(pre[x][y][0], pre[x][y][1]);
	cout << pre[x][y][2];
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> d >> s;
    bfs();
    if (vis[0][s] == 0) cout << -1 << endl;
    else out(0, s);
    
    return 0;
}