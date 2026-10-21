#include <string>
#include <algorithm>

class Solution {
public:
    int minOperations(std::string s) {
        int n = s.length();
        bool isSorted = true;
        char mn = s[0], mx = s[0];
        
        for (int i = 1; i < n; ++i) {
            mn = std::min(mn, s[i]);
            mx = std::max(mx, s[i]);
            if (s[i] < s[i - 1]) {
                isSorted = false;
            }
        }
        
        if (isSorted) {
            return 0;
        }
        
        if (n == 2) {
            return -1;
        }
        
        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }
        
        for (int i = 1; i < n - 1; ++i) {
            if (s[i] == mn || s[i] == mx) {
                return 2;
            }
        }
        
        return 3;
    }
};
