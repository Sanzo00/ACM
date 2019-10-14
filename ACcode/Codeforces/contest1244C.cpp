#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, p, w, d;
    cin >> n >> p >> w >> d;
    long long y = 0, x;
    while (y <= w) {
        if (y*d > p) break;
        if ((p - y*d) % w == 0 && y + (p - y*d) / w <= n) {
            x = (p - y*d) / w;
            cout << x << " " << y << " " << n-x-y << endl;
            return 0; 
        }
        y++; 
    }
    cout << -1 << endl;
    return 0;
}