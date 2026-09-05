class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0)
            return -1;

       // Right Side ke minimums ko pehle se store karne ke liye array
        vector<int> suffixMin(n);

        // Aakhri element ka right min woh khud hi hoga
        suffixMin[n - 1] = nums[n - 1];

        // Piche se loop chalao aur suffix minimum fill karo
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }

        // Aage se traverse karo aur raste mein Prefix Max track karo
        int prefixMax = INT_MIN;
        for (int i = 0; i < n; i++) {
            prefixMax = max(prefixMax, nums[i]); // Current tak ka max mil gaya

            // Formula lagao aur check karo
            if (prefixMax - suffixMin[i] <= k) {
                return i; // Pehla stable index milte hi return kar do
            }
        }

        return -1;
    }
};