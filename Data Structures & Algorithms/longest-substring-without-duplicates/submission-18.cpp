class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // if(s.length()==1){
        //     return 1;
        // }
        int left = 0;
        int right = 0;
        int longestSubstringLength = 0;
        // map<char,int> mpp;
        // we can remove this map
        vector<int> hash(256,-1);
        while(right<s.length()){
            if(hash[s[right]]!=-1){
                left = max(left,hash[s[right]]+1);
                hash[s[right]]=right;
            }

            longestSubstringLength = max(longestSubstringLength,right-left+1);
            hash[s[right]]=right;
            right++;
        }
        return longestSubstringLength;
    }
};
