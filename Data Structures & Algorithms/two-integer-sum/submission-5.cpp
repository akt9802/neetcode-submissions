class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // we have to return indices so sorting is not option 
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(i!=j){
                    if(nums[i]+nums[j]==target){
                        return {i,j};
                    }
                }
            }
        }
        return {-1,-1};
    }
};
