class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i = 1 ; i<intervals.size() ; i++){
            if(res.back()[1]>intervals[i][0]){
                // Overlap detected: Skip this interval (greedy removal)
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return intervals.size()-res.size();
    }
};