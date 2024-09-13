class Solution {                        
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int> ans;
        for(int i=1;i<n;i++){
            arr[i]^=arr[i-1];
        }

        for(auto i:queries){
           int left = i[0];
           int right = i[1];
           if(left == 0 ) ans.push_back(arr[right]);
           else ans.push_back(arr[left-1]^arr[right]);
        }

        return ans;
    }
};