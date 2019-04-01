#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        int flag = 1;
        int len = s.size();
        for (int i = 1; i < len; ++i) {
            if (s[i] - s[i-1] != 1) flag = 0;
        }
        if (flag) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}