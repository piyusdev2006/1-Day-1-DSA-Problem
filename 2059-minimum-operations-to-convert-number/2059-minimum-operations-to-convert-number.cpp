class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<int> q;
        vector<bool> visited(1001, false);
        
        q.push(start);
        visited[start] = true;
        int steps = 0;
        
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int curr = q.front();
                q.pop();
                
                for (int num : nums) {
                    int nextVals[] = {curr + num, curr - num, curr ^ num};
                    
                    for (int nextVal : nextVals) {
                        if (nextVal == goal) {
                            return steps + 1;
                        }
                        
                        if (nextVal >= 0 && nextVal <= 1000 && !visited[nextVal]) {
                            visited[nextVal] = true;
                            q.push(nextVal);
                        }
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};