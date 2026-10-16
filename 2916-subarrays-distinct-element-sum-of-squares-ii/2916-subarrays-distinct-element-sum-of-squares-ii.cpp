class Solution {
private:
    vector<long long> treeSum;
    vector<long long> treeSqSum;
    vector<long long> lazy;
    long long MOD = 1e9 + 7;

    void push(int node, int start, int end) {
        if (lazy[node] == 0) return;
        
        int mid = start + (end - start) / 2;
        int left = 2 * node;
        int right = 2 * node + 1;

        long long val = lazy[node];

        lazy[left] = (lazy[left] + val) % MOD;
        treeSqSum[left] = (treeSqSum[left] + 2 * val * treeSum[left] % MOD + (mid - start + 1) * val % MOD * val % MOD) % MOD;
        treeSum[left] = (treeSum[left] + (mid - start + 1) * val % MOD) % MOD;

        lazy[right] = (lazy[right] + val) % MOD;
        treeSqSum[right] = (treeSqSum[right] + 2 * val * treeSum[right] % MOD + (end - mid) * val % MOD * val % MOD) % MOD;
        treeSum[right] = (treeSum[right] + (end - mid) * val % MOD) % MOD;

        lazy[node] = 0;
    }

    void update(int node, int start, int end, int l, int r, long long val) {
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            lazy[node] = (lazy[node] + val) % MOD;
            treeSqSum[node] = (treeSqSum[node] + 2 * val * treeSum[node] % MOD + (end - start + 1) * val % MOD * val % MOD) % MOD;
            treeSum[node] = (treeSum[node] + (end - start + 1) * val % MOD) % MOD;
            return;
        }
        
        push(node, start, end);
        int mid = start + (end - start) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        
        treeSum[node] = (treeSum[2 * node] + treeSum[2 * node + 1]) % MOD;
        treeSqSum[node] = (treeSqSum[2 * node] + treeSqSum[2 * node + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        treeSum.assign(4 * n, 0);
        treeSqSum.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        unordered_map<int, int> lastIdx;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int last = lastIdx.count(nums[i]) ? lastIdx[nums[i]] : -1;
            update(1, 0, n - 1, last + 1, i, 1);
            ans = (ans + treeSqSum[1]) % MOD;
            lastIdx[nums[i]] = i;
        }

        return ans;
    }
};
