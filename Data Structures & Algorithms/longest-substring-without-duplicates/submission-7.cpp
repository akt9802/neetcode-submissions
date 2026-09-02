class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // brute force 
        int n = s.length();
        int ans = 0;
        for(int i=0;i<n;i++){
            vector<int>hash(256,0);
            for(int j=i;j<n;j++){
                if(hash[s[j]] != 0){
                    // this is repeating
                    break;
                }
                hash[s[j]] = 1;
                ans = max(ans,j-i+1);
            }
        }
        return ans;
    }
};
