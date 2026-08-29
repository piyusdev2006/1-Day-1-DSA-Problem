class Solution {
private:
    // DFS function to find all connected indices in a group
    void dfs(int node, vector<vector<int>>& adj, string& s, vector<bool>& visited, vector<int>& indices, string& chars) {
        visited[node] = true;
        indices.push_back(node);     // Index collect kiya
        chars.push_back(s[node]);    // Character collect kiya
        
        for(auto neighbor : adj[node]) {
            if(!visited[neighbor]) {
                dfs(neighbor, adj, s, visited, indices, chars);
            }
        }
    }

public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        vector<vector<int>> adj(n);
        
        // Step 1: Build the Graph
        for(auto pair : pairs) {
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        }
        
        vector<bool> visited(n, false);
        
        // Step 2: Traverse each character
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                vector<int> indices;
                string chars = "";
                
                // DFS se ek group ke saare indices aur chars uthao
                dfs(i, adj, s, visited, indices, chars);
                
                // Step 3: Indices aur Characters ko alag-alag sort karo
                sort(indices.begin(), indices.end());
                sort(chars.begin(), chars.end());
                
                // Step 4: Sorted chars ko sorted positions par daal do
                for(int k = 0; k < indices.size(); k++) {
                    s[indices[k]] = chars[k];
                }
            }
        }
        
        return s;
    }
};
