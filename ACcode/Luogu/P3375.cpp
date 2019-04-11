#include <bits/stdc++.h>
#define LL long long
#define uLL unsigned long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 19260817;
const int mod1 = 19260877;
const int seed = 131;

int nex[maxn];
char a[maxn], b[maxn];
int n, m;
void Nex() {
    nex[0] = -1;
    int i = 0, j = -1;
    while (i < m) {
        if (j == -1 || b[i] == b[j])
            nex[++i] = ++j;
        else 
            j = nex[j];
    }
}
int kmp() {
    Nex();
    int i = 0, j = 0;
    int ans = 0;
    while (i < n) {
        if (j == -1 || a[i] == b[j]) {
            ++i; ++j;
        }else {
            j = nex[j];
        }
        if (j == m) {
            ans++;
            cout << i-m+1 << endl;
            j = nex[j];
        }

    }
    return ans;
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> a >> b;
    n = strlen(a);
    m = strlen(b);
    kmp();
    for (int i = 1; i <= m; ++i) {
        if (i > 1) cout << " ";
        cout << nex[i];
    }
    cout << "\n";

}

