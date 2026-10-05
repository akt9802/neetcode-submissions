class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // subarray sum >=target 
        int left = 0;
        int right = 0;
        int tempSum = 0;
        int minimumSubarraylength = INT_MAX;
        while(right < nums.size()){
            tempSum += nums[right];
            while(tempSum>=target){
                minimumSubarraylength = min(minimumSubarraylength,right-left+1);
                tempSum -= nums[left];
                left++;
            }
            right++;
        }
        if(minimumSubarraylength == INT_MAX){
            return 0;
        }
        return minimumSubarraylength;
    }
};