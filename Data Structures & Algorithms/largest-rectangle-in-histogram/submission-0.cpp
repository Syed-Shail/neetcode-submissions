class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> stk;
        int res=0;

        for(int i=0 ; i<heights.size();i++){
            
            while(!stk.empty()&& heights[i]<heights[stk.top()]){
                int height = heights[stk.top()];
                stk.pop();
                int width ;
                if(stk.empty()){
                    width=i;
                }
                else{
                    width = i-stk.top()-1;
                }
                res = max(res,height*width);

            }

            stk.push(i);
        }
        return res;

    }
};
