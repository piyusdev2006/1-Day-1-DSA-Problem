class Solution {
bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') count--;
            if (count < 0) return false;
        }
        return count == 0;
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        if (s.empty()) return {""};

        unordered_set<string> visited;
        queue<string> q;
        
        q.push(s);
        visited.insert(s);
        bool found = false;

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            if (isValid(curr)) {
                ans.push_back(curr);
                found = true;
            }

            if (found) continue;

            for (int i = 0; i < curr.length(); i++) {
                if (curr[i] != '(' && curr[i] != ')') continue;

                string nextStr = curr.substr(0, i) + curr.substr(i + 1);
                
                if (visited.find(nextStr) == visited.end()) {
                    q.push(nextStr);
                    visited.insert(nextStr);
                }
            }
        }
        return ans;
    }
};