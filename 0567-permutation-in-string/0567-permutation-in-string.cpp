class Solution {
public:
    bool isEqual(vector<int>& s1Freq, vector<int>& windowFreq) {

        for (int i = 0; i < 26; i++) {

            if (s1Freq[i] != windowFreq[i])
                return false;
        }

        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if (n > m)
            return false;

        vector<int> s1Freq(26, 0);
        vector<int> windowFreq(26, 0);

        // Frequency of s1
        for (char ch : s1)
            s1Freq[ch - 'a']++;

        // First window
        for (int i = 0; i < n; i++)
            windowFreq[s2[i] - 'a']++;

        // Check first window
        if (isEqual(s1Freq, windowFreq))
            return true;

        // Slide the window
        for (int i = n; i < m; i++) {

            // Add new character
            windowFreq[s2[i] - 'a']++;

            // Remove leftmost character
            windowFreq[s2[i - n] - 'a']--;

            // Compare frequencies
            if (isEqual(s1Freq, windowFreq))
                return true;
        }

        return false;
    }
};