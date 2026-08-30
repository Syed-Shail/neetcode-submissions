class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum =0;
        for(int num :  nums)sum+=num;
        int target = sum/2;
        if(sum%2!=0)return false;
        int n = nums.size();
        vector<bool> dp(target+1,false);
        dp[0]=true;
        for(int i : nums){
            for(int s=target ; s>=i ; s--){
                dp[s]=dp[s] || dp[s-i];
            }
        }
        return dp[target];
    }
};
