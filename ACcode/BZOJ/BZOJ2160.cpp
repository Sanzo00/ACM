#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 1e6 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 19930726;
using namespace std;

struct Palindromic_Tree{
    int nex[maxn][26];
    int fail[maxn], cnt[maxn], num[maxn];
    int len[maxn], S[maxn];
    int last, n, p;
    int newnode(int l) {
        for (int i = 0; i < 26; ++i) nex[p][i] = 0;
        cnt[p] = num[p] = 0;
        len[p] = l;
        return p++;
    }
    void init() {
        p = 0;
        newnode(0), newnode(-1);
        last = n = 0;
        S[n] = -1;
        fail[0] = 1;
    }
    int get_fail(int x) {
        while (S[n - len[x] - 1] != S[n]) x = fail[x];
        return x;
    }
    void add(int c) {
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
    void count() {
        for (int i = p - 1; i >= 0; --i) cnt[fail[i]] += cnt[i];
    }
}Tree;
long long cnt[maxn];
long long Pow(long long a, long long b) {
	long long t = 1;
	while (b) {
		if (b & 1) t = t * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return t;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	long long n, m;
	string s;
	cin >> n >> m >> s;
	Tree.init();
	int len = s.size();
	for (int i = 0; i < len; ++i) {
		Tree.add(s[i]);
	}
	Tree.count();
	for (int i = 1; i < Tree.p; ++i) cnt[Tree.len[i]] += Tree.cnt[i];
	long long ans = 1;
	for (int i = len; i >= 1 && m; --i) {
		if (cnt[i] && (i & 1)) {
			ans = ans * Pow(i, min(m, cnt[i])) % mod;
			m -= min(m, cnt[i]);
		}
	}
	if (m) ans = -1;
	cout << ans << endl;

	return 0;
}