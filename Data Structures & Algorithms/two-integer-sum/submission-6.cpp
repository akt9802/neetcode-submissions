class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // we can use hash map 
        map<int,int> mpp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int temp = target - nums[i];
            if(mpp.find(temp) != mpp.end()){
                return {mpp[temp],i};
            }
            mpp[nums[i]] = i;
        }
        return {-1,-1};
    }
};
