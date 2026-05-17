class Solution {
public:
    string exp(string & s , int l , int r){
        while(l>=0 && r<s.size() && s[l]==s[r]){
            l--;
            r++;
        }
        return s.substr(l+1,r-l-1);
    }

    string longestPalindrome(string s) {
        string ans = "";

        for(int i=0 ; i < s.size(); i++){
            string odd = exp(s,i,i);
            string even = exp(s,i,i+1);

            if(odd.size()>ans.size()){
                ans=odd;
            }
            if(even.size()>ans.size()){
                ans=even;
            }
        }
        return ans;
    }
};
