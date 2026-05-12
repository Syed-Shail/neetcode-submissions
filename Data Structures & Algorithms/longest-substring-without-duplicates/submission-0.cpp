class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l =0;
        int r =1;
        int sum =0;
        unordered_set<char> set1;
        for(r=0;r<s.size();r++){
            
        while(set1.find(s[r])!=set1.end()){
            set1.erase(s[l]);
            l++;
        }
        set1.insert(s[r]);
        sum = max(sum,r-l+1);
        }
        return sum;
    }
};
