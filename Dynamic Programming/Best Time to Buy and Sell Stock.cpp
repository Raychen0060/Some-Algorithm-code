class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_p=prices[0];
        int profit,max_pro=0;
        for(int i=0;i<prices.size();++i){
            if(min_p>prices[i]){
                min_p=prices[i];
            }
            else{
                profit=prices[i]-min_p;
            }
            max_pro=max(profit,max_pro);
        }
        return max_pro;
    }
};
