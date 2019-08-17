#include <bits/stdc++.h>
#define endl '\n'
const int maxn = 2e6 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
char s[10], t[maxn], ss[10];
int L[maxn], R[maxn];
int a[maxn];
struct Hash{
    // mod 402653189，805306457，1610612741，1e9+7
    // base 131, 233
    long long p[maxn], hash[maxn], base = 131;
    long long getHash(int l, int r) {
        long long ans = (hash[r] - hash[l-1] * p[r-l+1]) % mod;
        return (ans + mod) % mod;
    }
    void init(char* buf) {
        int n = strlen(buf);
        p[0] = 1;
        for (int i = 1; i <= n; ++i) p[i] = p[i - 1] * base % mod;
        for (int i = 1; i <= n; ++i) {
            hash[i] = (hash[i - 1] * base % mod + (buf[i-1] - 'a' + 1)) % mod;
        }
    }
}hh;
int check(int q, int x) {
	return (hh.getHash(L[q], R[q]-x) == hh.getHash(L[q]+x, R[q]));
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	map<char,char> mp;
	int n, head = 1e6+1, tail = 1e6+2;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%s%s", ss, s);
		char c = s[0];
		if (c == 's' && s[1] == 'i') c = 'z'; 
		if (ss[0] == 'a') t[tail++] = c;
		else t[head--] = c;
		L[i] = head+1, R[i] = tail-1;
	}
	for (int i = 1; i <= n; ++i) L[i] -= head, R[i] -= head;
	t[tail] = 0;
	hh.init(t+head+1);
	for (int i = 1; i <= n; ++i) {
		int l = i, r = n;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid, i)) l = mid + 1;
			else r = mid - 1;
		}
		a[i]++, a[r+1]--;
	}
	for (int i = 1; i <= n; ++i) {
		a[i] += a[i-1];
		printf("%d\n", a[i]);
	}
	return 0;
}