class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // two pointers 
        int i=0;
        int count = 1;
        for(int j=1;j<nums.size();j++){
            if(nums[i]!=nums[j]){
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i+1; 

    }
};