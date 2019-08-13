#include <iostream>
#include <stdio.h>
#include <set>
#include <cstring>
const int maxn = 2e5 + 5;
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
}ek;
char s[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T, kase = 0;
	scanf("%d", &T);	
	while (T--) {
		scanf("%s", s);
		int len = strlen(s);
		for (int i = 0; i < len; ++i) {
			s[i+len] = s[i];
		}
		len += len;
		s[len] = 0;
		ek.getNex(s, len);
		int L = 0, E = 0, G = 0;
		int tmp = len/2;
		for (int i = 1; i < len/2; ++i) {
			if (ek.nex[i] + i >= len && len % (len - ek.nex[i]) == 0) {
				tmp = len - ek.nex[i];
				break;
			}
		}
		for (int i = 0; i < tmp; ++i) {
			if (ek.nex[i] >= len/2) E++;
			else if (s[i+ek.nex[i]] > s[ek.nex[i]]) G++;
			else L++; 
		}
		printf("Case %d: %d %d %d\n", ++kase, L, E, G);
	}
	return 0;
}