#include <bits/stdc++.h>
const int maxn = 2e5 + 5;
using namespace std;
struct ac{
    int x, y, c;
};
int a[3][maxn], vis[2][maxn];
int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 1; i <= n; ++i) a[1][i] = s[i-1] - '0';
        cin >> s;
        for (int i = 1; i <= n; ++i) a[2][i] = s[i-1] - '0';
        if (a[1][1] <= 2) a[1][1] = 2;
        else a[1][1] = 4;
        queue<ac> que;
        que.push({1, 1, a[1][1]});
        int flag = 0;
        while (!que.empty()) {
            auto it = que.front();
            que.pop();
            int x = it.x;
            int y = it.y;
            if (it.x == 2 && it.y == n && (it.c == 2 || it.c == 6)) {
                flag = 1;
                break;
            }
            if (it.y+1 <= n) {
                if (it.c == 2 && a[x][y+1] <= 2) que.push({x, y+1, 2});
                if (it.c == 2 && a[x][y+1] > 2) que.push({x, y+1, 4}), que.push({x, y+1, 5});
                if (it.c == 6 && a[x][y+1] <= 2) que.push({x, y+1, 2});
                if (it.c == 6 && a[x][y+1] > 2) que.push({x, y+1, 5});
                if (it.c == 3 && a[x][y+1] <= 2) que.push({x, y+1, 2});
                if (it.c == 3 && a[x][y+1] > 2) que.push({x, y+1, 4});
 
            }
            if (it.x+1 <= 2) {
                if (it.c == 1 && a[x+1][y] > 2) que.push({x+1, y, 6});
                if (it.c == 4 && a[x+1][y] > 2) que.push({x+1, y, 6});
            }
            if (it.x-1 >= 1) {
                if (it.c == 1 && a[x-1][y] > 2) que.push({x-1, y, 3});
                if (it.c == 5 && a[x-1][y] > 2) que.push({x-1, y, 3});
            }
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
