class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }
        
        vector<bool> suspicious(n, false);
        queue<int> q;
        q.push(k);
        suspicious[k] = true;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int next : adj[curr]) {
                if (!suspicious[next]) {
                    suspicious[next] = true;
                    q.push(next);
                }
            }
        }
        
        bool cannotRemove = false;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) {
                for (int next : adj[i]) {
                    if (suspicious[next]) {
                        cannotRemove = true;
                        break;
                    }
                }
            }
            if (cannotRemove) break;
        }
        
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (cannotRemove || !suspicious[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};