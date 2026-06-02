class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int res = 0;

        for (int num : s){
            if (s.find(num-1) == s.end()){

                int current = num;
                int temp = 0;
                
                while (s.find(current) != s.end()){
                    current++;
                    temp++;
                    res = max(res, temp);
                }

            }

        }
        return res;
    }
};
