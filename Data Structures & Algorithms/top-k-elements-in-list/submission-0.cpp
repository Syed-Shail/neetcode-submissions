class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int , int> map1;
        vector<vector<int>> freq(nums.size()+1);

        for(int n : nums){
            map1[n]= 1+map1[n];
        }

        for(const auto& pair : map1){
        
            freq[pair.second].push_back(pair.first);
        }
        vector<int> res;
        for(int i=freq.size()-1; i>0;i--){
            for(int n: freq[i])
            res.push_back(n);
            if(res.size()==k){
                return res;
            }
        }
    return res;

    }
};
