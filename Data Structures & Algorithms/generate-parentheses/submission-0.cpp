class Solution {
public:


    void bcktrk(int nopen , int nclose , int n , vector<string>& res , string& stack)
    {
        if(nopen == nclose && nopen == n){
            res.push_back(stack);
            return ;
        }


        if(nopen<n){
            stack+= '(';
            bcktrk(nopen +1 , nclose , n , res, stack);
            stack.pop_back();
        }

        if(nclose<nopen){
            stack+=')';
            bcktrk(nopen,nclose+1, n , res,stack);
            stack.pop_back();
        }

    }


    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string stack;
        bcktrk(0,0,n,res,stack);
        return res;
    }
};
