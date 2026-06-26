class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        int ans = 0;
        for(int k=0;k<nums.size();k++){
            if(nums[k] != val){
                swap(nums[i],nums[k]);
                i++;
                ans++;
            }
        }
        return ans;
    }
};