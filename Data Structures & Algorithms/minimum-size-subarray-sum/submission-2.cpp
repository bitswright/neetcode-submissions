class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;
        int n = nums.size();
        int sum = 0, minLen = INT_MAX;
        while(r < n) {
            sum += nums[r];
            if(sum >= target) {
                while(sum >= target) {
                    sum -= nums[l++];
                }
                minLen = min(minLen, r - l + 2);
            }
            r++;
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};
