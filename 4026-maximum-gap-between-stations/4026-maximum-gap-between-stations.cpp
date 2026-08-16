class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.length();
        int m = station.length();

        // Agar ek hi worker hai, toh gap hamesha 0 hoga
        if (n == 1) return 0;

        // Step 1: Left-to-Right Pass (Har worker ki sabse PEHLI matching position)
        vector<int> earliest(n);
        int stationIdx = 0;
        for (int i = 0; i < n; i++) {
            while (stationIdx < m && station[stationIdx] != skill[i]) {
                stationIdx++;
            }
            earliest[i] = stationIdx;
            stationIdx++; 
        }

        // Step 2: Right-to-Left Pass (Har worker ki sabse AAKHIRI matching position)
        vector<int> latest(n);
        stationIdx = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (stationIdx >= 0 && station[stationIdx] != skill[i]) {
                stationIdx--;
            }
            latest[i] = stationIdx;
            stationIdx--; 
        }

        // Step 3: Maximum Gap nikalna
        int max_gap = 0;
        for (int i = 1; i < n; i++) {
            int current_gap = latest[i] - earliest[i - 1];
            max_gap = max(max_gap, current_gap);
        }

        return max_gap;
    }
};
