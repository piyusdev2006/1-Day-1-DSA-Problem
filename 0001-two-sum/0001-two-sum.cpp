class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {

            int current = nums[i];
            int need = target - current;

            if (mp.find(need) != mp.end()) {
                return {mp[need], i};
            }

            mp[current] = i;
        }

        return {-1, -1};
        
    }
};