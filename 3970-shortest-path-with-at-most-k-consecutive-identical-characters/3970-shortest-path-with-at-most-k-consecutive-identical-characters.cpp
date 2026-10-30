#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct State {
        int dist;
        int node;
        int consec;
        
        // Custom comparator for min-heap implementation
        bool operator>(const State& other) const {
            return dist > other.dist;
        }
    };

public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
        }
        
        // dist[node][consecutive_count]
        vector<vector<int>> dist(n, vector<int>(k + 1, 1e9));
        priority_queue<State, vector<State>, greater<State>> pq;
        
        dist[0][1] = 0;
        pq.push({0, 0, 1});
        
        while (!pq.empty()) {
            State curr = pq.top();
            pq.pop();
            
            int d = curr.dist;
            int u = curr.node;
            int consec = curr.consec;
            
            // First time reaching destination guarantees the absolute shortest path
            if (u == n - 1) return d;
            if (d > dist[u][consec]) continue;
            
            for (auto &edge : adj[u]) {
                int v = edge.first;
                int wt = edge.second;
                
                int nextConsec = (labels[v] == labels[u]) ? consec + 1 : 1;
                
                if (nextConsec <= k) {
                    if (d + wt < dist[v][nextConsec]) {
                        dist[v][nextConsec] = d + wt;
                        pq.push({d + wt, v, nextConsec});
                    }
                }
            }
        }
        
        return -1;
    }
};
