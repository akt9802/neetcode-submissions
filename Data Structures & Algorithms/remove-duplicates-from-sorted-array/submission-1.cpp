class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 1;
        int n = nums.size();
        int countAns = 1;
        while(j<n){
            if(nums[j]!=nums[i]){
                countAns++;
                nums[i+1] = nums[j];
                i++;
            }
            j++;
        }
        return countAns;
    }
};