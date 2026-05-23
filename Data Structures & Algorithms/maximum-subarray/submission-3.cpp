class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp = nums;
        int best = nums[0];

        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++){
            dp[i] = max(dp[i-1] + dp[i], dp[i]);
            best = max(best, dp[i]);
        }
        return best;
    }
};
