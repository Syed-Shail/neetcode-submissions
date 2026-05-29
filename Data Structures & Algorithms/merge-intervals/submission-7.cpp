class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& ints) {
        vector<vector<int>> res;
        sort(ints.begin(),ints.end());
        res.push_back(ints[0]);
        for(int i=1 ; i<ints.size() ; i++){
            if(res.back()[1]>=ints[i][0]){
                if(res.back()[1]>=ints[i][1]){}
                else{res.back()[1]=ints[i][1];}
            }
            else{
                res.push_back(ints[i]);
            }
        }
        return res;
    }
};
