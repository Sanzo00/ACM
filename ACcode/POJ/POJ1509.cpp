#include <cstring>
#include <iostream>
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;
int minRepresent(char *s, int len) {
    int i = 0, j = 1, k = 0;
    while (i < len && j < len && k < len) {
        int t = s[(i+k) % len] - s[(j+k) % len];
        if (t == 0) k++;
        else {
            if (t < 0)  j = max(j+k+1, i+1);
            else i = max(i+k+1, j+1);
            k = 0;
        }
    }
    return min(i, j);
}
char s[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> s;
		int len = strlen(s);
		cout << minRepresent(s, len) + 1 << endl;
	}
	return 0;
}