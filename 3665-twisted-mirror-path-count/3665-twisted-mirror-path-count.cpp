

class Solution {
private:
    static inline const int mat[2][2][2] = {
        {{1, 1}, {1, 1}}, 
        {{0, 1}, {1, 0}}
    };
    static const int MOD = 1000000007;

public:
    int uniquePaths(std::vector<std::vector<int>>& A) {
        int n = A[0].size();
        long long left = 0;
        
        // DP array to store top states
        std::vector<long long> dp(n, 0);
        dp[0] = 1;

        for (const auto& row : A) {
            left = 0;
            for (int j = 0; j < n; j++) {
                long long top = dp[j];
                int c = row[j];
                
                dp[j] = (left * mat[c][1][0] + top * mat[c][1][1]) % MOD;
                left = (left * mat[c][0][0] + top * mat[c][0][1]) % MOD;
            }
        }

        return left;
    }
};
