class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int minLen = n + 1;
        string res = "";
        int l = 0, ones = 0;

        for (int r = 0; r < n; r++) {
            if (s[r] == '1') {
                ones++;
            }

            while (ones == k) {
                int currentLen = r - l + 1;
                string sub = s.substr(l, currentLen);

                if (currentLen < minLen) {
                    minLen = currentLen;
                    res = sub;
                } else if (currentLen == minLen) {
                    if (sub < res) {
                        res = sub;
                    }
                }

                if (s[l] == '1') {
                    ones--;
                }
                l++;
            }
        }
        return res;
    }
};
