#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], b[maxn], c[maxn];
int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 2; i <= n; ++i) cin >> a[i];
    for (int i = 2; i <= n; ++i) cin >> b[i];
    int ev = k;
    for (int i = 2; i <= n; ++i) {
        int tev = min(b[i]+ev,k+b[i]);
        int tsa = a[i];
        if (tev <= tsa) {
            c[i] = tev + c[i-1];
            ev = 0;
        }else {
            c[i] = tsa + c[i-1];
            ev = tev - a[i];
        }
    }
    for (int i = 1; i <= n; ++i) cout << c[i] << " ";
    cout << endl;
    return 0;
}