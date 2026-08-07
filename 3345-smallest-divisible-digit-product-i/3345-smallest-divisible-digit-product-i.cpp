class Solution {
public:
    long long getProduct(int num) {
        long long product = 1;

        while (num > 0) {
            product *= num % 10;
            num /= 10;
        }

        return product;
    }

    int smallestNumber(int n, int t) {

        while (true) {

            long long product = getProduct(n);

            if (product % t == 0) {
                return n;
            }

            n++;
        }
    }
};
