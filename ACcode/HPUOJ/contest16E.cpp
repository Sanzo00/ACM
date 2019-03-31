#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> g[1000];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    string s;
    cin >> s;
    int len = s.size();
    for (int i = 0; i < len; ++i) {
        int t = s[i];
        g[t].push_back(i);
    }
    for (int i = 'a'; i <= 'z'; ++i) {
        if (g[i].empty()) continue;
        int ll = g[i].size();
        if (ll == 1) {
            cout << char(i) << ":0" << endl;
        }else {
            int tmp = g[i][1] - g[i][0];
            for (int j = 2; j < ll; ++j) {
                tmp = min(tmp, g[i][j] - g[i][j-1]);
            }
            cout << char(i) << ":" << len - tmp << endl;
        }
    }
    for (int i = 'A'; i <= 'Z'; ++i) {
        if (g[i].empty()) continue;
        int ll = g[i].size();
        if (ll == 1) {
            cout << char(i) << ":0" << endl;
        }else {
            int tmp = g[i][1] - g[i][0];
            for (int j = 2; j < ll; ++j) {
                tmp = min(tmp, g[i][j] - g[i][j-1]);
            }
            cout << char(i) << ":" << len - tmp << endl;
        }
    }

    return 0;
}