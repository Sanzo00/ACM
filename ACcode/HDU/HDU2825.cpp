#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int mod = 20090717;
const int inf = 0x3f3f3f3f;
using namespace std;
struct Trie{
    int nex[maxn][26], fail[maxn], end[maxn];
    int root, p;
    inline int newnode() {
        for (int i = 0; i < 26; ++i) {
            nex[p][i] = -1;
        }
        end[p++] = 0;
        return p - 1;
    }
    inline void init() {
        p = 0;
        root = newnode();
    }
    inline void insert(char *buf, int id) {
        int now = root;
        for (int i = 0; buf[i]; ++i) {
            if (nex[now][buf[i]-'a'] == -1) 
                nex[now][buf[i]-'a'] = newnode();
            now = nex[now][buf[i]-'a'];
        }
        end[now] |= (1 << id);
    } 
    inline void build() {
        queue<int> que;
        fail[root] = root;
        for (int i = 0; i < 26; ++i) {
            if (nex[root][i] == -1)
                nex[root][i] = root;
            else {
                fail[nex[root][i]] = root;
                que.push(nex[root][i]);
            }
        }
        while (!que.empty()) {
            int now = que.front();
            que.pop();
            end[now] |= end[fail[now]];
            for (int i = 0; i < 26; ++i) {
                if (nex[now][i] == -1) 
                    nex[now][i] = nex[fail[now]][i];
                else {
                    fail[nex[now][i]] = nex[fail[now]][i];
                    que.push(nex[now][i]);
                }
            }
        }
    }
    
}ac;
char s[15];
int dp[26][101][1025];
int num(int x) {
	int cnt = 0;
	while (x) cnt += x & 1, x >>= 1;
	return cnt;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m, p;
	while (scanf("%d %d %d", &n, &m, &p), n) {
		ac.init();
		for (int i = 0; i < m; ++i) {
			scanf("%s", s);
			ac.insert(s, i);
		}
		ac.build();
		memset(dp, 0, sizeof(dp));
		dp[0][0][0] = 1;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < ac.p; ++j) {
				for (int q = 0; q < (1 << m); ++q) {
					if (dp[i-1][j][q] == 0) continue;
					for (int k = 0; k < 26; ++k) {
						int v = ac.nex[j][k];
						dp[i][v][q | ac.end[v]] = (dp[i][v][q | ac.end[v]] + dp[i-1][j][q]) % mod;
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < ac.p; ++i) {
			for (int j = 0; j < (1 << m); ++j) {
				if (num(j) < p) continue;
				ans = (ans + dp[n][i][j]) % mod;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}