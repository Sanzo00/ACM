struct Matrix{
    int n;
    long long mat[151][151];
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
                    ans.mat[i][j] %= mod;
                    // ans.mat[i][j] = (ans.mat[i][j] + mat[i][k] * b.mat[k][j] % mod) % mod;
                }
            }
        }
        return ans;
    }
};
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