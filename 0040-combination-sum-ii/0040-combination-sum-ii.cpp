class Solution {
public:
    void solve(int start, int target, vector<int>& candidates,
               vector<int>& current, vector<vector<int>>& result) {

        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // Skip duplicate choices at the same level
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Since array is sorted
            if (candidates[i] > target) {
                break;
            }

            current.push_back(candidates[i]);

            solve(i + 1, target - candidates[i], candidates, current, result);

            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> result;
        vector<int> current;

        solve(0, target, candidates, current, result);

        return result;
    }
};