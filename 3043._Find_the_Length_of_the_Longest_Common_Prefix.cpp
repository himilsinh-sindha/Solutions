class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,int> prefixMap;
        for(auto i:arr1){
            string t = to_string(i);
            string prefix = "";
            for(auto j:t){
                prefix+=j;
                prefixMap[prefix]++;
            }
        }

        int maxLen = 0;

        for(auto i:arr2){
            string t = to_string(i);
            string prefix = "";
            for(auto j:t){
                prefix+=j;
                if(prefixMap.find(prefix)!=prefixMap.end()){
                    int size = prefix.size();
                    maxLen = max(maxLen,size);
                }
            }
        }

        return maxLen;
    }
};
