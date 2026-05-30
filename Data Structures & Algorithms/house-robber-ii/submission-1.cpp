class Solution {
    int robInternal(vector<int>& nums, int s, int e) {
        vector<vector<int>> dp(e-s, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = nums[s];
        for(int i = 1; i < e-s; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + nums[i+s];
        }
        return max(dp[e-s-1][0], dp[e-s-1][1]);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        return max(
            robInternal(nums, 0, n-1), 
            robInternal(nums, 1, n)
        );
    }
};
