class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0]; /// fisrt wala min declare 
        int maxp=0;

        for (int i = 1; i < prices.size(); i++) { //min se last tak loop
            if (prices[i] < minPrice) {   //if min se koi chotta hai then update
                minPrice = prices[i];
            } else {
                maxp = max(maxp,prices[i] - minPrice);  //if not then maxprofit nikal lo
            }
        }

        return maxp;
    }
};