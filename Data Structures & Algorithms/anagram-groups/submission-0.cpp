class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string,vector<string>> map1;
        for(string s: strs){
            string key =s;
            sort(key.begin(),key.end());
            map1[key].push_back(s);
        }
        vector<vector<string>> result;

        for(auto& pair: map1){
            result.push_back(pair.second);
        }
        return result;
    }
};
