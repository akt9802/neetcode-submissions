class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // brute force check all subarrays
        // int count = 0;
        // int n = nums.size();
        // for(int i=0;i<n;i++){
        //     int sum = 0;
        //     for(int j=i;j<nums.size();j++){
        //         sum += nums[j];
        //         if(sum == k){
        //             count++;
        //         }
        //     }
        // }
        // return count;

        // can we use map or prefix sum
        map<int,int> mpp;
        // if subarray starts from O, then for that condition we write mpp[0] = 1
        mpp[0] = 1;
        int count = 0;
        int prefixSum = 0;
        for(int i=0;i<nums.size();i++){
            prefixSum += nums[i];
            if(mpp.find(prefixSum - k) != mpp.end()){
                count += mpp[prefixSum-k];
            }
            mpp[prefixSum]++;
        }
        return count;
    }
};