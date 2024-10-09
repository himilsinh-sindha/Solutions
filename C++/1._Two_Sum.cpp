class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i=0;i<=size(nums)-1;i++){
            for(int j=i+1;j<=size(nums)-1;j++)
            
            if(nums[i]+nums[j]==target){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
        return ans;
    }
};