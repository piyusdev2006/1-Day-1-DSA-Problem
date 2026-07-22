class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int ans = INT_MIN;

        for(int left = 0; left < cols; left++) {

            vector<int> rowSum(rows,0);

            for(int right = left; right < cols; right++) {

                for(int r = 0; r < rows; r++)
                    rowSum[r] += matrix[r][right];

                set<int> st;

                st.insert(0);

                int prefix = 0;

                for(int x : rowSum) {

                    prefix += x;

                    auto it = st.lower_bound(prefix-k);

                    if(it!=st.end())
                        ans=max(ans,prefix-*it);

                    st.insert(prefix);
                }
            }
        }

        return ans;
    }
};
