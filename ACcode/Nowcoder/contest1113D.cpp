#include <bits/stdc++.h>
using namespace std;
string s, t;
int judge(int x) {
    if (s[x-1] >= 'a' && s[x-1] <= 'z' && s[x+1] >= 'a' && s[x+1] <= 'z') return 1;
    if (s[x-1] >= '0' && s[x-1] <= '9' && s[x+1] >= '0' && s[x+1] <= '9') return 1;
    return 0;
}
int main() {
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3 >> s;
    int len = s.size();
    for (int i = 0; i < len; ++i) {
        if (s[i] == '-' && i > 0 && i+1 < len && judge(i) && s[i+1] > s[i-1]) {
            string tmp;
            for (char j = s[i-1]+1; j < s[i+1]; ++j) {
                char c = j;
                if ((c < '0' || c > '9') && p1 == 2) c = c - 'a' + 'A';
                if (p1 == 3) c = '*';
                for (int k = 0; k < p2; ++k) tmp += c;
            }
            if (p3 == 2) reverse(tmp.begin(), tmp.end());
            t += tmp;
        }else t += s[i];
    }
    cout << t << endl;
    return 0;
}
