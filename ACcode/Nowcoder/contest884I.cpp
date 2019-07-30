#include <bits/stdc++.h>
const int maxn = 4e5 + 5;
using namespace std;
struct SAM{

    int trans[maxn<<1][27], slink[maxn<<1], maxlen[maxn<<1];
    int indegree[maxn<<1], endpos[maxn<<1], rank[maxn<<1];
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
        // 初始状态为可接受状态
        endpos[np] = 1;
    }

    inline void build(char *s) {
        root = last = now = 1;
        for (int i = 0; s[i]; ++i) extend(s[i] - 'a'); // extend(s[i] - '1');
    }

    inline long long getNum() {
    	// 拓扑排序 
        for (int i = 1; i <= now; ++i) indegree[ maxlen[i] ]++;
        for (int i = 1; i <= now; ++i) indegree[i] += indegree[i-1];
        for (int i = 1; i <= now; ++i) rank[ indegree[ maxlen[i] ]-- ] = i;
        memset(endpos, 0, sizeof(endpos));
        endpos[1] = 1; // 从根节点向后求有效的入度
        for (int i = 1; i <= now; ++i) {
            int x = rank[i];
            for (int j = 0; j < 26; ++j) {
                int nex = trans[x][j];
                if (!nex) continue;
                endpos[nex] += endpos[x]; // 有效入度
            }
        }
        long long ans = 0;
        for (int i = 2; i <= now; ++i) ans += endpos[i];
        return ans;
    }
}sam;
struct Palindrome_Tree{
    int nex[maxn][26];
    int fail[maxn], cnt[maxn], num[maxn]; // num 记录每个节点右端点的表示回文串的个数
    int len[maxn], S[maxn];					// cnt 记录每个节点表示的回文串出现的次数
    int last, n, p;
    int newnode(int l) { // 新建节点
        for (int i = 0; i < 26; ++i) nex[p][i] = 0;
        cnt[p] = num[p] = 0;
        len[p] = l;
        return p++;
    }
    void init() { // 初始化
        p = 0;
        newnode(0), newnode(-1); // 新建奇根和偶根
        last = n = 0;
        S[n] = -1; 
        fail[0] = 1; // 偶根指向
    }
    int get_fail(int x) { // 求fail
        while (S[n - len[x] - 1] != S[n]) x = fail[x];
        return x;
    }
    void add(int c) { // 添加节点
        c -= 'a';
        S[++n] = c;
        int cur = get_fail(last);
        if (!nex[cur][c]) {
            int now = newnode(len[cur] + 2);
            fail[now] = nex[get_fail(fail[cur])][c];
            nex[cur][c] = now;
            num[now] = num[fail[now]] + 1;
        }
        last = nex[cur][c];
        cnt[last]++;
    }
    void count() { // 求cnt
        for (int i = p - 1; i >= 0; --i) cnt[fail[i]] += cnt[i];
    }
}Tree;
char s[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	scanf("%s", s);
	Tree.init();
	int len = strlen(s);
	s[len] = 26 + 'a';
	for (int i = 0; i < len; ++i) {
		Tree.add(s[i]);
		s[i+len+1] = s[len-i-1];
	}
	s[len+len+1] = 0;
	// cout << s << endl;
	sam.build(s);
	// cout << sam.getNum() << endl;
	long long ans = (sam.getNum() + Tree.p - 2) / 2;
	printf("%lld\n", ans);
	return 0;
}