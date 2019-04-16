#include <bits/stdc++.h>
#define LL long long
#define uLL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 1e5 + 9;
struct SAM{

    int trans[maxn<<1][26], slink[maxn<<1], maxlen[maxn<<1];
    LL sum[maxn<<1];
    int last, now, root, len;
    
    inline void newnode (int v) {
        maxlen[++now] = v;
    }
    
    inline void extend(int c) {
        newnode(maxlen[last] + 1);
        int p = last, np = now;
        // 更新trans
        while (p && !trans[p][c]) {
            trans[p][c] = np;
            p = slink[p];
        }
        if (!p) slink[np] = root;
        else {
            int q = trans[p][c];
            if (maxlen[p] + 1 != maxlen[q]) {
                // 将q点拆出nq，使得maxlen[p] + 1 == maxlen[q]
                newnode(maxlen[p] + 1);
                int nq = now;
                memcpy(trans[nq], trans[q], sizeof(trans[q]));
                slink[nq] = slink[q];
                slink[q] = slink[np] = nq;
                while (p && trans[p][c] == q) {
                    trans[p][c] = nq;
                    p = slink[p];
                } 
            }else slink[np] = q;
        }
        last = np;
    }

    inline void build(char *s) {
        len = strlen(s);
        root = last = now = 1;
        for (int i = 0; i < len; ++i) extend(s[i] - 'a'); // extend(s[i] - '1');
    }

    LL Sum() {
    	LL ans = 0;
    	for (int i = root; i <= now; ++i) {
    		ans += maxlen[i] - maxlen[slink[i]];
    	}
    	return ans;
    }
    
}sam;

char s[maxn];

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> s;
    sam.build(s);
    LL ans = sam.Sum();
    cout << ans << endl;

    return 0;
}