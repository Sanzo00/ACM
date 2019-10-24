#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], b[maxn];
int main() {
    int q, n;
    cin >> q;
    while (q--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i]; 
        }
        for (int i = 1; i <= n; ++i) {
            if (b[i]) continue;
            int t = i, cnt = 1;
            set<int> st;
            st.insert(i);
            while(a[t] != i) {
                cnt++;
                t = a[t];
                st.insert(t);
            }
            for (auto it : st) {
                b[it] = cnt;
            }
        }
        for (int i = 1; i <= n; ++i) cout << b[i] << ' ', b[i] = 0;
        cout << endl; 
    }
        
    return 0;
}
