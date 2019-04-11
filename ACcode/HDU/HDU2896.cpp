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
const int maxn = 1e5 + 5;
int len, num[maxn];
struct Trie{
    int nex[maxn][128], fail[maxn], end[maxn];
    int root, p;
    int newnode() {
        end[p++] = 0;
        return p-1;
    }
    void init() {
        p = 1;
        root = newnode();
    }
    void insert(char *s, int num) {
        int now = root;
        for (int i = 0; s[i]; ++i) {
            if (nex[now][(int)s[i]] == 0) {
                nex[now][(int)s[i]] = newnode();
            }
            now = nex[now][(int)s[i]];
        }
        end[now] = num;
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
        for (int i = 0; s[i]; ++i) {
            now = nex[now][(int)s[i]];
            int tmp = now;
            while (tmp != root) {
                if (end[tmp]) {
                    num[len++] = end[tmp];
                }
                tmp = fail[tmp];
            }
        }
        return len > 0;
    }
}ac;
char s[maxn];
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, m;
    scanf("%d", &n);
    ac.init();
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s);
        ac.insert(s, i);
    }
    ac.build();
    scanf("%d", &m);
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        scanf("%s", s);
        len = 0;
        cnt += ac.query(s);
        if (len) {
            sort(num, num + len);
            printf("web %d:", i+1);
            for (int j = 0; j < len; ++j) {
                printf(" %d", num[j]);
            }
            puts("");
        }

    }
    printf("total: %d\n", cnt);
}

