#include <vector>
#include <queue>
#include <stdio.h>
#include <iostream>
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;
struct Matrix{
    int n;
    unsigned long long mat[151][151];
    Matrix(){}
    Matrix(int _n) {
        n = _n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                mat[i][j] = 0;
            }
        }
    }
    Matrix operator *(const Matrix &b) const{
        Matrix ans = Matrix(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    ans.mat[i][j] += mat[i][k] * b.mat[k][j];
                    // ans.mat[i][j] = (ans.mat[i][j] + mat[i][k] * b.mat[k][j] % mod) % mod;
                }
            }
        }
        return ans;
    }
};
struct Trie{
    int nex[maxn][26], fail[maxn], end[maxn];
    int root, p;
    inline int newnode() {
        for (int i = 0; i < 26; ++i) {
            nex[p][i] = -1;
        }
        end[p++] = 0;
        return p - 1;
    }
    inline void init() {
        p = 0;
        root = newnode();
    }
    inline void insert(char *buf) {
        int now = root;
        for (int i = 0; buf[i]; ++i) {
            if (nex[now][buf[i]-'a'] == -1) 
                nex[now][buf[i]-'a'] = newnode();
            now = nex[now][buf[i]-'a'];
        }
        end[now]++;
    } 
    inline void build() {
        queue<int> que;
        fail[root] = root;
        for (int i = 0; i < 26; ++i) {
            if (nex[root][i] == -1)
                nex[root][i] = root;
            else {
                fail[nex[root][i]] = root;
                que.push(nex[root][i]);
            }
        }
        while (!que.empty()) {
            int now = que.front();
            que.pop();
            if (end[fail[now]]) end[now] = 1; 
            for (int i = 0; i < 26; ++i) {
                if (nex[now][i] == -1) 
                    nex[now][i] = nex[fail[now]][i];
                else {
                    fail[nex[now][i]] = nex[fail[now]][i];
                    que.push(nex[now][i]);
                }
            }
        }
    }
    inline Matrix get() {
    	Matrix tmp = Matrix(p*2);
    	for (int i = 0; i < p; ++i) {
    		for (int j = 0; j < 26; ++j) {
    			if (end[i] || end[nex[i][j]]) continue;
	    		tmp.mat[i][nex[i][j]]++;
    		}
    	}
    	for (int i = 0; i < p; ++i) tmp.mat[i][i+p] = tmp.mat[i+p][i+p] = 1;
    	return tmp;
    }
}ac;
Matrix Pow(Matrix a, int n) {
    Matrix ans = Matrix(a.n);
    Matrix tmp = a;
    for (int i = 0; i < a.n; ++i) {
        ans.mat[i][i] = 1;
    }
    while (n) {
        if (n & 1) ans = ans * tmp;
        tmp = tmp * tmp;
        n >>= 1;
    }
    return ans;
}
char s[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	while (scanf("%d %d\n", &n, &m) != EOF) {
		ac.init();
		for (int i = 0; i < n; ++i) scanf("%s", s), ac.insert(s);
		ac.build();
		Matrix ans = ac.get();
		ans = Pow(ans, m);
		Matrix tmp = Matrix(2);
		tmp.mat[0][0] = 26;
		tmp.mat[0][1] = 1;
		tmp.mat[1][1] = 1;
		tmp = Pow(tmp, m);
		unsigned long long sum = tmp.mat[0][0] + tmp.mat[0][1] - 1;
		for (int j = 0; j < 2*ac.p; ++j) sum -= ans.mat[0][j];
		printf("%llu\n", sum+1);
	}
	return 0;
}