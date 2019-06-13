#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 500 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
char g[maxn][maxn];
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    int tot = 0, tmp = 1;
    int x = -1, y = -1, flag = 1;
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= m; ++j) {
    		cin >> g[i][j];
    		if (g[i][j] == '*') {
    			tot++;
    			if (tmp) {
    				if (g[i-1][j] == '*' && g[i][j-1] == '*' && g[i-1][j-1] == '.') x = i, y = j, tmp = 0;
    			}
    		}
    	}
    }
   	if (tot < 5) flag = 0;
   	tmp = 0;
   	for (int i = y; i <= m; ++i) {
   		if (g[x][i] == '*') tot--;
   		else break;
  		if (i == y && g[x][i+1] == '*') tmp++;
   	}
   	for (int i = y; i >= 1; --i) {
   		if (g[x][i] == '*') tot--;
   		else break;
  		if (i == y && g[x][i-1] == '*') tmp++;
   	}
   	for (int i = x; i >= 1; --i) {
   		if (g[i][y] == '*') tot--;
   		else break;
  		if (i == x && g[x+1][y] == '*') tmp++;
   	}
   	for (int i = x; i <= n; ++i) {
   		if (g[i][y] == '*') tot--;
   		else break;
  		if (i == x && g[x-1][y] == '*') tmp++;
   	}
   	tot += 3;
   	if (tot > 0 || tmp != 4) flag = 0;
   	if (flag) cout << "YES\n";
   	else cout << "NO\n";

    return 0;
}