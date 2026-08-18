class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> st;
        int i = 0;
        int j = 0;
        while(j<nums.size()){
            if(j-i<=k){
                if(st.find(nums[j]) != st.end()){
                    return true;
                }else{
                    st.insert(nums[j]);
                    j++;
                }
            }else{
                st.erase(nums[i]);
                i++;
            }
        }
        return false;
    }
};