class Solution {
public:
    void bcktrk(int ind , int target , vector<int>& path ,  vector<vector<int>>& res, vector<int>& nums){
        if(target==0){
            res.push_back(path);
            return;
        }
        for(int i= ind ; i<nums.size() ; i++){
            if(i>ind && nums[i]==nums[i-1])continue;
            if(nums[i]>target)break;
            path.push_back(nums[i]);
            bcktrk(i+1,target-nums[i],path,res,nums);
            path.pop_back();
        }
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>res;
        vector<int> path;
        bcktrk(0,target,path,res,candidates);
        return res;
    }
};
