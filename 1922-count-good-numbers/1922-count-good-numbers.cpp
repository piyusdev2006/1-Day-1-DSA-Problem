class Solution {
public:
    long long MOD = 1000000007;

    long long power(long long a, long long b){

        if(b == 0)
        return 1;

        long long half = power(a, b/2);

        half = half % MOD; // preventing from signed integer overflow

        if(b % 2 == 0)
            return (half * half) % MOD;
        
        return (a % MOD * half % MOD * half) % MOD;
    }


    int countGoodNumbers(long long n) {
        

        long long evenPositions = (n + 1) / 2;
        long long oddPositions = n / 2;

        long long evenWays = power(5, evenPositions);
        long long oddWays = power(4, oddPositions);

        return (evenWays * oddWays) % MOD;
    }
};

