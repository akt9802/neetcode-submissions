class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int left = 0;
        int right = 0;
        int maxFrequency = 0;
        vector<int> freq(26,0);

        while(right<s.length()){
            freq[s[right]-'A']++;
            maxFrequency = max(maxFrequency,freq[s[right]-'A']);

            while((right-left+1)-maxFrequency>k){
                // window is invalid
                freq[s[left]-'A']--;
                left++;
            }
            ans = max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};
