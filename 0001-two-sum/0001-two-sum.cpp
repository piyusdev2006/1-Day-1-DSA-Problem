class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            int a = nums[i];
            int oneMoreNeeded = target - a;
            if(mp.find(oneMoreNeeded) != mp.end()){
                return {mp[oneMoreNeeded] , i};
            }
            mp[a] = i;
        }
        return {-1, -1};
        
    }
};