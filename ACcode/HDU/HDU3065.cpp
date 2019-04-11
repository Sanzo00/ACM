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
const int maxn = 5e4 + 5;
int num[maxn];
struct Trie{
    int nex[maxn][128], fail[maxn], end[maxn];
    int root, p;
    int newnode() {
        end[p++] = 0;
        return p-1;
    }
    void init() {
        mem(nex, 0);
        mem(fail, 0);
        mem(end, 0);
        mem(num, 0);
        p = 1;
        root = newnode();
    }
    void insert(char *s, int id) {
        int now = root;
        for (int i = 0; s[i]; ++i) {
            if (nex[now][(int)s[i]] == 0) {
                nex[now][(int)s[i]] = newnode();
            }
            now = nex[now][(int)s[i]];
        }
        end[now] = id;
    }
    void build() {
        queue<int> que;
        fail[root] = root;
        for (int i = 0; i < 128; ++i) {
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
            for (int i = 0; i < 128; ++i) {
                if (nex[now][i] == 0) {
                    nex[now][i] = nex[fail[now]][i];
                }else {
                    fail[nex[now][i]] = nex[fail[now]][i];
                    que.push(nex[now][i]);
                }
            }
        }
    }
    int query(char *s) {
        int now = root;
        int cnt = 0;
        for (int i = 0; s[i]; ++i) {
            now = nex[now][(int)s[i]];
            int tmp = now;
            while (tmp != root) {
                num[end[tmp]]++;
                cnt += end[tmp];
                tmp = fail[tmp];
            }
        }
        return cnt;
    }
}ac;
char s[maxn*50];
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    while (cin >> n) {
        ac.init();
        map<int, string> mp;
        for (int i = 1; i <= n; ++i) {
            cin >> s;
            mp[i] = s;
            ac.insert(s, i);
        }
        ac.build();
        cin >> s;
        ac.query(s);
        for (int i = 1; i <= n; ++i) {
            if (num[i]) {
                cout << mp[i] << ": " << num[i] << "\n";
            }
        }
    }
        return 0;
}

