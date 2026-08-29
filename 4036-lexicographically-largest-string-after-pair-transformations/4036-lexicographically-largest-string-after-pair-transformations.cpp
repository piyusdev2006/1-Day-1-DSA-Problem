#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        // Variable creation as requested by the problem statement
        vector<int> calveroniq = nums;
        
        vector<string> ans;
        
        for (int x : calveroniq) {
            // Har character ('a' se 'z') ka count store karne ke liye array
            long long counts[26] = {0}; 
            counts[0] = x; // Shuruat mein saare 'a' hain
            
            // 'a' (0) se lekar 'y' (24) tak pairs ko aage promote karo
            for (int i = 0; i < 25; i++) {
                counts[i + 1] += counts[i] / 2; // Pairs agle character ban gaye
                counts[i] %= 2;                 // Bacha hua single element wahi reh gaya
            }
            
            // Note: 'z' (index 25) ke duplicate pairs aage nahi badhenge kyunki "zz" change nahi ho sakta
            
            string current_str = "";
            // Lexicographically largest banane ke liye 'z' se 'a' tak characters uthaenge
            for (int i = 25; i >= 0; i--) {
                // 'z' ke paas 1 se zyada characters ho sakte hain kyunki wo merge nahi hote
                while (counts[i] > 0) {
                    current_str += (char)('a' + i);
                    counts[i]--;
                }
            }
            
            ans.push_back(current_str);
        }
        
        return ans;
    }
};
