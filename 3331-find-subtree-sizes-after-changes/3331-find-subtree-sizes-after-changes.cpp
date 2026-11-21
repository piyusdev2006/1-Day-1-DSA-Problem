class Solution {
public:
    void findNewParents(int u, vector<vector<int>>& adj, string& s, vector<int>& lastSeen, vector<int>& newParent) {
        int c = s[u] - 'a';
        int prev = lastSeen[c];

        if (u != 0 && prev != -1) {
            newParent[u] = prev;
        }

        lastSeen[c] = u;
        for (int v : adj[u]) {
            findNewParents(v, adj, s, lastSeen, newParent);
        }
        lastSeen[c] = prev;
    }

    int countSubtree(int u, vector<vector<int>>& finalAdj, vector<int>& ans) {
        int sz = 1;
        for (int v : finalAdj[u]) {
            sz += countSubtree(v, finalAdj, ans);
        }
        return ans[u] = sz;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent = parent;
        vector<int> lastSeen(26, -1);
        findNewParents(0, adj, s, lastSeen, newParent);

        vector<vector<int>> finalAdj(n);
        for (int i = 1; i < n; i++) {
            finalAdj[newParent[i]].push_back(i);
        }

        vector<int> ans(n, 0);
        countSubtree(0, finalAdj, ans);
        return ans;
    }
};
