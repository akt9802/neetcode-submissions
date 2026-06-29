class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // think map of fixed size(if possible)
        // answer will be lie in rage 1 to n+1 (n is size of array)

        int n = nums.size();
        for(int i=0;i<n;i++){
            while(nums[i]>0 && nums[i]<=n && nums[i]!=i+1){
                //handle duplicate
                if(nums[nums[i]-1]==nums[i]) break;
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=(i+1)) return i+1;
        }
        return n+1;
    }
};