class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // if(s.length()==1){
        //     return 1;
        // }
        int left = 0;
        int right = 0;
        int longestSubstringLength = 0;
        map<char,int> mpp;
        while(right<s.length()){
            if(mpp.find(s[right])!=mpp.end()){
                left = max(left,mpp[s[right]]+1);
                mpp[s[right]]=right;
            }

            mpp[s[right]] = right;
            right++;
            longestSubstringLength = max(longestSubstringLength,right-left);
        }
        return longestSubstringLength;
    }
};
