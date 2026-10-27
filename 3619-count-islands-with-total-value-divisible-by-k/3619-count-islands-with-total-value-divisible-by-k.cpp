class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int ans = 0;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0 && !vis[i][j]) {
                    long long islandSum = 0;
                    queue<pair<int, int>> q;

                    q.push({i, j});
                    vis[i][j] = 1;

                    while (!q.empty()) {
                        auto curr = q.front();
                        q.pop();
                        int r = curr.first;
                        int c = curr.second;
                        islandSum += grid[r][c];

                        for (int d = 0; d < 4; d++) {
                            int nRow = r + delRow[d];
                            int nCol = c + delCol[d];

                            if (nRow >= 0 && nRow < m && nCol >= 0 &&
                                nCol < n && grid[nRow][nCol] > 0 &&
                                !vis[nRow][nCol]) {
                                vis[nRow][nCol] = 1;
                                q.push({nRow, nCol});
                            }
                        }
                    }

                    if (islandSum % k == 0) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};