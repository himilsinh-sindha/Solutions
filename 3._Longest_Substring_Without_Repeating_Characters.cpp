class Solution {
public:
    int lengthOfLongestSubstring(string s) { 
        int hash[256];
        fill(begin(hash), end(hash), -1);

        int left=0;
        int right=0;
        int maxLen=0;
        int n = s.size();
        while(right<n){
            if(hash[s[right]]!=-1){
                if(hash[s[right]]>=left){
                    left=hash[s[right]]+1;
                }
            }
            maxLen = max(maxLen,right-left+1);
            hash[s[right]]=right;
            right++;
        }

        return maxLen;
    }
};