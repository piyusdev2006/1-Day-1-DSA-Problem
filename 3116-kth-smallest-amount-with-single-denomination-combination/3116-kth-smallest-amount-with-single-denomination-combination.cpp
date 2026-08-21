class Solution {
public:
    // Helper function to calculate GCD
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    // Helper function to calculate LCM
    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    // Function to count valid amounts <= X using Bitmask + Inclusion-Exclusion
    long long countValid(long long X, vector<int>& coins) {
        long long total_count = 0;
        int n = coins.size();
        
        // 1 se lekar (2^n - 1) tak loop chalayenge saare subsets ke liye
        for (int mask = 1; mask < (1 << n); mask++) {
            long long current_lcm = 1;
            int set_bits = 0;
            bool overflow = false;
            
            for (int i = 0; i < n; i++) {
                if ((mask >> i) & 1) { // Agar i-th coin subset me shamil hai
                    set_bits++;
                    current_lcm = lcm(current_lcm, coins[i]);
                    // Agar LCM X se bada ho gaya toh aage calculate karne ka fayda nahi
                    if (current_lcm > X) {
                        overflow = true;
                        break;
                    }
                }
            }
            
            if (overflow) continue;
            
            long long multiples = X / current_lcm;
            
            // Inclusion-Exclusion Rule
            if (set_bits % 2 != 0) {
                total_count += multiples; // Odd coins -> Add
            } else {
                total_count -= multiples; // Even coins -> Subtract
            }
        }
        return total_count;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        // Binary Search ki range set karo
        long long low = 1;
        long long min_coin = *min_element(coins.begin(), coins.end());
        long long high = min_coin * k; 
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (countValid(mid, coins) >= k) {
                ans = mid;         // Yeh potential answer ho sakta hai
                high = mid - 1;    // Aur chota answer try karo
            } else {
                low = mid + 1;     // Valid numbers kam hain, range badao
            }
        }
        return ans;
    }
};
