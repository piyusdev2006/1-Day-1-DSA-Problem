class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        //    int n = nums.size();

        //     // Min aur Max element ka index nikalna
        //     int minIdx = min_element(nums.begin(), nums.end()) -
        //     nums.begin(); int maxIdx = max_element(nums.begin(), nums.end())
        //     - nums.begin();

        //     // Pata lagana kaun pehle aata hai aur kaun baad me
        //     int left = min(minIdx, maxIdx);
        //     int right = max(minIdx, maxIdx);

        //     // 3 alag-alag tareeqe (Strategies)
        //     int fromFront = right + 1;
        //     int fromBack = n - left;
        //     int fromBoth = (left + 1) + (n - right);

        //     // Sabse chota raasta return karo
        //     return min({fromFront, fromBack, fromBoth});

        int n = nums.size();
        if (n <= 2)
            return n;

        // 1. Find min and max iterators in a single pass
        auto [min_it, max_it] = minmax_element(nums.begin(), nums.end());

        // 2. Convert iterators to 0-based indices
        int idx1 = distance(nums.begin(), min_it);
        int idx2 = distance(nums.begin(), max_it);

        // 3. Make sure idx1 is always the smaller index to simplify math
        int left_idx = min(idx1, idx2);
        int right_idx = max(idx1, idx2);

        // 4. Calculate the deletions for all 3 scenarios
        int opt1 = right_idx + 1;
        int opt2 = n - left_idx;
        int opt3 = (left_idx + 1) + (n - right_idx);

        // Return the minimum steps required among all options
        return min({opt1, opt2, opt3});
    }
};