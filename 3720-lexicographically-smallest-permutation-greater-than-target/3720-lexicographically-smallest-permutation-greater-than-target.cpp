class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        // Base Case: Length alag hai toh permutation possible nahi hai
        if (s.length() != target.length()) return "";

        int n = s.length();
        
        // Step 1: String 's' ke saare characters ka frequency count le lo
        int freq[26] = {0};
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }

        string res = "";
        int prefixMatchLength = -1;

        // Step 2: Left se Right chal kar target se match karne ki koshish karo
        for (int i = 0; i < n; i++) {
            int targetCharIdx = target[i] - 'a';

            // Check karo ki kya target[i] se bada koi character available hai?
            int nextGreaterChar = -1;
            for (int c = targetCharIdx + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    nextGreaterChar = c;
                    break; // Sabse chhota available bada character select karo
                }
            }

            // Agar bada character mila, toh yeh ek valid 'split point' ho sakta hai
            if (nextGreaterChar != -1) {
                prefixMatchLength = i;
            }

            // Prefix matching barkarar rakhne ke liye target[i] khud available hona chahiye
            if (freq[targetCharIdx] > 0) {
                freq[targetCharIdx]--;
                res += target[i];
            } else {
                // Agar exact character khatam ho gaya, toh aage match nahi kar sakte
                break;
            }
        }

        // Step 3: Agar pure loop me koi bhi valid split point nahi mila, toh answer impossible hai
        if (prefixMatchLength == -1) {
            return "";
        }

        // Step 4: Final answer banane ke liye original frequency array ko firse reset karo
        int finalFreq[26] = {0};
        for (int i = 0; i < n; i++) {
            finalFreq[s[i] - 'a']++;
        }

        string finalAns = "";
        
        // Part A: Split point se pehle tak ka exact same prefix copy karo
        for (int i = 0; i < prefixMatchLength; i++) {
            finalAns += target[i];
            finalFreq[target[i] - 'a']--;
        }

        // Part B: Split point par target[i] se just bada available character rakh do
        int targetCharIdx = target[prefixMatchLength] - 'a';
        for (int c = targetCharIdx + 1; c < 26; c++) {
            if (finalFreq[c] > 0) {
                finalAns += (char)(c + 'a');
                finalFreq[c]--;
                break;
            }
        }

        // Part C: String ko lexicographically sabse chhota rakhne ke liye bache characters sorted order me bharo
        for (int c = 0; c < 26; c++) {
            while (finalFreq[c] > 0) {
                finalAns += (char)(c + 'a');
                finalFreq[c]--;
            }
        }

        return finalAns;
    }
};
