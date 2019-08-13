#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
using namespace std;
struct exKmp{
    // 字符串下标从0开始
    int nex[maxn], ex[maxn]; //模式串nex，匹配串ex
    void getNex(char *str, int len) {
        int i = 0, j, pos;
        nex[0] = len;
        while (str[i] == str[i+1] && i+1 < len) ++i;
        nex[1] = i;
        pos = 1;
        for (int i = 2; i < len; ++i) {
            if (nex[i-pos] + i < nex[pos] + pos) nex[i] = nex[i-pos];
            else {
                j = nex[pos] + pos - i;
                if (j < 0) j = 0;
                while (i+j < len && str[j] == str[j+i]) ++j;
                nex[i] = j;
                pos = i;
            }
        }
    }
    void getEx(char *s1, char *s2) { // s1匹配s2
        int i = 0, j, pos;
        int len1 = strlen(s1);
        int len2 = strlen(s2);
        getNex(s2, len2);
        while (s1[i] == s2[i] && i < len1 && i < len2) ++i;
        ex[0] = i;
        pos = 0;
        for (int i = 1; i < len1; ++i) {
            if (nex[i-pos] + i < ex[pos] + pos) ex[i] = nex[i-pos];
            else {
                j = ex[pos] + pos - i;
                if (j < 0) j = 0;
                while (i+j < len1 && j < len2 && s1[i+j] == s2[j]) ++j;
                ex[i] = j;
                pos = i;
            }
        }
    }
}exkmp;
char s[maxn], t[maxn], trans[28], ming[300];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s%s", trans, s);
		int lens = strlen(s);
		for (int i = 0; i < 26; ++i) {
			ming[trans[i]] = i + 'a';
		}
		for (int i = 0; i < lens; ++i) {
			t[i] = ming[s[i]];
		}
		t[lens] = 0;
		exkmp.getEx(s, t);
		int pos = lens;
		for (int i = 0; i < lens; ++i) {
			if (exkmp.ex[i] + i >= lens && i >= exkmp.ex[i]) {
				pos = i;
				break;
			}
		}
		for (int i = 0; i < pos; ++i) {
			t[i] = s[i];
			t[i+pos] = ming[s[i]];
		}
		t[pos+pos] = 0;
		printf("%s\n", t);
	}
	return 0;
}