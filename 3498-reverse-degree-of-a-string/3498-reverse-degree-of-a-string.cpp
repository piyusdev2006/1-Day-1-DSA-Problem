class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            int rev_pos = 'z' - s[i] + 1;
            
            ans += (i + 1) * rev_pos;
        }
        
        return ans;
    }
};