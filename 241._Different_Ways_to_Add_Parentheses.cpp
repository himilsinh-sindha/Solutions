class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        for(int i=0;i<expression.size();i++){
            char c = expression[i];
            if(c=='+' || c=='-' || c=='*'){
                string a = expression.substr(0,i);
                string b = expression.substr(i+1);
                vector<int> x = diffWaysToCompute(a);
                vector<int> y = diffWaysToCompute(b);
                for(auto j:x){
                    for(auto k:y){
                        if(c=='+') ans.push_back(j+k);
                        else if(c=='-') ans.push_back(j-k);
                        else ans.push_back(j*k);
                    }
                }
            }
        }

        if(ans.empty()) ans.push_back(stoi(expression));

        return ans;
    }
};