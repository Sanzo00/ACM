#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 3e2 + 7;

struct ac{
	string s;
	int A, B;
}a[maxn];
int n, m, flag;
vector<char> num;
int judge(int x) {
	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		// judge A
		for (int j = 0; j <= x; ++j) {
			if (a[i].s[j] == num[j]) cnt++;
			if (cnt > a[i].A) return 0;
		}
		if (x == m-1 && cnt != a[i].A) return 0;
		// judge B
		cnt = 0;
		for (int j = 0; j <= x; ++j) {
			for (int k = 0; k < m; ++k) {
				if (j == k) continue;
				if (a[i].s[k] == num[j]) cnt++;
				if (cnt > a[i].B) return 0;
			}
		}
		if (x == m-1 && cnt != a[i].B) return 0;
	}
	return 1;
}

void dfs(int x) {
	if (x == m) {
		flag = 1;
		return;
	}
	for (int i = 0; i <= 9; ++i) {
		num.push_back(i+'0');
		if (judge(x)) {
			dfs(x+1);
		}
		if (flag) return;
		num.pop_back();
	}
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
 	for (int i = 0; i < n; ++i) {
 		cin >> a[i].s >> a[i].A >> a[i].B;
 	}
 	dfs(0);
    for (int i = 0; i < m; ++i) {
    	cout << num[i];
    }
    cout << endl;
    return 0;
}