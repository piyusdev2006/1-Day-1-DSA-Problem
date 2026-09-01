class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int startRow = -1, startCol = -1;
        map<pair<int, int>, int> litterMap;
        int litterCount = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    startRow = i;
                    startCol = j;
                } else if (classroom[i][j] == 'L') {
                    litterMap[{i, j}] = litterCount++;
                }
            }
        }
        
        int targetMask = (1 << litterCount) - 1;
        if (targetMask == 0) return 0;
        
        vector<vector<vector<int>>> maxEnergyAtState(m, vector<vector<int>>(n, vector<int>(1 << litterCount, -1)));
        
        queue<vector<int>> q;
        q.push({0, startRow, startCol, energy, 0});
        maxEnergyAtState[startRow][startCol][0] = energy;
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            int moves = curr[0];
            int r = curr[1];
            int c = curr[2];
            int currEnergy = curr[3];
            int mask = curr[4];
            
            if (currEnergy < maxEnergyAtState[r][c][mask]) continue;
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && classroom[nr][nc] != 'X') {
                    int nextEnergy = currEnergy - 1;
                    if (nextEnergy < 0) continue;
                    
                    int nextMask = mask;
                    
                    if (classroom[nr][nc] == 'R') {
                        nextEnergy = energy;
                    } else if (classroom[nr][nc] == 'L') {
                        int litterIdx = litterMap[{nr, nc}];
                        nextMask |= (1 << litterIdx);
                    }
                    
                    if (nextMask == targetMask) {
                        return moves + 1;
                    }
                    
                    if (nextEnergy > maxEnergyAtState[nr][nc][nextMask]) {
                        maxEnergyAtState[nr][nc][nextMask] = nextEnergy;
                        q.push({moves + 1, nr, nc, nextEnergy, nextMask});
                    }
                }
            }
        }
        
        return -1;
    }
};
