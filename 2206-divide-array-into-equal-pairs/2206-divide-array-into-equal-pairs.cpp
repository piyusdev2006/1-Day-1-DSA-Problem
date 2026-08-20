class Solution {
public:
    bool divideArray(vector<int>& nums) {
       unordered_map<int, int> counts;
        
        // Count frequencies
        for (int num : nums) {
            counts[num]++;
        }
        
        // Check if any frequency is odd
        for (auto& [num, count] : counts) {
            if (count % 2 != 0) {
                return false;
            }
        }
        
        return true; 
    }
};