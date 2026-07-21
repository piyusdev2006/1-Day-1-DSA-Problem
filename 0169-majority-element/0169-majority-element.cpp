class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // voting algorithm
        int count = 0;
        int candidate = 0;

        for (int num : nums) {
            if(num == candidate){
                count++;
            }
            else if(count == 0){
                candidate = num;
                count++;
            }
            else{
                count--;
            }
        }

        return candidate;
    }
};