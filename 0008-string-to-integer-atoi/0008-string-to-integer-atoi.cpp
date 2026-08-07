class Solution {
public:

    int myAtoi(string s) {
        // Step 1: Empty string
        if (s.empty())
            return 0;

        // Step 2: Skip leading spaces
        int i = 0;

        while (i < s.size() && s[i] == ' ')
            i++;

        // All spaces
        if (i == s.size())
            return 0;

        // Step 3: Remove leading spaces
        s = s.substr(i);

        // Step 4: Find sign
        int sign = 1;

        if (s[0] == '-')
            sign = -1;

        // Step 5: Start index
        i = (s[0] == '+' || s[0] == '-') ? 1 : 0;

        // Step 6: Build number
        long long number = 0;

        while (i < s.size()) {

            // Stop at first non-digit
            if (!isdigit(s[i]))
                break;

            int digit = s[i] - '0';

            // Step 7: Check overflow
            if (sign == 1 && number > (INT_MAX - digit) / 10)
                return INT_MAX;

            if (sign == -1 && number > (-(long long)INT_MIN - digit) / 10)
                return INT_MIN;

            // Add digit
            number = number * 10 + digit;

            i++;
        }

        // Step 8: Apply sign
        return sign * number;
    }
};