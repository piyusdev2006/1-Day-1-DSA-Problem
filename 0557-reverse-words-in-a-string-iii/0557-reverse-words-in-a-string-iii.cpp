class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        int n = s.length();

        for (int end = 0; end <= n; ++end) {
            // Trigger reversal when a space or the end of the string is reached
            if (end == n || s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }
        
        return s;
    }
};
