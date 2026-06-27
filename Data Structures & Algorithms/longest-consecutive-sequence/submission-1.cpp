class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // edge case
        if(nums.size() == 0){
            return 0;
        }

        // set store unique and sorted element
        set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }

        vector<int>temp;
        for(auto s:st){
            temp.push_back(s);
        }   
        
        int count = 1;
        int maxi = 1;
        for(int i=0;i<temp.size()-1;i++){
            if(temp[i] == temp[i+1]-1){
                count++;
                maxi = max(maxi,count);
            }else{
                count = 1;
            }
        }
        maxi = max(maxi,count);
        return maxi;


    }
};
