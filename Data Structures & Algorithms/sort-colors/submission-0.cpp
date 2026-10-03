class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int c = 0, l = 0, r = n - 1;
        while(c <= r) {
            if(nums[c] == 0) {
                swap(nums[l++], nums[c++]);
            } else if(nums[c] == 1) {
                c++;
            } else {
                swap(nums[c], nums[r--]);
            }
        }
    }
};
