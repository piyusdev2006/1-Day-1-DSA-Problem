class Solution {
public:
    double solve(double x, long n) {
        if (n == 0)
            return 1; // Base case
        if (n < 0)
            return solve(1 / x, -n); // if n is a negative power
        if (n % 2 == 0)
            return solve(x * x, n / 2);       // if n is even power
        return x * solve(x * x, (n - 1) / 2); // if n is odd power
    }
    
    double myPow(double x, int n) { 
        return solve(x, long(n)); 
    }
};

/*
    class Solution {
public:

    double solve(double x,long long n){

        if(n==0)

            return 1;

        double half=solve(x,n/2);

        if(n%2==0)

            return half*half;

        return x*half*half;
    }

    double myPow(double x,int n){

        long long power=n;

        if(power<0){

            x=1/x;

            power=-power;

        }

        return solve(x,power);

    }

};
*/