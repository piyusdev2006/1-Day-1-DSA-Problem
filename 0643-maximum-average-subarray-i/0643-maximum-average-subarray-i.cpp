class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
          int windowSum = 0;

        // First window
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        int maxSum = windowSum;

        // Slide the window
        for (int i = k; i < nums.size(); i++) {

            windowSum += nums[i];       // add new element
            windowSum -= nums[i - k];   // remove old element

            maxSum = max(maxSum, windowSum);
        }

        return (double)maxSum / k;
    }
};