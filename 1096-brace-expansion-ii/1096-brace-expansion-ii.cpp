class Solution {
    set<string> dfs(string exp) {
        set<string> res;
        int level = 0;
        
        for (int i = 0; i < exp.length(); i++) {
            if (exp[i] == '{') level++;
            else if (exp[i] == '}') level--;
            else if (exp[i] == ',' && level == 0) {
                set<string> left = dfs(exp.substr(0, i));
                set<string> right = dfs(exp.substr(i + 1));
                res.insert(left.begin(), left.end());
                res.insert(right.begin(), right.end());
                return res;
            }
        }

        if (exp.empty()) return {""};
        
        if (exp[0] == '{' && exp.back() == '}') {
            int l = 0;
            bool isOuter = true;
            for (int i = 0; i < exp.length() - 1; i++) {
                if (exp[i] == '{') l++;
                else if (exp[i] == '}') l--;
                if (l == 0) { isOuter = false; break; }
            }
            if (isOuter) return dfs(exp.substr(1, exp.length() - 2));
        }

        int firstBrace = -1;
        level = 0;
        for (int i = 0; i < exp.length(); i++) {
            if (exp[i] == '{') {
                if (level == 0) firstBrace = i;
                level++;
            } else if (exp[i] == '}') {
                level--;
                if (level == 0) {
                    set<string> left = dfs(exp.substr(0, firstBrace));
                    set<string> mid = dfs(exp.substr(firstBrace + 1, i - firstBrace - 1));
                    set<string> right = dfs(exp.substr(i + 1));
                    
                    for (auto& l : left) {
                        for (auto& m : mid) {
                            for (auto& r : right) {
                                res.insert(l + m + r);
                            }
                        }
                    }
                    return res;
                }
            }
        }
        return {exp};
    }
public:
    vector<string> braceExpansionII(string expression) {
        set<string> resSet = dfs(expression);
        return vector<string>(resSet.begin(), resSet.end());
    }
};