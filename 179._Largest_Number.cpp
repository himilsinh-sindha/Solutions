class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(auto i:nums){
            v.push_back(to_string(i));
        }

        sort(v.begin(),v.end(),[](const string& a,const string& b){
            return b+a<a+b;
        });

        if(v[0]=="0") return "0";

        string ans;
        for(auto i:v){
            ans+=i;
        }

        return ans;
    }
};