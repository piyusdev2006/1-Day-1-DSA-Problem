class Solution {
public:
    bool checkDivisibility(int n) {
        // Agar number negative ya 0 hai to validation
        if (n <= 0)
            return false;

        int temp = n;
        int digit_sum = 0;
        long long digit_product = 1; // long long handle karne ke liye safe hai

        while (temp > 0) {
            int last_digit = temp % 10;

            digit_sum += last_digit;
            digit_product *= last_digit;

            temp /= 10;
        }

        long long total_divisor = digit_sum + digit_product;

        if (n % total_divisor == 0) {
            return true;
        }

        return false;
    }
};