class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // we can't sort it
        // brute force: check for every subarray(not optimal)]

        // maybe we can go for sliding window
        int minLen = INT_MAX;
        int left = 0;
        int right = 0;
        int tempSum = 0;
        while(right<nums.size()){
            tempSum += nums[right];
            while(tempSum >= target){
                minLen = min(minLen,right-left+1);
                tempSum -= nums[left];
                left++;
                
            }
            right++;
        }
        if(minLen == INT_MAX){
            return 0;
        }
        return minLen;

    }
};