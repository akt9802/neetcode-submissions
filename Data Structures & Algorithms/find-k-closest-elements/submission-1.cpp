class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // Because the array is sorted, the k closest elements will always form a contiguous subarray

        int left = 0;
        int right = arr.size()-1;
        int requiredElementToRemove = arr.size()-k;
        while(requiredElementToRemove > 0){
            if(abs(arr[left]-x)<=abs(arr[right]-x)){
                right--;
            }else{
                left++;
            }
            requiredElementToRemove--;
        }
        vector<int>ans;
        for(int i=left;i<=right;i++){
            ans.push_back(arr[i]);
        }
        return ans;

    }
};