#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
const int maxn = 1e6+6;
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
// __int128 read() {    __int128 x = 0, f = 1;  char c = getchar(); while (c < '0' || c > '9') {        if (c == '-') f = -1;       c = getchar();  }   while (c >= '0' && c <= '9') {      x = x * 10 + c - '0';       c = getchar();  }   return x * f;}
// void print(__int128 x) { if (x < 0) {        putchar('-');       x = -x; }   if (x > 9)  print(x / 10);  putchar(x % 10 + '0');}

struct SAM{

	int trans[maxn<<1][26], slink[maxn<<1], maxlen[maxn<<1];
	int last, now, root;
	
	void newnode (int v) {
		maxlen[++now] = v;
	}
	
	void extend(int c) {
		newnode(maxlen[last] + 1);
		int p = last, np = now;
		// 更新trans
		while (p && !trans[p][c]) {
			trans[p][c] = np;
			p = slink[p];
		}
		if (!p) slink[np] = root;
		else {
			int q = trans[p][c];
			if (maxlen[p] + 1 != maxlen[q]) {
				// 将q点拆出nq，使得maxlen[p] + 1 == maxlen[q]
				newnode(maxlen[p] + 1);
				int nq = now;
				memcpy(trans[nq], trans[q], sizeof(trans[q]));
				slink[nq] = slink[q];
				slink[q] = slink[np] = nq;
				while (p && trans[p][c] == q) {
					trans[p][c] = nq;
					p = slink[p];
				} 
			}else slink[np] = q;
		}
		last = np;
	}

	void build(string s) {
		root = last = now = 1;
		mem(trans, 0);
		mem(slink, 0);
		mem(maxlen, 0);
		int len = s.size();
		for (int i = 0; i < len; ++i) extend(s[i] - 'a');
	}
	// 求不同的子串种类
	LL all () {
		LL ans = 0;
		for (int i = root+1; i <= now; ++i) {
			ans += maxlen[i] - maxlen[ slink[i] ];
		}
		return ans;
	}
}sam;

int main() {
#ifndef ONLINE_JUDGE
   	// freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    sam.build(s);
    cout << sam.all() << endl;

    return 0;
}
