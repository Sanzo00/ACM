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
