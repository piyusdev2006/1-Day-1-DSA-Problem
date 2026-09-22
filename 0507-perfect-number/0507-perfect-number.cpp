class Solution {
public:
    bool checkPerfectNumber(int num) {
         //1 ya usse chota number perfect nahi ho sakta , evenly divide hona chahiye
        if (num <= 1) return false;
        
        int sum = 1; // 1 toh har kisi ka divisor hota , so added it
        
        // Loop sirf sqrt(num) tak chalayenge 
        for (int i = 2; i * i <= num; i++) {    // O(√N) tc hi aayega
            if (num % i == 0) {
                sum += i; // Pehla factor add kiya
                
                if (i * i != num) { 
                    sum += num / i; //dusra factor bhi add kar diya
                }
            }
        }
        
        
        return sum == num;
    }
};