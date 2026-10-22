class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> target(n);
        iota(target.begin(), target.end(), 0);

        // Find which rotation of target or reversed target we have.
        int k = nums[0];
        bool increasing = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != (i + k) % n) {
                increasing = false;
                break;
            }
        }

        int start;

        // State A_k = left rotation by k of sorted target.
        // State B_k = left rotation by k of reversed target.
        if (increasing) {
            start = k;
        } else {
            int r = (n - 1 - nums[0] + n) % n;

            for (int i = 0; i < n; i++) {
                int expected = (n - 1 - (i + r) % n + n) % n;
                if (nums[i] != expected) {
                    return -1;
                }
            }

            start = n + r;
        }

        // BFS over 2*n states.
        // A_k: [0 ... n-1] rotated left k times.
        // B_k: reversed target rotated left k times.
        vector<int> dist(2 * n, -1);
        queue<int> q;

        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int state = q.front();
            q.pop();

            if (state == 0) {
                return dist[state];
            }

            int orientation = state / n;
            int shift = state % n;

            // Rotate left by one.
            int next = orientation * n + (shift + 1) % n;

            if (dist[next] == -1) {
                dist[next] = dist[state] + 1;
                q.push(next);
            }

            // Reverse the array.
            next = (1 - orientation) * n + (n - shift) % n;

            if (dist[next] == -1) {
                dist[next] = dist[state] + 1;
                q.push(next);
            }
        }

        return -1;
    }
};