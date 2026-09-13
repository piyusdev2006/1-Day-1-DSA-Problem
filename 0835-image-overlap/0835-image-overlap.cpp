class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        
        vector<pair<int, int>> list1;
        vector<pair<int, int>> list2;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) list1.push_back({i, j});
                if (img2[i][j] == 1) list2.push_back({i, j});
            }
        }
        
        unordered_map<int, int> vectorCount;
        int maxOverlap = 0;
        
        for (auto p1 : list1) {
            for (auto p2 : list2) {
                int dx = p2.first - p1.first;
                int dy = p2.second - p1.second;
                
                int hashKey = (dx + 30) * 100 + (dy + 30);
                
                vectorCount[hashKey]++;
                maxOverlap = max(maxOverlap, vectorCount[hashKey]);
            }
        }
        
        return maxOverlap;
    }
};