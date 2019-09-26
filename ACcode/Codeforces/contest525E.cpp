#include <bits/stdc++.h>
using namespace std;
int n, k;
long long S, ans;
map<long long, int> mp[26];
long long f[20], a[30];
void dfs1(int l, int r, int usek, long long sum) {
    if (usek > k || sum > S) return;
    if (l > r) {
        mp[usek][sum]++;
        return;
    }
    dfs1(l+1, r, usek, sum);
    dfs1(l+1, r, usek, sum+a[l]);
    if (a[l] < 20) dfs1(l+1, r, usek+1, sum+f[a[l]]);
}
void dfs2(int l, int r, int usek, long long sum) {
    if (usek > k || sum > S) return;
    if (l > r) {
        for (int i = 0; i + usek <= k; ++i) {
            if (mp[i].find(S-sum) != mp[i].end()) ans += mp[i][S-sum]; 
        }
        return;
    }
    dfs2(l+1, r, usek, sum);
    dfs2(l+1, r, usek, sum+a[l]);
    if (a[l] < 20) dfs2(l+1, r, usek+1, sum+f[a[l]]);
}

int main() {
    f[0] = 1;
    for (int i = 1; i < 20; ++i) f[i] = f[i-1] * i;
    scanf("%d %d %lld", &n, &k, &S);
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    int mid = (1+n) >> 1;
    ans = 0;
    dfs1(1, mid, 0, 0);
    dfs2(mid+1, n, 0, 0);
    printf("%lld\n", ans);
    return 0;        
}
