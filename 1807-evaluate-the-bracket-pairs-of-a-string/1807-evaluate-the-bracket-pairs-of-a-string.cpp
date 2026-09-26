class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> map;
        for (auto& k : knowledge) {
            map[k[0]] = k[1];
        }
        
        string ans = "";
        int n = s.length();
        for (int i = 0; i < n; ) {
            if (s[i] == '(') {
                int j = i + 1;
                string key = "";
                while (j < n && s[j] != ')') {
                    key += s[j];
                    j++;
                }
                if (map.find(key) != map.end()) {
                    ans += map[key];
                } else {
                    ans += "?";
                }
                i = j + 1;
            } else {
                ans += s[i];
                i++;
            }
        }
        return ans;
    }
};