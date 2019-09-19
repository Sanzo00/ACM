#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;
long long f[26]={34183,13513,152993,13591,19687,350869,111187,766091,769297,633469,752273,298651,617191,880421,136067,1408397,726899,458921,2133701,2599847,2730947,4696343,10267237,18941059,34078909,69208409};
unordered_map<long long, int>mp[26][26];
char s[maxn], t[maxn];
int lens, len[maxn], idx[maxn];
long long sum[maxn], Hash[maxn];
string bf[maxn];
long long get(char *buf, int n) {
    long long ans = 0;
    for (int i = 2; i <= n-1; ++i) ans += f[buf[i] - 'a'];
    return ans;
}
void solve(int n) {
    for (int i = 1; i <= lens-n+1; ++i) {
        long long tmp = sum[i+n-2] - sum[i];
        if (mp[s[i]-'a'][s[i+n-1]-'a'].count(tmp)) mp[s[i]-'a'][s[i+n-1]-'a'][tmp]++; 
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T, q;
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j)
                mp[i][j].clear();
        scanf("%s", s+1);
        lens = strlen(s+1);
        for (int i = 1; i <= lens; ++i) sum[i] = sum[i-1] + f[s[i] - 'a'];
        scanf("%d", &q);
        for (int i = 0; i < q; ++i) {
            scanf("%s", t+1);
            len[i] = strlen(t+1);
            Hash[i] = get(t, len[i]);
            mp[t[1]-'a'][t[len[i]]-'a'][Hash[i]] = 0;
            bf[i] = string(1, t[1]) + string(1, t[len[i]]);
        }
        for (int i = 0; i < q; ++i) idx[i] = i;
        sort(idx, idx+q, [&](int x, int y) {
            return len[x] < len[y];
        });
        int pre = 0;
        for (int i = 0; i < q; ++i) {
            if (pre == len[idx[i]]) continue;
            solve(pre = len[idx[i]]);
        }
        for (int i = 0; i < q; ++i) {
            printf("%d\n", mp[bf[i][0]-'a'][bf[i][1]-'a'][Hash[i]]);
        }
    }

    return 0;
}