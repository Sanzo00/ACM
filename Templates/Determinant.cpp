LL det(int n) {
    LL tmp = 1;
    for (int i = 1; i <= n; ++i) {
        if (!A[i][i]) {
            int flag = 1;
            for (int j = i + 1; j <= n; ++j) {
                if (!A[j][i]) continue;
                flag = 0;
                for (int k = i; k <= n; ++k) {
                    swap(A[i][k], A[j][k]);
                }
                tmp *= -1;
                break;
            }
            if (flag) return 0;
        }

        for (int j = i + 1; j <= n; ++j) {
            while (A[j][i]) {
                LL t = A[i][i] / A[j][i];
                for (int k = i; k <= n; ++k) {
                    A[i][k] -= t * A[j][k];
                    swap(A[i][k], A[j][k]);
                }
                tmp *= -1;
            }
        }
        tmp *= A[i][i];
    }
    return tmp;
}
