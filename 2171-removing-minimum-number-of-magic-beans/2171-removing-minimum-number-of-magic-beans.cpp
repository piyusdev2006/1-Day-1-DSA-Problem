class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        sort(beans.begin(), beans.end());
        
        vector<long long> prefix(n + 1, 0);
        for(int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + beans[i];
        }
        
        long long minRemoved = 1e18;
        
        for(int i = 0; i < n; i++) {
            long long removedLeft = prefix[i];
            long long removedRight = (prefix[n] - prefix[i+1]) - (long long)beans[i] * (n - 1 - i);
            minRemoved = min(minRemoved, removedLeft + removedRight);
        }
        
        return minRemoved;
    }
};