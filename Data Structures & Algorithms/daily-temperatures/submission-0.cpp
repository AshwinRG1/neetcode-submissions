class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res;
        for (int i = 0; i < temperatures.size(); i++){
            bool found = false;
            for (int j = i + 1; j < temperatures.size(); j++){
                if (temperatures[j] > temperatures[i]){
                    res.push_back(j - i);
                    found = true;
                    break;
                }
            }
            if (!found){
                res.push_back(0);
            }
        }
        return res;
    }
};
