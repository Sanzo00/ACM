#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 3e5 + 5;
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
int RL[maxn << 1];
void Manacher(string s) {
	string t;
	for (int i = 0; i < (int)s.size(); ++i) {
		t += s[i];
		t += '#';
	}
	s = "#" + t;
	int MaxRight = 0, pos = 0;
	for (int i = 0; i < (int)s.size(); ++i) {
   		if (i < MaxRight)	RL[i] = min(RL[2 * pos - i], MaxRight - i + 1); // 好多这里写的是 MaxRight - i，个人感觉根据算法思想应该+1计算长度。
   		else 	RL[i] = 1;
   		int l = i - RL[i];
   		int r = i + RL[i];
   		while (l >= 0 && r < (int)s.size() && s[l] == s[r])	{
   			RL[i] += 1;
   			l = i - RL[i];
   			r = i + RL[i];
   		}
   		if (RL[i] + i - 1 > MaxRight) {
   			MaxRight = RL[i] + i - 1;
   			pos = i;
   		}
   	}
}
int ans[maxn], pos[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string s;
	while (cin >> s) {
		int len = s.size();
		Tree.init();
		for (int i = 0; i <= len * 2; ++i) RL[i] = 0;
		for (int i = 1; i <= len; ++i) ans[i] = 0;

		Manacher(s);
		for (int i = 0; i < len; ++i) {
			Tree.add(s[i]);
			pos[Tree.last] = i; 
		}
		Tree.count();
		for (int i = 2; i < Tree.p; ++i) {
			int t = Tree.len[i] / 2;
			int idx = (pos[i] - t - (Tree.len[i] - t) / 2) * 2 + 1;
			if ((Tree.len[i] - t) % 2 == 0) idx += 1;  
			if (RL[idx] - 1 >= Tree.len[i] - t) {
				ans[Tree.len[i]] += Tree.cnt[i];
			}
		}
		for (int i = 1; i <= len; ++i) {
			if (i > 1) cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}