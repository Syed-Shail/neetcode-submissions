class Solution {
public:
    stack <int> stk;
    int evalRPN(vector<string>& tokens) {
        for(string s : tokens){
            if(s=="+"){
                int temp1 =  stk.top();
                stk.pop();
                int temp2 = stk.top();
                stk.pop();
                stk.push(temp1+temp2);
            }
          else  if(s=="-"){
                int temp1 = stk.top();
                stk.pop();
                int temp2 = stk.top();
                stk.pop();
                stk.push(temp2-temp1);
            }
           else if(s=="*"){
                int temp1 = stk.top();
                stk.pop();
                int temp2 = stk.top();
                stk.pop();
                stk.push(temp2*temp1);
            }
           else if(s=="/"){
                int temp1 = stk.top();
                stk.pop();
                int temp2 = stk.top();
                stk.pop();
                stk.push(temp2/temp1);
            }
            else{
                stk.push(stoi(s));
            }
        }
        return stk.top();
    }
};
