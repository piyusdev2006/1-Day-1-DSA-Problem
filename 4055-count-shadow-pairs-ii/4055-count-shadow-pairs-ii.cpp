class Solution {
private:
    const int INF = 1000000007;
    const int NEG = -1;

    vector<int> mx;
    vector<int> second_val;
    vector<int> mn;
    vector<int> cntMx;
    vector<int> active;
    vector<int> lazy;

    void build(int node, int l, int r) {
        mx[node] = NEG;
        second_val[node] = NEG;
        mn[node] = INF;
        cntMx[node] = 0;
        active[node] = 0;
        lazy[node] = INF;

        if (l == r) return;

        int mid = (l + r) >> 1;
        build(node << 1, l, mid);
        build(node << 1 | 1, mid + 1, r);
    }

    void applyChmin(int node, int x) {
        if (mx[node] <= x) return;

        mn[node] = min(mn[node], x);
        mx[node] = x;
        lazy[node] = min(lazy[node], x);
    }

    void push(int node) {
        if (lazy[node] != INF) {
            applyChmin(node << 1, lazy[node]);
            applyChmin(node << 1 | 1, lazy[node]);
            lazy[node] = INF;
        }
    }

    void pull(int node) {
        int left = node << 1;
        int right = left | 1;

        mn[node] = min(mn[left], mn[right]);
        active[node] = active[left] + active[right];

        if (mx[left] > mx[right]) {
            mx[node] = mx[left];
            cntMx[node] = cntMx[left];
            second_val[node] = max(second_val[left], mx[right]);
        } else if (mx[left] < mx[right]) {
            mx[node] = mx[right];
            cntMx[node] = cntMx[right];
            second_val[node] = max(mx[left], second_val[right]);
        } else {
            mx[node] = mx[left];
            cntMx[node] = cntMx[left] + cntMx[right];
            second_val[node] = max(second_val[left], second_val[right]);
        }
    }

    void insert(int node, int l, int r, int pos) {
        if (l == r) {
            mx[node] = INF;
            second_val[node] = NEG;
            mn[node] = INF;
            cntMx[node] = 1;
            active[node] = 1;
            lazy[node] = INF;
            return;
        }

        push(node);

        int mid = (l + r) >> 1;

        if (pos <= mid) {
            insert(node << 1, l, mid, pos);
        } else {
            insert(node << 1 | 1, mid + 1, r, pos);
        }

        pull(node);
    }

    void rangeChmin(int node, int l, int r, int ql, int qr, int x) {
        if (ql > r || qr < l || active[node] == 0 || mx[node] <= x) {
            return;
        }

        if (ql <= l && r <= qr && second_val[node] < x) {
            applyChmin(node, x);
            return;
        }

        push(node);

        int mid = (l + r) >> 1;

        rangeChmin(node << 1, l, mid, ql, qr, x);
        rangeChmin(node << 1 | 1, mid + 1, r, ql, qr, x);

        pull(node);
    }

    int query(int node, int l, int r, int ql, int qr, int x) {
        if (ql > r || qr < l || active[node] == 0 || mx[node] < x) {
            return 0;
        }

        if (ql <= l && r <= qr && mn[node] >= x) {
            return active[node];
        }

        if (l == r) {
            return mx[node] >= x ? active[node] : 0;
        }

        push(node);

        int mid = (l + r) >> 1;

        return query(node << 1, l, mid, ql, qr, x)
                + query(node << 1 | 1, mid + 1, r, ql, qr, x);
    }

    int lowerBound(const vector<unsigned long long>& order, int target) {
        int left = 0, right = order.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            int val = (int)(order[mid] >> 32);

            if (val < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

public:
    int shadowPairs(vector<int>& nums) {
        int n = nums.size();
        vector<unsigned long long> order(n);

        for (int i = 0; i < n; i++) {
            order[i] = ((unsigned long long)nums[i] << 32) | (i & 0xffffffffULL);
        }

        sort(order.begin(), order.end());

        vector<int> rank(n);

        for (int i = 0; i < n; i++) {
            rank[(int)(order[i] & 0xffffffffULL)] = i;
        }

        mx.resize(4 * n);
        second_val.resize(4 * n);
        mn.resize(4 * n);
        cntMx.resize(4 * n);
        active.resize(4 * n);
        lazy.resize(4 * n);

        build(1, 0, n - 1);

        long long res = 0;

        for (int j = 0; j < n; j++) {
            int b = nums[j];
            int right = lowerBound(order, b) - 1;

            if (right >= 0) {
                res += query(1, 0, n - 1, 0, right, b);
            }

            insert(1, 0, n - 1, rank[j]);

            int left = lowerBound(order, nums[j]) - 1;

            if (left >= 0) {
                rangeChmin(1, 0, n - 1, 0, left, nums[j]);
            }
        }

        return (int)res;
    }
};
