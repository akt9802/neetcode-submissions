class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> numsPrefix(n,1);
        vector<int> numsSuffix(n,1);

        int temp = nums[0];
        for(int i=1;i<n;i++){   
            numsPrefix[i] = temp;
            temp *= nums[i];
        }

        temp = nums[n-1];
        for(int i=n-2;i>=0;i--){
            numsSuffix[i] = temp;
            temp *= nums[i];
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(numsPrefix[i]*numsSuffix[i]);
        }
        return ans;
    }
};
