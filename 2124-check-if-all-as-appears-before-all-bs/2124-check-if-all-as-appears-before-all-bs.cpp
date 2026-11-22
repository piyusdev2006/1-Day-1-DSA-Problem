class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == 'b' && s[j] == 'a') {
                    return false;
                }
            }
        }
        return true;
    }
};
