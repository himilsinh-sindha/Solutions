class Solution {
public:
    int solve(int start,string&s,unordered_set<string>&st){
        if(start==s.size()) return 0;
        int mSplit = 0;
        for(int i=start+1;i<=s.size();i++){
           string sub = s.substr(start,i-start);
           if(st.find(sub)==st.end()){
            st.insert(sub);
            mSplit = max(mSplit,1+solve(i,s,st));
            st.erase(sub);
           }
        }

        return mSplit;
    }


    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        return solve(0,s,st);
    }
};