class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;

        unordered_map<char,int> map1;

        for(int i=0; i<s.size();i++){
            map1[s[i]]++;
            map1[t[i]]--;
        }

        for(auto &pair:map1){
            if(pair.second!=0){
                return false;
            }
        }
        return true;
    }
};
