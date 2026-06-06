class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;

        vector<int> res;

        for (int num : nums){
            res[num]++;
        }

        for (auto iter; iter != map.end(); iter++){
            if (k == iter.second){
                res.push_back(iter.first);
            }
        }
    }
};
