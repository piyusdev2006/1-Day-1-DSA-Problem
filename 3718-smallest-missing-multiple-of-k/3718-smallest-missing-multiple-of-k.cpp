class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
       unordered_set<int> st(nums.begin(), nums.end());
        
        // Start checking multiples from 1 * k
        int mul = k;
        
        while (st.count(mul)) {
            mul += k; // Move to the next multiple: 2k, 3k, 4k...
        }
        
        // Return the first multiple not present in the set
        return mul; 
    }
};