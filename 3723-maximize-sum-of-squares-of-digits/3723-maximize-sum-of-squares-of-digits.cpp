class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";

        string ans = "";
        int nines = sum / 9;
        int remainder = sum % 9;

        ans.append(nines, '9');
        if (nines < num && remainder > 0) {
            ans.push_back('0' + remainder);
        }
        
        int remaining_slots = num - ans.length();
        if (remaining_slots > 0) {
            ans.append(remaining_slots, '0');
        }

        return ans;
    }
};