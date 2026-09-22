class Solution {
public:
    vector<int> constructRectangle(int area) {
        // Gap min chahiye, isliye W ko ekdum square root ke paas se shuru kiya 😎
        int w = sqrt(area);
        // Area = L * W ke hisab se L ki starting value set kar di 👍
        int l = area / w; 
        
        while (l * w != area || l < w) {
            if (l * w < area) {
                l++; // if area is smaller increase l
            } else {
                w--; // if length L < W , decrease W
            }
        }
        
        return {l, w};
    }
};