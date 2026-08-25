// class Solution {
// public:
//     int numberOfSequence(int n, vector<int>& sick) {
        
//     }
// };

#include <vector>

class Solution {
private:
    long long MOD = 1e9 + 7;

    // Helper: Binary Exponentiation O(log power)
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    // Helper: Modular Inverse via Fermat's Little Theorem
    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    int numberOfSequence(int n, std::vector<int>& sick) {
        // Simulation dynamic_programming
        int m = sick.size();
        
        // Allocate factorial array dynamically up to size n
        std::vector<long long> fact(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        long long total_healthy = 0;
        long long denominator = 1;
        long long internal_ways = 1;

        // 1. Process leftmost uninfected edge segment
        int left_segment = sick[0];
        if (left_segment > 0) {
            total_healthy += left_segment;
            denominator = (denominator * fact[left_segment]) % MOD;
        }

        // 2. Process all inner uninfected middle segments
        for (int i = 0; i < m - 1; i++) {
            int mid_segment = sick[i + 1] - sick[i] - 1;
            if (mid_segment > 0) {
                total_healthy += mid_segment;
                denominator = (denominator * fact[mid_segment]) % MOD;
                internal_ways = (internal_ways * power(2, mid_segment - 1)) % MOD;
            }
        }

        // 3. Process rightmost uninfected edge segment
        int right_segment = n - 1 - sick[m - 1];
        if (right_segment > 0) {
            total_healthy += right_segment;
            denominator = (denominator * fact[right_segment]) % MOD;
        }

        // 4. Calculate multinomial combinations
        long long numerator = fact[total_healthy];
        long long ans = (numerator * modInverse(denominator)) % MOD;
        ans = (ans * internal_ways) % MOD;

        return ans;
    }
};
