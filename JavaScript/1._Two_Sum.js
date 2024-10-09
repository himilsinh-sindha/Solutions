/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    for(let i=0;i<nums.length;i++){
        let req = target - nums[i];
        let index = nums.indexOf(req);
        if(index!==-1 && index!==i){
            return [i,index];
        }
    }
};