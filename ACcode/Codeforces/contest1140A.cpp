#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
const int maxn = 10005;
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;

int a[maxn];
int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);   
    int n;
    cin >> n;
    for (int i  = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    set<int> st;
    for (int i = 1; i <= n; ++i) {
        st.insert(a[i]);
        st.erase(i);
        if (st.empty()) ans++;
    }
    cout << ans << endl;
    

    return 0;
}