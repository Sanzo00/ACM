#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
using namespace std;

int l[26], r[26], cnt[maxn][26], used[26];
char ans[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    string s;
    int k;
    while (cin >> s >> k) {
        for (int i = 0; i < 26; ++i) {
            cin >> l[i] >> r[i];
        }
        int len = s.size();
        // 记录当前位置之后的所有字符的数量
        memset(cnt[len], 0, sizeof(cnt[len]));
        for (int i = len-1; i >= 0; --i) {
            for (int j = 0; j < 26; ++j) cnt[i][j] = cnt[i+1][j];
            cnt[i][s[i]-'a']++;
        }
        vector<int> g[26];
        // 统计每个字符的位置
        for (int i = 0; i < len; ++i) {
            g[s[i]-'a'].push_back(i);
        }
        vector<int>::iterator head[26];
        for (int i = 0; i < 26; ++i) head[i] = g[i].begin();
        int last = -1, now = 0;
        memset(used, 0, sizeof(used));
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (used[j] == r[j]) continue;
                while (head[j] != g[j].end() && *head[j] <= last) ++head[j];
                if (head[j] == g[j].end()) continue;
                used[j]++;
                int pos = *head[j];
                int sum = 0, flag = 1;
                for (int k = 0; k < 26; ++k) {
                    if (cnt[pos+1][k] < l[k] - used[k]) flag = 0;
                    sum += max(l[k] - used[k], 0);
                }
                if (sum > k - i - 1) flag = 0;

                sum = 0;
                for (int k = 0; k < 26; ++k) {
                    sum += min(cnt[pos+1][k], r[k] - used[k]);
                }
                if (sum < k - i - 1) flag = 0;
                if (flag == 0) {
                    used[j]--;
                }else {
                    ans[now++] = j + 'a';
                    last = pos;
                    break;
                }
            }
        }
        ans[now] = 0;
        if (now != k) cout << -1 << endl;
        else cout << ans << endl; 
    }
    return 0;
}
