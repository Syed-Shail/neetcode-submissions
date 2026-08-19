class Solution {
public:
    int lin(vector<int>& nums, int l , int r){
        int n = nums.size();
        vector<int>dp(r-l);
        dp[0]=nums[l];
        if(r-l>1)dp[1]=max(nums[l+1],nums[l]);
        for(int i = 2 ; i<r-l ; i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[l+i]);
        }
        return dp[r-l-1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        if(n==1)return nums[0];
        return max(lin(nums,0,n-1),lin(nums,1,n));
    }
};
