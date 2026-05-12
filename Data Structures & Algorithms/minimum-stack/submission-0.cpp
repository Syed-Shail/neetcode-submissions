class MinStack {
public:
stack<int> stk;
stack <int> minstk;
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        if(minstk.empty() || val<=minstk.top()){
            minstk.push(val);
        }
    }
    
    void pop() {
        if(stk.top()==minstk.top()){
            minstk.pop();
        }
        stk.pop();
    }
    
    int top() {
       return stk.top();
    }
    
    int getMin() {
        return minstk.top();
    }
};
