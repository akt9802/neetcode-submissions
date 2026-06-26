class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int maxi = 0;
        int ans = 0;
        for(auto m:mpp){
            if(m.second > maxi){
                maxi = m.second;
                ans = m.first;
            }
        }
        return ans;
    }
};