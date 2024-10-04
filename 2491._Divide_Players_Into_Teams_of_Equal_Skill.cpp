class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        long long sum = 0;

        int left = 0;
        int right = skill.size()-1;

        unordered_map<int,int> m;
        int tskill = skill[left]+skill[right];
        while(left<right){
            if(skill[left]+skill[right]!=tskill){
                return -1;
            }

            m[skill[left]]=skill[right];
            sum+=skill[left]*skill[right];

            left++;
            right--;
        }

        return sum;
    }
};