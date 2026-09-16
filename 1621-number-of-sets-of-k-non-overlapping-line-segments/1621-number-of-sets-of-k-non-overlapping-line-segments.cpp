class Solution {
public:
    int numberOfSets(int n, int k) {
        long long MOD = 1000000007;
        int total_points = n + k - 1;
        int choose = 2 * k;

        if (choose > total_points) return 0;

        // DP table for combinations C(N, K) mod 10^9 + 7
        // Using a fixed-size vector alternative without including <vector>
        long long C[2005] = {0};
        C[0] = 1;

        for (int i = 1; i <= total_points; ++i) {
            for (int j = (i < choose ? i : choose); j > 0; --j) {
                C[j] = (C[j] + C[j - 1]) % MOD;
            }
        }

        return C[choose];
    }
};