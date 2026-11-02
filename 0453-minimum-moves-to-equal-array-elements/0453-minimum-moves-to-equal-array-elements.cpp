class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min = INT_MAX;
        for (int x : nums){
             if (x < min) min = x;
        }
        long moves = 0;
        for (int x : nums){
            moves += x - min;
        } 
        return (int) moves;
    }
};