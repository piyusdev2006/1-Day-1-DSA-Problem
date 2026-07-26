class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int i = 0;
        int j = 0;

        vector<vector<int>> ans;

        while (i < series1.size() || j < series2.size()) {

            if (j == series2.size() ||
                (i < series1.size() && series1[i][0] < series2[j][0])) {

                ans.push_back({
                    series1[i][0],
                    series1[i][1] + (j < series2.size() ? series2[j][1] : 0)
                });

                i++;
            }

            else if (i == series1.size() ||
                     series2[j][0] < series1[i][0]) {

                ans.push_back({
                    series2[j][0],
                    (i < series1.size() ? series1[i][1] : 0) + series2[j][1]
                });

                j++;
            }

            else {

                ans.push_back({
                    series1[i][0],
                    series1[i][1] + series2[j][1]
                });

                i++;
                j++;
            }
        }

        return ans;
    }
};