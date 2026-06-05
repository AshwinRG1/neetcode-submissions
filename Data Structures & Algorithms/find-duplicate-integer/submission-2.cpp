class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> seen;
        for (auto num : nums){
            if (seen.find(num) == seen.end()){
                seen.insert(num);
            } else {
                return num;
            }
        }
    }
};
