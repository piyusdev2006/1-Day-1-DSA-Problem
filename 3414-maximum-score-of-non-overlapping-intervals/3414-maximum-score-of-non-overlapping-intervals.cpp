struct State {
    long long weight = 0;
    vector<int> selected;
};

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& input) {
        int n = input.size();
       
        vector<tuple<int, int, long long, int>> intervals;
        for (int i = 0; i < n; ++i) {
            intervals.emplace_back(input[i][0], input[i][1], (long long)input[i][2], i);
        }
        
        sort(intervals.begin(), intervals.end());
        
        vector<int> next_idx(n, n);
        for (int i = 0; i < n; ++i) {
            int low = i + 1, high = n - 1;
            int current_end = get<1>(intervals[i]);
            
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (get<0>(intervals[mid]) > current_end) {
                    next_idx[i] = mid;
                    high = mid - 1; 
                } else {
                    low = mid + 1;
                }
            }
        }
      
        vector<vector<State>> memo(n + 1, vector<State>(5));
        
        for (int i = n - 1; i >= 0; --i) {
            for (int quota = 1; quota <= 4; ++quota) {
                
                State skip = memo[i + 1][quota];
                
                int nxt = next_idx[i];
                State next_res = memo[nxt][quota - 1];
                
                State pick;
                pick.weight = get<2>(intervals[i]) + next_res.weight;
                pick.selected = next_res.selected;
                pick.selected.push_back(get<3>(intervals[i])); 
                sort(pick.selected.begin(), pick.selected.end());
                
                if (pick.weight > skip.weight) {
                    memo[i][quota] = pick;
                } else if (pick.weight == skip.weight) {
                    if (pick.selected < skip.selected) {
                        memo[i][quota] = pick;
                    } else {
                        memo[i][quota] = skip;
                    }
                } else {
                    memo[i][quota] = skip;
                }
            }
        }
        
        return memo[0][4].selected;
    }
};