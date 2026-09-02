class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // optimal approach 
        int left = 0;
        int right = 0;
        int ans = 0;
        vector<int>hash(256,-1);
        while(right<s.length()){
            if(hash[s[right]] != -1){
                left = max(left,hash[s[right]]+1);
            }
            ans = max(ans,right-left+1);
            hash[s[right]] = right;
            right++;
        }
        return ans;
    }
};
