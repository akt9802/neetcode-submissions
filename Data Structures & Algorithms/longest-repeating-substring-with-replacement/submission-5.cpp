class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        int maxLength = 0;
        int maxFreq = 0;
        map<char,int> mpp;
        while(right<s.length()){
            mpp[s[right]]++;
            maxFreq = max(maxFreq,mpp[s[right]]);

            // we have to check for valid window
            while(right-left+1 - maxFreq > k){
                // we need to shrink the window
                mpp[s[left]]--;
                left++;
            }
            maxLength = max(maxLength,right-left+1);
            right++;
        }
        return maxLength;
    }
};
