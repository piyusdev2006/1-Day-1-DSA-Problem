class Solution {
    int solve(int n, vector<int>&dp){
        if(n <=1) return n;

        if(dp[n] != -1) return dp[n];

        dp[n] = solve(n-1, dp) + solve(n-2, dp);
        return dp[n];
    }
public:
    
    int fib(int n) {
        vector<int>dp(n+1, -1);

        return solve(n, dp);
    }
};

// basic recursion
// int fib(int n) {
//         if(n <= 1) return n;

//         return fib(n-1) + fib(n-2);
//     }