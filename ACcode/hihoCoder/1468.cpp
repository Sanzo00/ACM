#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
const int maxn = 1044373;
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;

int read() {
    int num = 0, flag = 1;
    char c = getchar();
    while (c < '0' || c > '9')  flag = (c == '-') ? -1 : 1, c = getchar();
    while (c >= '0' && c <= '9') num = (num << 3) + (num << 1) + c - '0', c = getchar();
    return num * flag;
}
void out(int x) {
    if (x > 9)  out(x / 10);
    putchar(x % 10 + '0');
}

vector<int> g[maxn];
int tmp[maxn], vis[maxn], len;

int other(int x) {
    if (x & 1) return x+1;
    else return x-1;
}

int dfs(int x) {

    if (vis[other(x)]) return 0;
    if (vis[x]) return 1;
    tmp[len++] = x;
    vis[x] = 1;
    // cout << x << endl;
    for (int i = 0, y; i < (int)g[x].size(); ++i) {
        y = g[x][i];
        if (dfs(y) == 0) return 0;
    }
    return 1;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    scanf("%d %d", &n, &m);
        
    for (int i = 0, l, r; i < m; ++i) {
        scanf("%d %d", &l, &r);
        g[l].push_back(other(r));
        g[r].push_back(other(l));


    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i*2] || vis[i*2-1]) continue;
        len = 0;
        if (dfs(i*2-1) == 0) {
            for (int j = 0; j < len; ++j) {
                vis[tmp[j]] = 0;
            }
            len = 0;
            if (dfs(i*2) == 0) {
                puts("NIE");
                return 0;
            }
        }
    }

    for (int i = 1; i <= n*2; ++i) 
        if (vis[i])   printf("%d\n", i);
   
    return 0;
}