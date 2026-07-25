class Solution {
public:
    bool unique(string s) {

        unordered_set<char> st;

        for (char ch : s) {

            if (st.count(ch))
                return false;

            st.insert(ch);
        }

        return true;
    }

    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> freq;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {

            freq[s[right]]++;

            while (freq[s[right]] > 1) {

                freq[s[left]]--;

                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};