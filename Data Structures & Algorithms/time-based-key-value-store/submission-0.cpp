class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> m1;

    TimeMap() {
        m1.clear();
    }
    
    void set(string key, string value, int timestamp) {
        m1[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int,string>>& vec = m1[key];
        int l =0;
        int r = vec.size()-1;
        string res ="";
        while(l<=r){
            int mid = (l+r)/2;
            if(vec[mid].first<=timestamp){
                res = vec[mid].second;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return res;
    }
};
