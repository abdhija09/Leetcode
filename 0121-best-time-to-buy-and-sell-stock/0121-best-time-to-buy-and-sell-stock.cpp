
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;

        int ans = 0;         
        int mine = prices[0]; 

        for(int i = 1; i < prices.size(); i++) {
            
            int profit = prices[i] - mine;
            ans = max(ans, profit);

            mine = min(mine, prices[i]);
        }

        return ans;
    }
};