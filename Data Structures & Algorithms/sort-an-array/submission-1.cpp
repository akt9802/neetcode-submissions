class Solution {
   public:
    void quickSort(vector<int>& nums, int low, int high) {
        // recurssive function
        if (low < high) {
            int partitionIndex = partition(nums, low, high);
            quickSort(nums, low, partitionIndex - 1);
            quickSort(nums, partitionIndex + 1, high);
        }
    }

    int partition(vector<int>& nums,int low,int high){
        int pivot = nums[low];
        int i=low;
        int j=high;
        while(i<j){
            while(i<high && nums[i]<=pivot){
                i++;
            }
            while(j>low && nums[j]>=pivot){
                j--;
            }

            if(i<j){
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[low],nums[j]);
        return j;
    }

    vector<int> sortArray(vector<int>& nums) {
        // applying merge sort will bring space complexity to nlogn
        // so we apply quick sort
        // TC : O(nlogn), SC : O(1)

        int n = nums.size() - 1;
        quickSort(nums, 0, n);
        return nums;
    }
};