class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int left = 0;
        int right = arr.size()-1;
        int requiredElementToRemove = arr.size()-k;
        while(requiredElementToRemove > 0){
            if(abs(x-arr[left])<=abs(x-arr[right])){
                right--;
            }else{
                left++;
            }
            requiredElementToRemove--;
        }
        for(int i=left;i<=right;i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};