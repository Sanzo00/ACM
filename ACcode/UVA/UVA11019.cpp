#include <bits/stdc++.h>
#define LL long long
#define uLL unsigned long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 1e4 + 5;
int num[1001][1002];
int n, m, x, y;
struct Trie{
    int nex[maxn][26], fail[maxn];
    vector<int>end[maxn];
    int root, p;
    int newnode() {
        return p++;
    }
    void init() {
        mem(nex, 0);
        mem(fail, 0);
        for (int i = 0; i < maxn; ++i)  end[i].clear();
        mem(num, 0);
        p = 1;
        root = newnode();
    }
    void insert(char *s, int id) {
        int now = root;
        for (int i = 0; s[i]; ++i) {
            if (nex[now][s[i]-'a'] == 0) {
                nex[now][s[i]-'a'] = newnode();
            }
            now = nex[now][s[i]-'a'];
        }
        end[now].push_back(id);
    }
    void build() {
        queue<int> que;
        fail[root] = root;
        for (int i = 0; i < 26; ++i) {
            if (nex[root][i] == 0) {
                nex[root][i] = root;
            }else {
                fail[nex[root][i]] = root;
                que.push(nex[root][i]);
            } 
        }
        while (!que.empty()) {
            int now = que.front();
            que.pop();
            for (int i = 0; i <26; ++i) {
                if (nex[now][i] == 0) {
                    nex[now][i] = nex[fail[now]][i];
                }else {
                    fail[nex[now][i]] = nex[fail[now]][i];
                    que.push(nex[now][i]);
                }
            }
        }
    }
    void solve(int i, int j, int k) {
        if (i < k || j < y-1) return;
        num[i - k][j - y+1]++;
        return;
    }
    int query(char *s, int id) {
        int now = root;
        int cnt = 0;
        for (int i = 0; s[i]; ++i) {
            now = nex[now][s[i]-'a'];
            int tmp = now;
            while (tmp != root) {
                for (int j = 0; j < (int)end[tmp].size(); ++j) {
                    solve(id, i, end[tmp][j]);
                }
                tmp = fail[tmp];
            }
        }
        return cnt;
    }
}ac;
char s[1002][1001], t[102][101];
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        ac.init();
        cin >> n >> m;
        for (int i = 0; i < n; ++i) cin >> s[i];
        cin >> x >> y;
        for (int j = 0; j < x; ++j) {
            cin >> t[j];
            ac.insert(t[j], j);
        }
        ac.build();
        for (int i = 0; i < n; ++i) ac.query(s[i], i);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (num[i][j] == x) ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}

