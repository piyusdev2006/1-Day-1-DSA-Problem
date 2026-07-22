class Solution {
public:
    void merge(vector<int> &arr, int low, int mid, int high) {

    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left++]);
        }
        else {
            temp.push_back(arr[right++]);
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left++]);
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right++]);
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

int countReversePairs(vector<int> &arr, int low, int mid, int high) {

    int count = 0;
    int right = mid + 1;

    for (int i = low; i <= mid; i++) {
        while (right <= high && (long long)arr[i] > 2* (long long)arr[right]) right++;
        count += (right - (mid + 1));
    }
    return count;
}

int mergeSort(vector<int> &arr, int low, int high) {

    int count = 0;
    // base case
    if (low >= high) return count;

    int mid = low + (high - low)/2;

    count += mergeSort(arr, low, mid);  // left half

    count += mergeSort(arr, mid + 1, high); // right half

    count += countReversePairs(arr, low, mid, high); //Modification

    merge(arr, low, mid, high);  // merging sorted halves
    return count;
}

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};