class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i){
            for (int j = i; j < nums.size(); ++j){
                if ((nums[i] == nums[j]) && (i != j)){
                    res = nums[i];
                }
            }
        }
        return res;
    }
};
