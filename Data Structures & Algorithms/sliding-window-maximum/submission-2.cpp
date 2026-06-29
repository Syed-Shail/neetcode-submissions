class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int,int>> hip;
        for(int i=0 ; i<nums.size() ; i++){
            hip.push({nums[i],i});
            while(hip.top().second<=i-k){
                hip.pop();
            }
            if(i>=k-1){
                res.push_back(hip.top().first);
            }
        }
        return res;
    }
};
