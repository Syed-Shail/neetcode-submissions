class Solution {
public:

    int bs(int high , int low , vector<int>& nums , int target){
        if(low>high){
            return -1;
        }
        int mid = (high+low)/2;
        if(target>nums[mid]){
           return bs(high,mid+1,nums,target);
        }
        if(target<nums[mid]){
            return bs(mid-1,low,nums,target);
        }
        if(target==nums[mid]){
            return mid;
        }
    }
    int search(vector<int>& nums, int target) {
        
        int res = bs(nums.size()-1, 0 , nums ,target);
        return res;


    }
};
