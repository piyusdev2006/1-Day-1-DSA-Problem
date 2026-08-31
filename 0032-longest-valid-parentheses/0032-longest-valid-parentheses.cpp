
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        // Edge Case: Agar string khali hai ya sirf 1 character hai, toh valid ho hi nahi sakti
        if (n <= 1) return 0;
        
        // dp[i] store karega: index 'i' par khatam hone wali longest valid substring ki length
        vector<int> dp(n, 0);
        int maxLength = 0; // Global maximum track karne ke liye
        
        // Index 0 se shuru nahi kar sakte kyunki akele character se koi pair nahi banta
        for (int i = 1; i < n; i++) {
            // Hum sirf tabhi check karenge jab current character ek closing bracket ')' ho
            if (s[i] == ')') {
                
                // CASE 1: Agar just piche wala character opening bracket '(' hai -> "...()"
                if (s[i - 1] == '(') {
                    // Agar i-2 valid index hai toh pichla answer jod lo, nahi toh sirf ye 2 points
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                }
                
                // CASE 2: Agar piche wala character bhi closing ')' hai -> "...))"
                // Aur is current ')' ko balance karne ke liye piche s[i - dp[i-1] - 1] par ek '(' maujood ho
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    
                    // dp[i-1] = andar ki valid string ki length
                    // 2 = current ')' aur usko match karne wale '(' ki length
                    // Pichla bacha part = jo matches ke bhi pehle tha -> dp[i - dp[i-1] - 2]
                    int prevValid = (i - dp[i - 1] >= 2) ? dp[i - dp[i - 1] - 2] : 0;
                    
                    dp[i] = dp[i - 1] + 2 + prevValid;
                }
                
                // Har step par maximum length ko update karte chalo
                maxLength = max(maxLength, dp[i]);
            }
        }
        
        return maxLength;
    }
};
