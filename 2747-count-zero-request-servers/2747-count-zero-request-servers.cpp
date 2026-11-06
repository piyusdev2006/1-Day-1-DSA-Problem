class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int q_len = queries.size();
        vector<int> ans(q_len);
        vector<pair<int, int>> sorted_queries(q_len);
        
        for (int i = 0; i < q_len; ++i) {
            sorted_queries[i] = {queries[i], i};
        }
        
        sort(sorted_queries.begin(), sorted_queries.end());
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        vector<int> server_count(n + 1, 0);
        int unique_active_servers = 0;
        int left = 0;
        int right = 0;
        int log_len = logs.size();
        
        for (int i = 0; i < q_len; ++i) {
            int query_time = sorted_queries[i].first;
            int query_idx = sorted_queries[i].second;
            
            int window_start = query_time - x;
            int window_end = query_time;
            
            while (right < log_len && logs[right][1] <= window_end) {
                int server_id = logs[right][0];
                if (server_count[server_id] == 0) {
                    unique_active_servers++;
                }
                server_count[server_id]++;
                right++;
            }
            
            while (left < log_len && logs[left][1] < window_start) {
                int server_id = logs[left][0];
                server_count[server_id]--;
                if (server_count[server_id] == 0) {
                    unique_active_servers--;
                }
                left++;
            }
            
            ans[query_idx] = n - unique_active_servers;
        }
        
        return ans;
    }
};
