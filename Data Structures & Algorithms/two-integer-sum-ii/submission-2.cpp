class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left =0 ;
        int right = numbers.size()-1;
        vector<int> result;

        while(left<right){
            if(numbers[left]+numbers[right]>target){
                right--;
            }
            if(numbers[left]+numbers[right]<target){
                left++;
            }
            if(numbers[left]+numbers[right]==target){
                right++;
                left++;
                result.push_back(left);
                result.push_back(right);
                return result;
            }
        }
        return result;
    }
};
