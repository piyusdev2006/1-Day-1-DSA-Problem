class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        int max_sum = INT_MIN;

        // Outer loop for left column boundary
        for (int left = 0; left < cols; ++left) {
            // This stores sum of elements between 'left' and 'right' columns
            // for each row
            vector<int> row_sums(rows, 0);

            // Inner loop for right column boundary
            for (int right = left; right < cols; ++right) {

                // Update row_sums for the current right column
                for (int r = 0; r < rows; ++r) {
                    row_sums[r] += matrix[r][right];
                }

                // Now find the max subarray sum <= k in row_sums (1D problem)
                set<int> accumulated_sums;
                accumulated_sums.insert(0); // Base case for prefix sum
                int current_sum = 0;

                for (int sum : row_sums) {
                    current_sum += sum;

                    // We need: current_sum - target <= k  =>  target >=
                    // current_sum - k
                    auto it = accumulated_sums.lower_bound(current_sum - k);

                    if (it != accumulated_sums.end()) {
                        max_sum = max(max_sum, current_sum - *it);
                    }

                    accumulated_sums.insert(current_sum);
                }
            }
        }

        return max_sum;
    }
};
