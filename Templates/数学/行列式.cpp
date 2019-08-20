LL det(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = (A[i][j] % mod + mod) % mod;
        }
    }
    LL tmp = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            while (A[j][i]) {
                // LL t = A[i][i] * inv(A[j][i], mod);
                LL t = A[i][i] / A[j][i];
                for (int k = i; k < n; ++k) {
                    A[i][k] = (A[i][k] - t * A[j][k]) % mod;
                    // swap(A[i][k], A[j][k]);
                }
                swap(A[i], A[j]);
                tmp *= -1;
            }
        }
        if (!A[i][i]) return 0;
        tmp = A[i][i] * tmp % mod;
    }
    return (tmp + mod) % mod;
}