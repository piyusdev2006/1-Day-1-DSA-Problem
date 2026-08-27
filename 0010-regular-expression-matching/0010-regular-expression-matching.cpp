class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        
        // Step 1: Initialize DP table with False
        // Size is (n+1) x (m+1) to handle empty string/pattern states
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        
        // Step 2: Base Case handling
        dp[0][0] = true; // Empty string & empty pattern
        
        // If string is empty (i = 0), matching depends on '*' erasing previous characters
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        
        // Step 3: Nested loops to compute subproblems
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                
                // Case 1: Pattern character is a wildcard '*'
                if (p[j - 1] == '*') {
                    // Choice 1: Ignore the '*' and its preceding element (0 occurrences)
                    bool zero_occurrences = dp[i][j - 2];
                    
                    // Choice 2: Match current character and stay at the same pattern state
                    bool char_matches = (p[j - 2] == s[i - 1] || p[j - 2] == '.');
                    bool multiple_occurrences = char_matches && dp[i - 1][j];
                    
                    dp[i][j] = zero_occurrences || multiple_occurrences;
                } 
                // Case 2: Pattern character is a standard letter or '.'
                else {
                    bool char_matches = (p[j - 1] == s[i - 1] || p[j - 1] == '.');
                    if (char_matches) {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = false;
                    }
                }
            }
        }
        
        // Step 4: The answer for full lengths is sitting at the bottom-right corner
        return dp[n][m];
    }
};
