#include <bits/stdc++.h>
const int maxn = 5e5 + 5;
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
}ek1, ek2;
char s[maxn], t[maxn];
int pre[maxn], val[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	scanf("%d", &T);
	while (T--) {
		for (int i = 0; i < 26; ++i) scanf("%d", &val[i]);
		scanf("%s", s);
		int lens = strlen(s);
		for (int i = 0; i <= lens; ++i) t[i] = s[i];
		reverse(t, t + lens);
		pre[0] = val[s[0]-'a'];
		for (int i = 1; i < lens; ++i) {
			pre[i] = pre[i-1] + val[s[i]-'a'];
		}
		ek1.getEx(s, t);
		ek2.getEx(t, s);
		int ans = 0;
		for (int i = 1; i < lens; ++i) {
			int t1 = 0, t2 = 0;
			if (ek1.ex[i] + i == lens) t2 = pre[lens-1] - pre[i-1];
			if (ek2.ex[lens-i] + lens-i == lens) t1 = pre[ek2.ex[lens-i]-1];
			ans = max(ans, t1+t2); 
		}
		printf("%d\n", ans);
	}
	return 0;
}