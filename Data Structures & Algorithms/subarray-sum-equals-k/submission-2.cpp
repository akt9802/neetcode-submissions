class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // we can use map here
        map<int,int> mpp;
        mpp[0] = 1;
        int prefixSum = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            prefixSum += nums[i];
            if(mpp.find(prefixSum-k) != mpp.end()){
                count += mpp[prefixSum-k];
            }
            mpp[prefixSum]++;
        }
        return count;
    }
};