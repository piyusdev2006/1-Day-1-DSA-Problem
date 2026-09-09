class Solution {
public:
    long long countCommas(long long n) {
        long long totalCommas = 0;
        long long threshold = 1000;
        
        while (n >= threshold) {
            // Jitne bhi numbers is threshold (1000, 1000000, etc.) se bade ya 
            // barabar hain, un sabka 1 comma count mein add kar do
            totalCommas += (n - threshold + 1);
            
            // Agle comma check karne ke liye limit bada do
            threshold *= 1000; 
        }
        
        return totalCommas;
    }
};