class Solution {
public:
    unordered_map<char,vector<char>>m1={
        {'2',{'a','b','c'}},
        {'3',{'d','e','f'}},
        {'4',{'g','h','i'}},
        {'5',{'j','k','l'}},
        {'6',{'m','n','o'}},
        {'7',{'p','q','r','s'}},
        {'8',{'t','u','v'}},
        {'9',{'w','x','y','z'}}
    };
    vector<string> res;
    void rec(string& digits , int pos,string& path){
        if(pos==digits.size()){
            res.push_back(path);
            return;
        }
        
            for(char c:m1[digits[pos]]){
                path.push_back(c);
                rec(digits,pos+1,path);
                path.pop_back();
            }
        
    }
    vector<string> letterCombinations(string digits) {
        string path;
        if(digits.size()==0)return res;
        rec(digits,0,path);
        return res;
    }
};
