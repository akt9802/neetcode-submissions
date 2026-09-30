class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // we can use set of size k
        int left = 0;
        int right = 0;
        set<int> st;
        while(right<nums.size()){
            if(right-left > k){
                st.erase(nums[left]);
                left++;
            }
            if(st.find(nums[right])!=st.end() && right!=left){
                return true;
            }
            st.insert(nums[right]);
            right++;
        }
        return false;
    }
};