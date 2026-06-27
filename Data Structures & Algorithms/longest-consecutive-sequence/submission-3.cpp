class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // so we have to handle edge case aswell
        if(nums.size() == 0){
            return 0;
        }
        unordered_set<int> st(nums.begin(),nums.end());
        int maxi = 1;
        for(auto num : st){
            if(st.find(num-1) == st.end()){
                // num - 1 donot exist
                int len = 1;
                int current = num;
                while(st.find(current+1) != st.end()){
                    current++;
                    len++;
                }

                maxi = max(maxi,len);
            }
        }   
        return maxi;
    }
};
