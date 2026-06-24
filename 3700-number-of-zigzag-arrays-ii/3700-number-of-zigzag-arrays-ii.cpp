class Solution {
public:
    int MOD = 1e9 + 7;
    typedef vector<vector<long long>> Matrix;

    Matrix multiply(const Matrix& A, const Matrix& B, int size) {
        Matrix C(size, vector<long long>(size, 0));
        for(int i = 0; i < size; i++) {
            for(int k = 0; k < size; k++) {
                if(A[i][k] == 0) continue;
                for(int j = 0; j < size; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    Matrix power(Matrix A, long long p, int size) {
        Matrix res(size, vector<long long>(size, 0));
        for(int i = 0; i < size; i++) res[i][i] = 1;
        
        while(p > 0) {
            if(p & 1) res = multiply(res, A, size);
            A = multiply(A, A, size);
            p >>= 1;
        }
        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        if (n == 1) return m;

        int size = 2 * m;
        Matrix T(size, vector<long long>(size, 0));

        for (int y = 0; y < m; y++) {
            for (int v = 0; v < y; v++) {
                T[y][m + v] = 1; 
            }
        }

        for (int y = 0; y < m; y++) {
            for (int v = y + 1; v < m; v++) {
                T[m + y][v] = 1;
            }
        }

        Matrix Tn = power(T, n - 2, size);

        vector<long long> S2(size, 0);
        for(int y = 0; y < m; y++) {
            S2[y] = y;
            S2[m + y] = m - 1 - y;
        }

        long long ans = 0;
        for (int i = 0; i < size; i++) {
            long long val = 0;
            for (int j = 0; j < size; j++) {
                val = (val + Tn[i][j] * S2[j]) % MOD;
            }
            ans = (ans + val) % MOD;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna