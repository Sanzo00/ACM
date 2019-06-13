#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 1e6 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
map<char,int> mp; 
int maxlen;
void solve(string s, int &x, char &y) {
	int len = s.size();
	maxlen = max(maxlen, len);
	x = 0;
	for (int i = 0; i < len; ++i) {
		if (mp[s[i]]) {
			x++;
			y = s[i];
		}
	}
}
vector<string> all[maxn];
void push(pair<int,string> t) {
	all[t.first].push_back(t.second);
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    mp['a'] = 1;
    mp['e'] = 2;
    mp['i'] = 3;
    mp['o'] = 4;
    mp['u'] = 5;
    int n, cnt;
    char c;
    string s;
    cin >> n;
    vector< pair<int,string> > g[10];
    for (int i = 0; i < n; ++i) {
    	cin >> s;
    	solve(s, cnt, c);
    	g[mp[c]].push_back(make_pair(cnt, s));
    }
    vector<pair<string, string> >same, ans;
    for (int i = 1; i <= 5; ++i) sort(g[i].begin(), g[i].end());
    for (int i = 1; i <= 5; ++i) {
    	int len = g[i].size();
    	for (int j = 0; j < len; ++j) {
    		if (j + 1 < len && g[i][j].first == g[i][j+1].first) {
    			same.push_back(make_pair(g[i][j].second, g[i][j+1].second));
    			++j;
    		}else {
    			push(g[i][j]);
    		}
    	}
    }
    int len = same.size();
    int sum = 0;
    for (int i = 0; i <= maxlen && len; ++i) {
    	for (int j = 0; j < (int)all[i].size() / 2 && len; ++j) {
    		int l = j * 2, r = l + 1;
    		ans.push_back(make_pair(all[i][l], same[len-1].first));
    		ans.push_back(make_pair(all[i][r], same[len-1].second));
    		len--;
    		sum++;
    	}
    }
    for (int i = 0; i < len / 2; ++i) {
    	int l = i * 2, r = l + 1;
    	ans.push_back(make_pair(same[l].first, same[r].first));
    	ans.push_back(make_pair(same[l].second, same[r].second));
    	sum++;
    }
    cout << sum << endl;
    if (sum == 0) return 0;
    for (auto it : ans) {
    	cout << it.first << ' ' << it.second << endl;
    }
    return 0;
}