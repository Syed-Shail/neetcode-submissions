class Solution {
public:
    vector<vector<int>> res;
    void rec(vector<int>& nums, int start , int sum , vector<int>& path){
        if(sum<0) return;
        if(sum==0){
            res.push_back(path);
            return;
        }
        for(int i= start; i<nums.size();i++){
            path.push_back(nums[i]);
            rec(nums,i,sum-nums[i],path);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> path;
        rec(nums,0,target,path);
        return res;
    }
};
