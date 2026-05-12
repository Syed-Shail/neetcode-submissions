class Solution {
public:
    vector<vector<int>> res;
    void bt(vector<int>& nums,vector<int>& path,vector<bool>& used){
        if(path.size()==nums.size()){
            res.push_back(path);
            return;
        }
        for(int i=0 ; i<nums.size();i++){
            if(used[i]==true)continue;
            used[i]= true;
            path.push_back(nums[i]);
            bt(nums,path,used);
            used[i]=false;
            path.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        vector<bool> used(nums.size(),false);
        bt(nums,path,used);
        return res;
    }
};
