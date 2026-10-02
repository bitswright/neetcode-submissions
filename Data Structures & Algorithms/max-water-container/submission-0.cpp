class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int maxWaterStorable = 0, waterStorable;
        int l = 0, r = n-1;
        while(l < r) {
            waterStorable = min(heights[l], heights[r]) * (r - l);
            maxWaterStorable = max(maxWaterStorable, waterStorable);
            if(heights[l] < heights[r])
                l++;
            else
                r--;
        }
        return maxWaterStorable;
    }
};
