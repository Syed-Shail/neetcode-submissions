class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        
        for (char c : s) {
            // Push opening brackets onto the stack
            if (c == '(' || c == '[' || c == '{') {
                s1.push(c);
            }
            // For closing brackets, check if the top of the stack matches the corresponding opening bracket
            else if (c == ')' || c == ']' || c == '}') {
                // If the stack is empty or the top does not match, return false
                if (s1.empty() || 
                    (c == ')' && s1.top() != '(') ||
                    (c == ']' && s1.top() != '[') ||
                    (c == '}' && s1.top() != '{')) {
                    return false;
                }
                // Pop the matched opening bracket
                s1.pop();
            }
        }
        
        // If the stack is empty, all opening brackets were properly matched
        return s1.empty();
    }
};
