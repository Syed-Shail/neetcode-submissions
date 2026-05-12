class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       unordered_set<int> s1;

       for(int i=0;i<nums.size();i++){
        int temp = nums[i];
         if(s1.find(temp)!=s1.end()){
            return true;
         }
         s1.insert(nums[i]);
       }
       return false;
    }
};
