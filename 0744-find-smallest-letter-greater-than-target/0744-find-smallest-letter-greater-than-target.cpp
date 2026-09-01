class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2; // Overflow se bachne ke liye

            if (letters[mid] <= target) {
                // Agar mid element target se chota ya barabar hai,
                // toh hamara answer right side mein hi hoga.
                low = mid + 1;
            } else {
                // Agar mid element target se bada hai, toh yeh answer ho sakta
                // hai, par kya iss se bhi chota koi bada element hai? Left
                // check karo.
                high = mid - 1;
            }
        }

        // Wrap-around logic: Agar low == n ho gaya, toh n % n = 0 return
        // karega.
        return letters[low % n];
    }
};