#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 5e5 + 5;
struct ac{
    int p, h, num;
};

bool cmp1(ac x, ac y) {
    return x.p < y.p;
}
bool cmp2(ac x, ac y) {
    return x.h < y.h;
}
vector<ac> b[maxn], f[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    int n;
    cin >> n;
    vector<ac> aa(n), bb(n);
    for (int i = 0; i < n; ++i) {
        cin >> aa[i].p;
    }
    for (int i = 0; i < n; ++i) {
        cin >> aa[i].h;
        aa[i].num = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> bb[i].p;
    }
    for (int i = 0; i < n; ++i) {
        cin >> bb[i].h;
        bb[i].num = i;
    }

    sort(aa.begin(), aa.end(), cmp1);
    sort(bb.begin(), bb.end(), cmp1);
    map<int, int> mp;
    int all_b = 0;
    for (int i = 0; i < n; ++i) {
        if (mp[aa[i].p] == 0) {
            mp[aa[i].p] = ++all_b;
        } 
        // cout << i << " " << mp[aa[i].p] << endl;
        int t = mp[aa[i].p];
        b[t].push_back({t, aa[i].h, aa[i].num});
    }
    // cout << all_b << endl;
    int all_f = 0;
    mp.clear();
    for (int i = 0; i < n; ++i) {
        if (mp[bb[i].p] == 0) {
            mp[bb[i].p] = ++all_f;
        } 
        int t = mp[bb[i].p];
        f[t].push_back({t, bb[i].h, bb[i].num});
    }
    // cout << all_f << endl;
    for (int i = 1; i <= all_f; ++i) {
        sort(f[i].begin(), f[i].end(), cmp2);
        // for (ac it : f[i]) {
            // cout << it.h << " " << it.num << "->";
        // }cout << endl;
    }
    // cout << "!!!\n";
    for (int i = 1; i <= all_b; ++i) {
        sort(b[i].begin(), b[i].end(), cmp2);
        for (ac it : b[i]) {
            // cout << it.h << " " << it.num << "->";
        }//cout << endl;
    }

    vector<P> ans;
    int flag = 0;
    int now = 1;
    int len = f[now].size();
    for (int i = 0; i < n && !flag; ++i) {
        int h = aa[i].h;
        int l = 0, r = len;
        while (l < r) {
            if (f[now][mid].h > h) r = mid;
            else l = mid + 1;
        }
        //cout << r << "!" << endl;
        if (f[now][r-1].h >= h) flag = 1;
        else {
            ans.push_back(P(aa[i].num, f[now][r-1].num));
            len--;
            f[now].erase(f[now].begin()+r-1);
        }
        if (len == 0) {
            now++;
            len = f[now].size();
        }
        // cout << i << " " << flag << endl;
        // for (auto it : ans) {
        //     cout << it.first + 1 << " ";
        // }cout << endl;
        // for (auto it : ans) {
        //     cout << it.second + 1 << " ";
        // }cout << endl;
        // cout << "------------\n";

    }
    if (flag) cout << "impossble\n";
    else {
        for (auto it : ans) {
            cout << it.first + 1 << " ";
        }cout << endl;
        for (auto it : ans) {
            cout << it.second + 1 << " ";
        }cout << endl;
    }


    
    return 0;
}


