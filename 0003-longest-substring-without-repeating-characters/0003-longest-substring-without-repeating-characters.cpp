class Solution {
public:
    bool unique(string s) {

        unordered_set<char> st;

        for(char ch : s) {

            if(st.count(ch))
                return false;

            st.insert(ch);
        }

        return true;
    }

    int lengthOfLongestSubstring(string s) {
        int ans = 0;

        for(int i = 0; i < s.size(); i++) {

            unordered_set<char> st;

            for(int j = i; j < s.size(); j++) {

                if(st.count(s[j]))
                    break;

                st.insert(s[j]);

                ans = max(ans, j-i+1);
            }
        }

        return ans;
    }
};