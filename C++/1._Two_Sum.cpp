class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            int a = nums[i];
            int req= target - a;
            if(m.find(req)!=m.end()){
                return {m[req],i};
            }
            m[a]=i;
        }

        return nums;
    }
};