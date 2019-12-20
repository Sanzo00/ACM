#include <bits/stdc++.h>
using namespace std;
 
int cnt[300];
int main() {
	int q;
	cin >> q;
	while (q--) {
		string s;
		cin >> s;
		cnt['U'] = cnt['D'] = cnt['L'] = cnt['R'] = 0;
		for (int i = 0; i < s.size(); ++i) {
			cnt[s[i]]++;
		}		
		int w = min(cnt['L'], cnt['R']);
		int h = min(cnt['U'], cnt['D']);
		if (w && h) {
			cout << 2* (w + h) << endl;
			for (int i = 0; i < h && w; ++i) {
				cout << 'U';
			}
			for (int i = 0; i < w && h; ++i) {
				cout << 'R';
			}
			for (int i = 0; i < h && w; ++i) {
				cout << 'D';
			}
			for (int i = 0; i < w && h; ++i) {
				cout << 'L';
			}
		}else if(!w && !h) {
			cout << 0 << endl;
		}else if (!w) {
			cout << 2 << endl << "DU";
		}else {
			cout << 2 << endl << "LR";
		}
		
			
		cout << endl;
	}
	
	return 0;
}