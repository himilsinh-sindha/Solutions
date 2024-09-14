class Solution {
public:
    bool isValid(string s) {
        stack<char> ans;
        for(int i=0;i<s.size();i++){
            if(s[i]==')' || s[i]==']' || s[i]=='}'){
               if(ans.empty()) return false;
            }
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                ans.push(s[i]);
            }
            else if(!ans.empty()){
                if(s[i]==')' && ans.top()=='('){
                ans.pop();
            }
            else if(s[i]==')' && ans.top()!='('){
                return false;
            }
            else if(s[i]==']' && ans.top()=='['){
                ans.pop();
            }
            else if(s[i]==']' && ans.top()!=']'){
                return false;
            }
            else if(s[i]=='}' && ans.top()=='{'){
                ans.pop();
            }
            else if(s[i]=='}' && ans.top()!='{'){
                return false;
            }
            }
        }
        return ans.empty();
    }
};