

struct Node {
    int prod = 1;
    int remain[5] = {0};
};

class Solution {
    int k_val;
    vector<Node> tree;
    
    Node mergeNodes(const Node& left, const Node& right) {
        Node res;
        res.prod = (left.prod * right.prod) % k_val;
        for (int i = 0; i < k_val; ++i) {
            res.remain[i] = left.remain[i];
        }
        for (int i = 0; i < k_val; ++i) {
            int new_mod = (left.prod * i) % k_val;
            res.remain[new_mod] += right.remain[i];
        }
        return res;
    }
    
    void build(int node, int start, int end, const vector<int>& nums) {
        if (start == end) {
            tree[node].prod = nums[start] % k_val;
            tree[node].remain[nums[start] % k_val] = 1;
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid, nums);
        build(2 * node + 1, mid + 1, end, nums);
        tree[node] = mergeNodes(tree[2 * node], tree[2 * node + 1]);
    }
    
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            for(int i = 0; i < k_val; i++) tree[node].remain[i] = 0;
            tree[node].prod = val % k_val;
            tree[node].remain[val % k_val] = 1;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = mergeNodes(tree[2 * node], tree[2 * node + 1]);
    }
    
    Node query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return Node(); 
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        Node leftNode = query(2 * node, start, mid, l, r);
        Node rightNode = query(2 * node + 1, mid + 1, end, l, r);
        return mergeNodes(leftNode, rightNode);
    }
    
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        k_val = k;
        int n = nums.size();
        tree.assign(4 * n + 1, Node());
        build(1, 0, n - 1, nums);
        
        vector<int> res;
        for (auto& q : queries) {
            update(1, 0, n - 1, q[0], q[1]);
            Node qNode = query(1, 0, n - 1, q[2], n - 1);
            res.push_back(qNode.remain[q[3]]);
        }
        return res;
    }
};