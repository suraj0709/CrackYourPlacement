class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int least = INT_MAX;
        int ptt = 0;
        int pp = 0;
        int op = 0;

        for(int i=0; i<prices.size(); i++){
            if(prices[i] < least)
                least = prices[i];
            
            ptt = prices[i] - least;

            if(pp < ptt)
                pp = ptt;
            else{
                least = prices[i];
                op += pp;
                pp = 0;
            }
        }
        if(pp != 0) op += pp;
        return op;
    }
};
