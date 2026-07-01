class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sorting array => O(nlogn)
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<nums.size()-2;i++){
            // we didn't handle duplicate here, lets handle dublicate here
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }

            int j = i+1;
            int k = n-1;

            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum > 0){
                    k--;
                }else if(sum < 0){
                    j++;
                }else{
                    // sum == 0
                    ans.push_back({nums[i],nums[j],nums[k]});

                    while(j<k && nums[j]==nums[j+1]){
                        j++;
                    }
                    while(j<k && nums[k]==nums[k-1]){
                        k--;
                    }
                    j++;
                    k--;
                }
            }
        }
        return ans;
    }
};
