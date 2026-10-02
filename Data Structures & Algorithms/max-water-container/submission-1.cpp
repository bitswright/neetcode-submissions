class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int maxWaterStorable = 0, waterStorable, leastHeight;
        int l = 0, r = n-1;
        while(l < r) {
            leastHeight = min(heights[l], heights[r]);
            waterStorable = leastHeight * (r - l);
            maxWaterStorable = max(maxWaterStorable, waterStorable);
            while(l < r && heights[l] <= leastHeight)
                ++l;
            while(l < r && heights[r] <= leastHeight)
                --r;
        }
        return maxWaterStorable;
    }
};
