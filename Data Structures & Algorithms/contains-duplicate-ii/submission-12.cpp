class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // we can use set of size k
        set<int> st;
        int left = 0;
        int right = 0;
        while(right<nums.size()){
            if(st.size()>k){
                st.erase(nums[left]);
                left++;
            }
            if(st.find(nums[right]) != st.end()){
                return true;
            }

            st.insert(nums[right]);
            right++;
        }
        return false;
        
    }
};