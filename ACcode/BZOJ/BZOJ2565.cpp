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
}Pre, Suf;
int L[maxn], R[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	int len = s.size();
	Pre.init(); Suf.init();
	for (int i = 0; i < len; ++i) Pre.add(s[i]), L[i] = Pre.len[Pre.last];
	for (int i = len-1; i >= 0; --i) Suf.add(s[i]), R[i] = Suf.len[Suf.last];
	int ans = 0;
	for (int i = 0; i < len; ++i) {
		ans = max(ans, L[i] + R[i+1]);
	}
	cout << ans << endl;
	return 0;
}