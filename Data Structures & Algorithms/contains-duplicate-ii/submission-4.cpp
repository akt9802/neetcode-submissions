class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // we can't sort this question because index is involved
        // when we are stading at a particular index we must think that we 
        // only need to consider previous k elements

        // set
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            if(st.count(nums[i])){
                return true;
            }
            
            st.insert(nums[i]);
            if(st.size() > k){
                st.erase(nums[i-k]);
            }
        }
        return false;
    }
};