class Solution {
public:
     vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));
        
        int r = 0, c = 0;
        grid[r][c] = '.';
        
        // Traverse until we reach the bottom-right corner
        while (r < m - 1 || c < n - 1) {
            if (c < n - 1) {
                c++; // Move Right
            } else {
                r++; // Move Down
            }
            grid[r][c] = '.';
        }
        
        return grid;
        
    }
};