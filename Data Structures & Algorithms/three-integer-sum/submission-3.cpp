class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j, k;
        vector<vector<int>> triplets;
        while(i < n-2) {
            if(nums[i] > 0)
                break;
            j = i + 1;
            k = n - 1;
            while(j < k) {
                if(nums[i] + nums[j] + nums[k] == 0) {
                    triplets.push_back({nums[i], nums[j], nums[k]});
                    while(j < k && nums[j] == nums[j+1])
                        ++j;
                    ++j;
                    while(j < k && nums[k-1] == nums[k])
                        --k;
                    --k;
                } else if (nums[i] + nums[j] + nums[k] < 0) {
                    while(j < k && nums[j] == nums[j+1])
                        ++j;
                    ++j;
                } else {
                    while(j < k && nums[k-1] == nums[k])
                        --k;
                    --k;
                }
            }
            while(i < n-2 && nums[i] == nums[i+1])
                i++;
            i++;
        }
        return triplets;
    }
};
