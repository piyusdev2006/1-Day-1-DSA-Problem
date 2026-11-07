#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        vector<int> ans(m);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> freeServers;
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busyServers;

        for (int i = 0; i < n; ++i) {
            freeServers.push({servers[i], i});
        }

        long long currTime = 0;
        for (int j = 0; j < m; ++j) {
            currTime = max(currTime, (long long)j);

            while (!busyServers.empty() && busyServers.top().first <= currTime) {
                int idx = busyServers.top().second;
                busyServers.pop();
                freeServers.push({servers[idx], idx});
            }

            if (freeServers.empty()) {
                currTime = busyServers.top().first;
                while (!busyServers.empty() && busyServers.top().first <= currTime) {
                    int idx = busyServers.top().second;
                    busyServers.pop();
                    freeServers.push({servers[idx], idx});
                }
            }

            auto [weight, idx] = freeServers.top();
            freeServers.pop();

            ans[j] = idx;
            busyServers.push({currTime + tasks[j], idx});
        }

        return ans;
    }
};
