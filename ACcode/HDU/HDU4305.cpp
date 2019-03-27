#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
const int maxn = 305;
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;

int mod = 10007, flag;
LL A[maxn][maxn], B[maxn][maxn];

LL exgcd(LL a, LL b, LL &x, LL &y) {
    LL d = a;
    if (b == 0) x = 1,y = 0;
    else {
        d = exgcd(b, a%b, y, x);
        y -= a / b * x;
    }
    return d;
}
LL inv(LL a, LL mod) {
    LL x, y;
    LL d = exgcd(a, mod, x, y);
    return (d == 1) ? ((x + mod) % mod) : -1; 
}

LL det(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            A[i][j] = (A[i][j] % mod + mod) % mod;
        }
    }
    LL tmp = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            while (A[j][i]) {
                LL t = A[i][i] * inv(A[j][i], mod);
                for (int k = i; k <= n; ++k) {
                    A[i][k] = (A[i][k] - t * A[j][k]) % mod;
                    swap(A[i][k], A[j][k]);
                }
                tmp *= -1;
            }
        }
        if (!A[i][i]) {
            flag = 1;
            return 0;
        }
        tmp = A[i][i] * tmp % mod;
    }
    return (tmp + mod) % mod;
}

struct ac{
    int x, y;
    ac(int _x = 0, int _y = 0) {
        x = _x;
        y = _y;
    }
    int dis(ac t) {
        return ((t.x-x)*(t.x-x) + (t.y-y)*(t.y-y));
    }
    friend ac operator - (const ac a, const ac b) {
        return ac(a.x-b.x, a.y-b.y);
    }
    friend double operator ^ (const ac a, const ac b) {
        return a.x * b.y - a.y * b.x;
    }

}a[maxn];

int judge (ac t1, ac t2, ac t) {
    ac p = t - t1;
    ac q = t2 - t1;
    if (p ^ q) return 0;
    if (t.x < min(t1.x, t2.x) || t.x > max(t1.x, t2.x)) return 0;
    if (t.y < min(t1.y, t2.y) || t.y > max(t1.y, t2.y)) return 0;
    return 1;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);   
    int T;
    cin >> T;
    while (T--) {
        mem(A, 0);
        mem(B, 0);
        int N, R;
        cin >> N >> R;
        flag = 0;
        for (int i = 1; i <= N; ++i) {
            cin >> a[i].x >> a[i].y;
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = i+1; j <= N; ++j) {
                if (a[i].dis(a[j]) > R*R) continue;
                int tmp = 0;
                for (int k = 1; k <= N && !tmp; ++k) {
                    if (k == i || k == j) continue;
                    if (judge(a[i], a[j], a[k])) tmp = 1;
                }
                if (tmp == 1) continue;
                B[i][j] = B[j][i] = 1;
            }
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (i == j || !B[i][j]) continue;
                A[i][i]++;
                A[i][j] = -1;
            }
        }
        LL ans = det(N-1);
        if (flag) ans = -1;
        cout << ans << endl;
    }


    return 0;
}