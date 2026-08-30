class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
       int n = nums.size();
        
        // Min aur Max element ka index nikalna
        int minIdx = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxIdx = max_element(nums.begin(), nums.end()) - nums.begin();
        
        // Pata lagana kaun pehle aata hai aur kaun baad me
        int left = min(minIdx, maxIdx);
        int right = max(minIdx, maxIdx);
        
        // 3 alag-alag tareeqe (Strategies)
        int fromFront = right + 1;
        int fromBack = n - left;
        int fromBoth = (left + 1) + (n - right);
        
        // Sabse chota raasta return karo
        return min({fromFront, fromBack, fromBoth}); 
    }
};