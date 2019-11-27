#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
using namespace std;
int a[maxn];
int main() {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; ) {
			int pos, tmp = 1e9;
			for (int j = i; j <= n; ++j) {
				if (a[j] < tmp) {
					tmp = a[j];
					pos = j;
				}
			}
			for (int j = pos; j > i; --j) {
				swap(a[j], a[j-1]);
			}
			if (pos == i) ++i;
			else i = pos;
		}
		for (int i = 1; i <= n; ++i) {
			cout << a[i] << " ";
		}
		cout << endl;
 
	}	
    return 0;
}
