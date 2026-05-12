class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> m1;
        for(char c : s1){
            m1[c]++;
        }
        int left =0;
        int right=0;
        int n=s2.length();
        int required = s1.length();
        while(right<n){
            if(m1[s2[right]]>0){
                required--;
            }
            m1[s2[right]]--;
            right++;
            if(required==0)return true;

            if(right-left==s1.length()){
                if (m1[s2[left]] >= 0) {
                    required++;
                }
                m1[s2[left]]++;
                left++;
            }
        }return false;
    }
};
