class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int , vector<int> , greater<int>> hip;

        for(int i=0 ; i<nums.size();i++){
            if(hip.size()<k){
                hip.push(nums[i]);
            }
            else if(nums[i]>hip.top()){
                hip.pop();
                hip.push(nums[i]);
            }
        }
        return hip.top();
    }
};
