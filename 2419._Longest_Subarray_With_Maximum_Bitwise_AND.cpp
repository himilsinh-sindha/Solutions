class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int maxLen=0;
        int cnt=0;
        for(auto i:nums){
            if(i==maxi){
                cnt++;
                maxLen = max(maxLen,cnt);
            }
            else{
                cnt=0;
            }
        }

        return maxLen;
    }
};