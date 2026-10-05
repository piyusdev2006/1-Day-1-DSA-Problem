class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int> st;
        st.push_back(0);
        
        for (char c : s) {
            if (c == '(') {
                st.push_back(0);
            } else {
                int top_val = st.back();
                st.pop_back();
                
                int score = max(2 * top_val, 1);
                st.back() += score;
            }
        }
        
        return st.back();
    }
};