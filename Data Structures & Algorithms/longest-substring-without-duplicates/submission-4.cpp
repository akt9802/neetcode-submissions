class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // brute force generate all substring
        int maxi = 0;
        for(int i=0;i<s.length();i++){
            int tempMax = 0;
            vector<int> hash(255,0);
            for(int j=i;j<s.length();j++){
                if(hash[s[j]] == 0){
                    hash[s[j]] = 1;
                    tempMax = max(tempMax,j-i+1);
                }else{
                    break;
                }
            }
            maxi = max(maxi,tempMax);
        }
        return maxi;
    }
};
