class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // we have to write algo in O(n) time complexity
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int ansCount = 0;
        for(int i=0;i<nums.size();i++){
            int value = nums[i];
            int temp = 0;
            while(mpp.find(value)!= mpp.end()){
                value--;
            }
            value++;
            while(mpp.find(value)!=mpp.end()){
                temp++;
                value++;
            }
            ansCount = max(ansCount,temp);
        }
        return ansCount;
    }
};
