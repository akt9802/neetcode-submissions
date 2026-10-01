class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // we will take two pointer
        int ans = 0;
        int left = 0;
        int right = 0;
        // map
        unordered_map<char,int> mpp;
        while(right<s.length()){
            if(mpp.find(s[right]) != mpp.end()){
                // this means this char exist in map
                left = max(left,mpp[s[right]]+1);
            }
            ans = max(ans,right-left+1);
            mpp[s[right]]=right;
            right++;
        }
        return ans;
    }
};
