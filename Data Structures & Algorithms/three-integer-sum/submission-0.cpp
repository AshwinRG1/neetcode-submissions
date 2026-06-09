class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (size_t i = 0; i < nums.size() - 1; ++i){
            
            int l = i + 1;
            int r = nums.size() - 1;
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            while (r > l){
                if (nums[i] + nums[l] + nums[r] == 0){
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                } 
                else if (nums[i] + nums[l] + nums[r] > 0){
                    r--;
                } else {
                    l++;
                }
            }
        }


        return res;


    }
};
