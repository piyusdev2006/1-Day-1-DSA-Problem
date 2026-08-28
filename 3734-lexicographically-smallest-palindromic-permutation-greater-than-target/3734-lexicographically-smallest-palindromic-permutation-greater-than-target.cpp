class Solution {
private:
    // Helper function jo bache hue characters ko smallest sorted order mein append karega
    string tryBuild(string left, vector<int>& counts, int mid_char) {
        for (int c = 0; c < 26; ++c) {
            int available_half = counts[c] / 2;
            if (available_half > 0) {
                left.append(available_half, (char)('a' + c));
            }
        }
        
        string full_palindrome = left;
        if (mid_char != -1) {
            full_palindrome.push_back((char)('a' + mid_char));
        }
        
        string right = left;
        reverse(right.begin(), right.end());
        full_palindrome += right;
        
        return full_palindrome;
    }

public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> counts(26, 0);
        for (char c : s) counts[c - 'a']++;
        
        // Step 1: Base validation for odd frequencies
        int mid_char = -1, odd_count = 0;
        for (int i = 0; i < 26; ++i) {
            if (counts[i] % 2 != 0) {
                odd_count++;
                mid_char = i;
            }
        }
        if (odd_count > 1) return ""; 
        
        int half_len = n / 2;
        string prefix = "";
        vector<vector<int>> snapshots;
        bool perfectly_matched = true;
        
        // Step 2: Try to match the target prefix exactly
        for (int i = 0; i < half_len; ++i) {
            snapshots.push_back(counts); // Store inventory snapshot BEFORE choosing char i
            int target_idx = target[i] - 'a';
            
            if (counts[target_idx] >= 2) {
                prefix.push_back(target[i]);
                counts[target_idx] -= 2;
            } else {
                perfectly_matched = false;
                break;
            }
        }
        
        // Case A: Agar full half perfectly match ho gaya, fill remainder and evaluate
        if (perfectly_matched) {
            string cand = tryBuild(prefix, counts, mid_char);
            if (cand > target) return cand;
        }
        
        // Case B: Agar candidate target se bada nahi bana, ya break hua toh rollback/backtrack loop chalega
        // Hum maximum possible length se start karenge jo construct hui thi (curr_len)
        int curr_len = snapshots.size(); 
        for (int i = curr_len - 1; i >= 0; --i) {
            // Restore inventory to the exact state BEFORE making the choice at index i
            counts = snapshots[i];
            
            // Agar pehle kuch characters push hue the prefix mein, unko balance out karo length maintain karne ke liye
            if (prefix.size() > i) {
                prefix.pop_back();
            }
            
            int target_idx = target[i] - 'a';
            // Index i par target character se BADA character search karo
            for (int c = target_idx + 1; c < 26; ++c) {
                if (counts[c] >= 2) {
                    prefix.push_back((char)('a' + c));
                    counts[c] -= 2;
                    return tryBuild(prefix, counts, mid_char); // Found the smallest greater permutation!
                }
            }
        }
        
        return ""; 
    }
};
