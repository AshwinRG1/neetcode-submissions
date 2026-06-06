class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;

        vector<int> res;

        for (int num : nums){
            res[num]++;
        }

        for (auto it; it != map.end(); it++){
            if (k == it.second){
                res.push_back(it.first);
            }
        }
    }
};
