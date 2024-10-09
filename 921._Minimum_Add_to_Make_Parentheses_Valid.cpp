class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st; // Stack to keep track of unmatched parentheses
        
        // Traverse each character in the string
        for (auto i : s) {
            // If the stack is not empty and the top is an opening parenthesis '('
            // and the current character is a closing parenthesis ')',
            // then we have a valid pair, so we pop the stack.
            if (!st.empty() && st.top() == '(' && i == ')') {
                st.pop();
            } 
            // Otherwise, push the current parenthesis onto the stack.
            // It will either be an unmatched opening parenthesis '('
            // or an unmatched closing parenthesis ')'.
            else {
                st.push(i);
            }
        }

        // The size of the stack represents the number of unmatched parentheses.
        // This is the minimum number of parentheses we need to add to make the string valid.
        return st.size();
    }
};
