class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        // Step 1: Create pairs of {element, original_index}
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }
        
        // Step 2: Sort based on element values
        sort(v.begin(), v.end());
        
        vector<int> result(n);
        
        // Step 3 & 4: Grouping and placing back
        int i = 0;
        while(i < n) {
            int j = i + 1;
            
            // Chain dhoondo jahan tak diff <= limit hai
            while(j < n && v[j].first - v[j-1].first <= limit) {
                j++;
            }
            
            // Ab i se lekar j-1 tak ke elements ek hi group ke hain
            vector<int> indices;
            for(int k = i; k < j; k++) {
                indices.push_back(v[k].second); // original indices collect karein
            }
            
            // Indices ko sort karo taaki left-to-right correct positions mil sakein
            sort(indices.begin(), indices.end());
            
            // Group ke elements ko sorted indices par place karo
            for(int k = i; k < j; k++) {
                result[indices[k - i]] = v[k].first;
            }
            
            // Agle group par jao
            i = j;
        }
        
        return result;
    }
};
