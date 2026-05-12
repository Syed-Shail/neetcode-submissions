class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        vector<int> res;
        
        for(int i =0 ; i<temperatures.size(); i++){
          int count =1;
          int flag =0;
        for(int j=i+1 ; j<temperatures.size(); j++){
            if(temperatures[i]<temperatures[j]){
                res.push_back(count);
                flag =1;
                break;
            }
            else{
                count++;
            }
        }
        if (flag ==0){
            res.push_back(0);
        }
    }
    return res;
    }
};
