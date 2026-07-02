class Solution {
public:
vector<vector<string>> res;

    bool part(string& s , int l , int r){
        while(l<r){
            if(s[l]==s[r]){
                l++;
                r--;
            }
            else{
                return false;
            }
        }
        return true;
    }

    void bcktrk(string& s , int start , vector<string>& path){
        if(start==s.size()){
            res.push_back(path);
            return;
        }

        for(int end = start ; end<s.size() ; end++){
            if(part(s,start,end)){
                path.push_back(s.substr(start,end-start+1));
                bcktrk(s,end +1,path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> path;
        bcktrk(s,0,path);
        return res;
    }
};
