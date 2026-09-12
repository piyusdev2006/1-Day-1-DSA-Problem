

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        vector<tuple<int, int, long long, int>> arr;
        for (int i = 0; i < n; ++i) {
            arr.emplace_back(intervals[i][0], intervals[i][1],
                             (long long)intervals[i][2], i);
        }
        
        sort(arr.begin(), arr.end());

        vector<int> next_idx(n, n);
        for (int i = 0; i < n; ++i) {
            int low = i + 1, high = n - 1, current_end = get<1>(arr[i]);
            while (low <= high) {
                int mid = (low + high) / 2;
                if (get<0>(arr[mid]) > current_end) {
                    next_idx[i] = mid;
                    high = mid - 1;
                } else
                    low = mid + 1;
            }
        }

        // Struct to hold dp states
        struct State {
            long long weight = 0;
            vector<int> path;
        };

        // DP Array: dp[N+1][5]
        vector<vector<State>> dp(n + 1, vector<State>(5));

        // Bottom-Up logic
        for (int i = n - 1; i >= 0; --i) {
            for (int k = 1; k <= 4; ++k) {

                // Not Pick
                State notPick = dp[i + 1][k];

                // Pick
                int nxt = next_idx[i];
                State pick = dp[nxt][k - 1];
                pick.weight += get<2>(arr[i]);
                pick.path.push_back(get<3>(arr[i]));
                sort(pick.path.begin(), pick.path.end());

                // Compare & Store
                if (pick.weight > notPick.weight)
                    dp[i][k] = pick;
                else if (notPick.weight > pick.weight)
                    dp[i][k] = notPick;
                else
                    dp[i][k] = (pick.path < notPick.path) ? pick : notPick;
            }
        }

        return dp[0][4].path;
    }
};