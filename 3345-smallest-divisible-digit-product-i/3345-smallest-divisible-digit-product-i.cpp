class Solution {
public:
    long long getProduct(int num) {
        long long product = 1;

        while (num > 0) {
            int digit = num % 10;
            product *= digit;
            num /= 10;
        }

        return product;
    }
    int smallestNumber(int n, int t) {
        while (true) {

            long long digitProduct = getProduct(n);

            if (digitProduct % t == 0) {
                return n;
            }

            n++;
        }
    }
};