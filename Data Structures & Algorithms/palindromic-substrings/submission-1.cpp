class Solution {
public:
    void exp(string &s , int l , int r , int &count){
        while(l>=0 && r<s.size() && s[l]==s[r]){
            count++;
            l--;
            r++;
        }
    }

    int countSubstrings(string s) {
        int count =0;
        for(int i=0 ; i<s.size() ; i++){
            exp(s,i,i,count);
            exp(s,i,i+1,count);
        }
        return count;
    }
};
