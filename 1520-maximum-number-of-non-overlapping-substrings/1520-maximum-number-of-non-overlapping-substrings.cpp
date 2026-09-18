class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> L(26, -1), R(26, -1);
        
        for (int i = 0; i < n; i++) {
            if (L[s[i] - 'a'] == -1) {
                L[s[i] - 'a'] = i;
            }
            R[s[i] - 'a'] = i;
        }

        auto check = [&](int start_idx) -> int {
            int end_idx = R[s[start_idx] - 'a'];
            
            for (int j = start_idx; j <= end_idx; j++) {
                if (L[s[j] - 'a'] < start_idx) {
                    return -1; 
                }
                
                end_idx = max(end_idx, R[s[j] - 'a']);
            }
            return end_idx;
        };

        vector<pair<int, int>> intervals; 
        for (int i = 0; i < n; i++) {
           
            if (i == L[s[i] - 'a']) {
                int valid_end = check(i);
                if (valid_end != -1) {
                    intervals.push_back({valid_end, i});
                }
            }
        }

        sort(intervals.begin(), intervals.end());
        
        vector<string> ans;
        int last_end = -1;
    
        for (auto& it : intervals) {
            int end_idx = it.first;
            int start_idx = it.second;
            
            if (start_idx > last_end) {
                ans.push_back(s.substr(start_idx, end_idx - start_idx + 1));
                last_end = end_idx;
            }
        }
        
        return ans;
    }
};