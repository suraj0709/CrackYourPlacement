class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lsf = INT_MAX;
        int ptt = 0;
        int op = 0;

        for(int i=0; i<prices.size(); i++){
            if(prices[i] < lsf)
                lsf = prices[i];
            ptt = prices[i] - lsf;
            if(op < ptt)
                op = ptt;
        }
        return op;
    }
};
