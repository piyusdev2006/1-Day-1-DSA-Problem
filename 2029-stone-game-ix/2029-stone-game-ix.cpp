class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int count[3] = {0, 0, 0};
        
        // Categorize stones by their remainder when divided by 3
        for (int stone : stones) {
            count[stone % 3]++;
        }
        
        // Case 1: Count of type 0 stones is even
        if (count[0] % 2 == 0) {
            return count[1] > 0 && count[2] > 0;
        }
        
        // Case 2: Count of type 0 stones is odd
        return std::abs(count[1] - count[2]) > 2;
    }
};