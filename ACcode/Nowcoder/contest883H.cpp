#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);		
		vector<pair<int,int>> point(n);
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &point[i].first, &point[i].second);
		}
		sort(point.begin(), point.end());
		int x = point[n/2-1].first;
		int y = point[n/2-1].second;
		printf("%d %d %d %d\n", x-1, y+maxn, x+1, y-maxn+1);
	}
	return 0;
}