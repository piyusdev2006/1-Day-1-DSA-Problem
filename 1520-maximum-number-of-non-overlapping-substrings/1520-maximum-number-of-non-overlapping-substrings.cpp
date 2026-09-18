class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, n), last(26, -1);

        for(int i = 0; i < n; i++) {
            first[s[i]-'a'] = min(first[s[i]-'a'], i);
            last[s[i]-'a'] = i;
        }

        vector<string> res;
        int prevEnd = -1;

        for(int i = 0; i < n; i++) {

            if(i != first[s[i]-'a']) continue;

            int end = last[s[i]-'a'];
            bool valid = true;

            for(int j = i; j <= end; j++) {
                if(first[s[j]-'a'] < i) {
                    valid = false;
                    break;
                }
                end = max(end, last[s[j]-'a']);
            }

            if(valid) {
                if(i > prevEnd) {
                    res.push_back(s.substr(i, end - i + 1));
                } else {
                    res.back() = s.substr(i, end - i + 1);
                }
                prevEnd = end;
            }
        }

        return res;
    }
};