class Solution {
public:
    int t[51];

    int solve(int i,string& s,unordered_set<string>&st,int&n){
        if(i>=n) return 0;

        if(t[i]!=-1){
            return t[i];
        }

        int result = 1+solve(i+1,s,st,n);

        for(int j=i;j<n;j++){
            string curr = s.substr(i,j-i+1);
            if(st.count(curr)){
                result = min(result,solve(j+1,s,st,n));
            }
        }

        return t[i]=result;
    }
    int minExtraChar(string s, vector<string>& d) {
        int n = s.size();
        memset(t,-1,sizeof(t));

        unordered_set<string> st(d.begin(),d.end());

        return solve(0,s,st,n);
    }
};