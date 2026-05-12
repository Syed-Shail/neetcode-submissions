class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());

        while(l<r){
            int k = (l+r)/2;
            int totaltime =0;

            for(auto p : piles){
                totaltime+=(p+k-1)/k;
            }

            if(totaltime<=h){
                r=k;
            }
            else{
                l=k+1;
            }

        }
        return l;
    }
};
