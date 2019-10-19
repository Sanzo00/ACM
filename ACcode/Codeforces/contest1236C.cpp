#include <bits/stdc++.h>
const int maxn = 3e2 + 5;
const int mod = 1e9 + 7;
using namespace std;
int a[maxn][maxn];
int main() {
    int n;
    cin >> n;
    int now = n * n;
    for (int i = n; i >= 1; i -= 2) {
        for (int j = n; j >= 1; --j) {
            a[j][i] = now--;
        }
        now -= n;
    }
    now = n+1;
    for (int i = 2; i <= n && (n&1); i += 2) {
        for (int j = n; j >= 1; --j) {
            a[j][i] = now++;
        }
        now += n;
    }
    now = 1;
    for (int i = 1; i <= n && (n%2==0); i += 2) {
        for (int j = n; j >= 1; --j) {
            a[j][i] = now++;
        }
        now += n;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}