class Solution {
public:

    void merge(vector<int>& nums, int mid, int low, int high) {

        int left = low;
        int right = mid + 1;

        vector<int> temp;

        // Compare both sorted halves
        while(left <= mid && right <= high){

            if(nums[left] < nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }

        // Add remaining elements from left half
        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }

        // Add remaining elements from right half
        while(right <= high){
            temp.push_back(nums[right]);
            right++;
        }

        // Copy sorted elements back to nums
        for(int k = low; k <= high; k++){
            nums[k] = temp[k - low];
        }
    }

    void mergeSort(vector<int>& nums, int low, int high) {

        if(low == high || low > high){
            return;
        }

        int mid = low + (high - low) / 2;

        // Sort left half
        mergeSort(nums, low, mid);

        // Sort right half
        mergeSort(nums, mid + 1, high);

        // Merge both sorted halves
        merge(nums, mid, low, high);
    }

    vector<int> sortArray(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        mergeSort(nums, low, high);

        return nums;
    }
};