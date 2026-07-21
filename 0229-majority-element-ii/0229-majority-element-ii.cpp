class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int vote1 = 0;
        int vote2 = 0;

        int candidate1 = 0;
        int candidate2 = 1;

        for (int num : nums) {

            if (num == candidate1) {
                vote1++;
            }

            else if (num == candidate2) {
                vote2++;
            }

            else if (vote1 == 0) {
                candidate1 = num;
                vote1 = 1;
            }

            else if (vote2 == 0) {
                candidate2 = num;
                vote2 = 1;
            }

            else {

                vote1--;
                vote2--;
            }
        }

        vector<int> ans;

        int vote1Freq = 0;
        int vote2Freq = 0;

        for (int num : nums) {

            if (num == candidate1)
                vote1Freq++;

            else if (num == candidate2)
                vote2Freq++;
        }

        if (vote1Freq > nums.size()/3)
            ans.push_back(candidate1);

        if (vote2Freq > nums.size()/3)
            ans.push_back(candidate2);

        return ans;
    }
};