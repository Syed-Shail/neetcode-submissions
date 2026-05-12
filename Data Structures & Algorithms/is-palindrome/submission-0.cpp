class Solution {
public:
    bool isPalindrome(string s) {
        int left , right;
        right =s.size()-1 ;
        left = 0;

        while(left<right){
            while(left<right && !alphaNum(s[left])){
                left++;
            }
             while(left<right && !alphaNum(s[right])){
                right--;
            }
            if(tolower(s[left])!=tolower(s[right])){
                return false;
            }
            right--;
            left++;
        }
        return true;

    }
     bool alphaNum(char c) {
        return (c >= 'A' && c <= 'Z' || 
                c >= 'a' && c <= 'z' || 
                c >= '0' && c <= '9');
    }
};
