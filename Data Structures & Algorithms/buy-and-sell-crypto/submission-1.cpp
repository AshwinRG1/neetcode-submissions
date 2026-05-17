class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mP = 0;
        int tP = 0;

        for (int i = 0; i < prices.size(); i++){
            for (int j = i + 1; j < prices.size(); j++){

                tP = prices.at(j) - prices.at(i);

                if (tP > mP){
                    mP = tP;
                }
            }
        }


        return mP; 
    }
};
