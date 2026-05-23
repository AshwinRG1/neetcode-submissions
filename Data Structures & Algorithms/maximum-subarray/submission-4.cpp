class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp = nums;

        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++){
            dp[i] = max(dp[i-1] + dp[i], dp[i]);
        }
        return max(dp);
    }
};
