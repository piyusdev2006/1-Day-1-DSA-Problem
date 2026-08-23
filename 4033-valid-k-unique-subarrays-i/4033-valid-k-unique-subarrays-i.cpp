class Solution {
public:
    vector<bool> validSubarrays(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        const int MAXV = 100001;

        // ---------- Mo's ordering ----------
        int B = max(1, (int)(n / max(1.0, sqrt((double)q))));   // block size

        vector<array<int,3>> qs(q);
        for (int i = 0; i < q; i++) {
            qs[i] = { queries[i][0], queries[i][1], i };        // {l, r, id}
        }

        sort(qs.begin(), qs.end(), [&](const array<int,3>& a, const array<int,3>& b) {
            int ba = a[0] / B, bb = b[0] / B;
            if (ba != bb) return ba < bb;
            // odd-even trick: alternate blocks me r ulta chalao -> ~30% faster
            return (ba & 1) ? (a[1] > b[1]) : (a[1] < b[1]);
        });

        // ---------- window state ----------
        vector<int> cnt(MAXV, 0);
        int distinct = 0;
        int oddCount = 0;                                       // kitni values odd baar aayi hain

        // element window me daalo
        auto add = [&](int v) {
            if (cnt[v] == 0) distinct++;                        // pehli baar aaya
            if (cnt[v] & 1) oddCount--;                         // odd tha -> ab even
            else            oddCount++;                         // even tha -> ab odd
            cnt[v]++;
        };

        // element window se hatao
        auto remove = [&](int v) {
            if (cnt[v] & 1) oddCount--;                         // odd tha -> ab even
            else            oddCount++;                         // even tha -> ab odd
            cnt[v]--;
            if (cnt[v] == 0) distinct--;                        // poori tarah nikal gaya
        };

        // ---------- sweep ----------
        vector<bool> ans(q, false);
        int curL = 0, curR = -1;                                // khaali window

        for (int i = 0; i < q; i++) {
            int l = qs[i][0], r = qs[i][1], id = qs[i][2];

            // IMPORTANT: pehle expand, phir shrink -> warna curL > curR+1 wali
            // invalid state me negative counts ban jayenge
            while (curR < r) add(nums[++curR]);
            while (curL > l) add(nums[--curL]);
            while (curR > r) remove(nums[curR--]);
            while (curL < l) remove(nums[curL++]);

            ans[id] = (distinct == k) && (oddCount == 0);       // dono exact, koi probability nahi
        }

        return ans;
    }
};