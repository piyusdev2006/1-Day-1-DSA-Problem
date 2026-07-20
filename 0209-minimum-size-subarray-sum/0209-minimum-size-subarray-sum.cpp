class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int ans = INT_MAX;

        int right;

        for (right = 0; right < nums.size(); right++) {

            sum += nums[right];

            while (sum >= target) {

                ans = min(ans, right - left + 1);

                sum -= nums[left];

                left++;
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};

/*
    int minSubArrayLen(int target, vector<int>& nums) {
int n = nums.size();
int mini = INT_MAX;

for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
        sum += nums[j];

        int length = j - i + 1;

        if (sum >= target) {
            mini = min(mini, length);
            break; // No need to extend further
        }
    }
}
return mini == INT_MAX ? 0 : mini;
}
*/