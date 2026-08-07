class Solution {
public:
    void solve(int n , int open, int close, string s, vector<string>&answer){
        // Base case
        if (s.length() == 2 * n) {
            answer.push_back(s);
            return;
        }

        if(open < n){
             solve(n, open+1, close, s + '(', answer);
        }

        if(close < open){
            solve(n, open, close+1, s + ')', answer);

        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        solve(n, 0, 0 , "", answer);
        return answer;
    }
};

