#include <bits/stdc++.h>
const int maxn = 2e5 + 5;
using namespace std;
map<int, int> vis;
int a[maxn];
int main() {
    int n, m;
    cin >> n >> m;
    int len = 0;
    int now = 0;
    int pre = 0;
    for (int i = 1, d; i <= n; ++i) {
        cin >> d;
        if (vis[d]) continue;
        a[now++] = d;
        vis[d] = 1;
        if (len < m) len++;
        else {
            vis[a[pre++]] = 0;
        }
    }
    cout << now - pre << endl;
    for (int i = now-1; i >= pre; --i) cout << a[i] << " ";
    return 0;
}
