class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int small = INT_MAX;
        int res =0;
        for(int i : prices){
            small = min(i,small);
            res = max(res,i-small);
        }
        return res;
    }
};
