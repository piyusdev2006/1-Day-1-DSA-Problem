class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        int B = sqrt(n) + 1;
        int numBlocks = (n + B - 1) / B;
        vector<int> blockProd(numBlocks, 1);
        vector<vector<int>> blockRemain(numBlocks, vector<int>(k, 0));
        
        auto buildBlock = [&](int b) {
            blockProd[b] = 1;
            for(int i = 0; i < k; i++) blockRemain[b][i] = 0;
            int start = b * B;
            int end = min(n, start + B);
            for (int i = start; i < end; ++i) {
                blockProd[b] = (blockProd[b] * (nums[i] % k)) % k;
                blockRemain[b][blockProd[b]]++;
            }
        };
        
        for (int b = 0; b < numBlocks; ++b) {
            buildBlock(b);
        }
        
        vector<int> res;
        for (auto& q : queries) {
            int idx = q[0], val = q[1], start = q[2], xi = q[3];
            nums[idx] = val;
            buildBlock(idx / B);
            
            int count = 0;
            int currProd = 1;
            int bStart = start / B;
            
            int endPartial = min(n, (bStart + 1) * B);
            for (int i = start; i < endPartial; ++i) {
                currProd = (currProd * (nums[i] % k)) % k;
                if (currProd == xi) count++;
            }
            
            for (int b = bStart + 1; b < numBlocks; ++b) {
                for (int r = 0; r < k; ++r) {
                    if ((currProd * r) % k == xi) {
                        count += blockRemain[b][r];
                    }
                }
                currProd = (currProd * blockProd[b]) % k;
            }
            res.push_back(count);
        }
        return res;
    }
};