#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 500 + 7;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		cin >> a[i][j];
    	}
    }
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		cin >> b[i][j];
    	}
    }
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		if (a[i][j] != b[i][j]) {
    			if (i == n-1 || j == m-1) {
    				cout << "No\n";
    				return 0;
    			}
    			a[i][j] ^= 1;
    			a[i][j+1] ^= 1;
    			a[i+1][j] ^= 1;
    			a[i+1][j+1] ^= 1; 
    		}
    	}
    }
    cout << "Yes\n";

    return 0;
}