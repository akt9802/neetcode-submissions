class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // time complexity allowed : O(nlogn)

        // edge case
        if(nums.size() == 0){
            return false;
        }

        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]){
                return true;
            }
        }
        return false;
    }
};