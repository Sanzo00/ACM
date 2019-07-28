#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;
int a[maxn], v[maxn][3];
int dp[maxn][3][3], pre[maxn][3][3];
int ans[maxn];
int mid(int a, int b, int c) {
    int t[3] = {a, b, c};
    sort(t, t + 3);
    return t[1];
}
void find(int i, int j, int k) {
    while (i >= 1) {
        ans[i] = v[i][j];
        int nex = pre[i][j][k];
        j = k;
        k = nex;
        --i;
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 2; i <= n-1; ++i) {
            cin >> a[i];
        }
        a[0] = a[1] = a[2];
        a[n] = a[n+1] = a[n-1];
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 3; ++j) {
                v[i][j] = a[i+j-1];
            }
            sort(v[i], v[i]+3);
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    dp[i][j][k] = 0;
                }
            }
        }
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                dp[2][j][k] = 1;
            }
        }
        int flag = 0;
        for (int i = 3; i <= n; ++i) {
            for (int j = 0; j < 3 && !flag; ++j) {
                for (int k = 0; k < 3 && !flag; ++k) {
                    for (int l = 0; l < 3; ++l) {
                        if (dp[i-1][k][l] == 0) continue;
                        if (mid(v[i][j], v[i-1][k], v[i-2][l]) == a[i-1]) {
                            dp[i][j][k] = 1;
                            pre[i][j][k] = l;
                            break;
                        }
                    }  
                    if (i == n && dp[i][j][k]) {
                        flag = 1;
                        find(i, j, k);
                        goto here;
                    }
                }
            }
        }
        here:
        if (flag == 0) cout << -1 << endl;
        else {
            for (int i = 1; i <= n; ++i) {
                if (i > 1) cout << ' ';
                cout << ans[i];
            }
            cout << endl;
        }
    }
    return 0;
}