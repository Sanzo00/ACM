#include <bits/stdc++.h>
#define psi pair<string,int>
#define endl "\n"
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;
int n, m, op, T, v, t;
string s;
list<psi> LRU;
unordered_map<string, list<psi>::iterator> mp;
void add() {
    if (mp.find(s) != mp.end()) {
        auto it = mp[s];
        cout << it->second << endl;
        LRU.push_front(*it);
        mp[s] = LRU.begin();
        LRU.erase(it);
    }else {
        cout << v << endl;
        if (t == m) {
            auto it = LRU.end();
            --it;
            LRU.pop_back();
            mp.erase(it->first);
            t--;
        }
        LRU.push_front(make_pair(s, v));
        mp[s] = LRU.begin();
        t++;
    }
}
void search() {
    if (mp.find(s) == mp.end()) {
        cout << "Invalid\n";
        return;
    }
    auto it = mp[s];
    if (v == 0) {
        cout << it->second << endl;
    }
    if (v == 1) {
        if (it == LRU.begin()) cout << "Invalid\n";
        else cout << (--it)->second << endl;
    }
    if (v == -1) {
        ++it;
        if (it == LRU.end()) cout << "Invalid\n";
        else cout << it->second << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        LRU.clear();
        mp.clear();
        t = 0;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> op >> s >> v;
            op ? search() : add();
        }      
    }
    return 0;
}