class Solution {
public:
    int myAtoi(string s) {

        int index = 0;
        int n = s.length();

        // Skip leading spaces
        while (index < n && s[index] == ' ')
            index++;

        // Empty string after removing spaces
        if (index == n)
            return 0;

        // Determine sign
        int sign = 1;
        if (s[index] == '+' || s[index] == '-') {
            if (s[index] == '-')
                sign = -1;
            index++;
        }

        long long number = 0;

        // Convert digits
        while (index < n && isdigit(s[index])) {

            int digit = s[index] - '0';

            // Check overflow before updating
            if (number > (INT_MAX - digit) / 10)
                return (sign == 1) ? INT_MAX : INT_MIN;

            number = number * 10 + digit;
            index++;
        }

        return sign * number;
    }
};