// #include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <queue>
#include <cstring>
#define endl '\n'
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
struct BigInteger{
    int A[25];
    enum{MOD = 10000};
    BigInteger(){memset(A, 0, sizeof(A)); A[0]=1;}
    void set(int x){memset(A, 0, sizeof(A)); A[0]=1; A[1]=x;}
    void print(){
        printf("%d", A[A[0]]);
        for (int i=A[0]-1; i>0; i--){
            if (A[i]==0){printf("0000"); continue;}
            for (int k=10; k*A[i]<MOD; k*=10) printf("0");
            printf("%d", A[i]);
        }
        printf("\n");
    }
    int& operator [] (int p) {return A[p];}
    const int& operator [] (int p) const {return A[p];}
    BigInteger operator + (const BigInteger& B){
        BigInteger C;
        C[0]=max(A[0], B[0]);
        for (int i=1; i<=C[0]; i++)
            C[i]+=A[i]+B[i], C[i+1]+=C[i]/MOD, C[i]%=MOD;
        if (C[C[0]+1] > 0) C[0]++;
        return C;
    }
    BigInteger operator * (const BigInteger& B){
        BigInteger C;
        C[0]=A[0]+B[0];
        for (int i=1; i<=A[0]; i++)
            for (int j=1; j<=B[0]; j++){
                C[i+j-1]+=A[i]*B[j], C[i+j]+=C[i+j-1]/MOD, C[i+j-1]%=MOD;
            }
        if (C[C[0]] == 0) C[0]--;
        return C;
    }
};
struct Trie{
    int nex[maxn][51], fail[maxn], end[maxn];
    int root, p;
    map<char,int> mp;
    inline void newname(char *buf) {
    	int num = 0;
    	for (int i = 0; buf[i]; ++i) mp[buf[i]] = num++;
    }
    inline int newnode() {
        for (int i = 0; i < 51; ++i) {
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
            if (nex[now][mp[buf[i]]] == -1) 
                nex[now][mp[buf[i]]] = newnode();
            now = nex[now][mp[buf[i]]];
        }
        end[now]++;
    } 
    inline void build() {
        queue<int> que;
        fail[root] = root;
        for (int i = 0; i < 51; ++i) {
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
            for (int i = 0; i < 51; ++i) {
                if (nex[now][i] == -1) 
                    nex[now][i] = nex[fail[now]][i];
                else {
                    fail[nex[now][i]] = nex[fail[now]][i];
                    que.push(nex[now][i]);
                }
            }
        }
    }
}ac;
BigInteger dp[51][110];
char s[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m, p;
	ac.init();
	scanf("%d %d %d", &n, &m, &p);
	scanf("%s", s);
	ac.newname(s);
	for (int i = 0; i < p; ++i) {
		scanf("%s", s);
		ac.insert(s);
	}
	ac.build();
	dp[0][0].set(1);
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < ac.p; ++j) {
			for (int k = 0; k < n; ++k) {
				int v = ac.nex[j][k];
				if (ac.end[v]) continue;
				dp[i][v] = dp[i][v] + dp[i-1][j];
			}
		}
	}
	BigInteger ans;
	for (int i = 0; i < ac.p; ++i) ans = ans + dp[m][i];
	ans.print();
	return 0;
}