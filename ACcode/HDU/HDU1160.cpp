#include <bits/stdc++.h>
const int maxn = 5e4 + 5;
using namespace std;
int a[maxn], b[maxn], c[maxn], d[maxn];
int vis[maxn], used[maxn], path[maxn], n;
int LIS() {
    int len = 0;
    for (int i = 1; i <= n; ++i) {
        int it = lower_bound(d, d + len, a[i]) - d;
        if (it == len) {
        	d[len++] = a[i];
        	path[i] = len;
        }else {
        	d[it] = a[i];
        	path[i] = it + 1;
        }
    }
    fill(used, used+n+1, 0);
    int tmp = len;
    for (int i = n; i >= 1; --i) {
    	if (path[i] == tmp) used[i] = 1, tmp--;
    }
    return len;
}
struct ac{
	int x, y, id;
	bool operator < (const ac &t) {
		if (y != t.y) return y > t.y;
		else return x < t.x;
	}
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int aa, bb;
    vector<ac> v;
    int id = 1;
    while (cin >> aa >> bb) v.push_back({aa, bb, id++});
    n = v.size();
    sort(v.begin(), v.end());
    for (int i = 0; i < (int)v.size(); ++i) {
    	a[i+1] = v[i].x;
    }
    cout << LIS() << endl;
    for (int i = 1; i <= n; ++i) {
    	if (used[i] == 0) continue;
    	cout << v[i-1].id << endl;
    }
    return 0;
}