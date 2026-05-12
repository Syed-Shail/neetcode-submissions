class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int length =0 ;

        unordered_set<int> set1(nums.begin(),nums.end());

        for(int num : set1){
            if(set1.find(num-1)==set1.end()){
                int big = 1;
                while(set1.find(num+big)!=set1.end()){
                    big++;

                }

                length = max(length,big);
            }
        }
        return length;
    }
};
