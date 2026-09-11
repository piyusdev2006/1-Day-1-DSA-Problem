class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        //  Frequency array banao
        vector<int> count(10, 0);
        for (int digit : digits) {
            count[digit]++;
        }
        
        int totalCount = 0; 
        
        //  100 se 998 tak loop for 3 digit even no
        for (int i = 100; i <= 998; i += 2) {
            int ones = i % 10;
            int tens = (i / 10) % 10;
            int hundreds = i / 100;
            
            vector<int> currentCount(10, 0);
            currentCount[ones]++;
            currentCount[tens]++;
            currentCount[hundreds]++;
            
            // Step 3: Check karo kya number available digits se ban sakta hai
            if (currentCount[ones] <= count[ones] && 
                currentCount[tens] <= count[tens] && 
                currentCount[hundreds] <= count[hundreds]) {
                
                totalCount++; // Number ban sakta hai, toh counter badha do
            }
        }
        
        return totalCount; 
    }
};