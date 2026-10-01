class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // edge case
        if(s1.length()>s2.length()){
            return false;
        }
        vector<int> freq1(26,0);
        for(int i=0;i<s1.length();i++){
            freq1[s1[i]-'a']++;
        }

        int left = 0;
        int right = 0;
        vector<int> freq2(26,0);
        while(right<s2.length()){
            freq2[s2[right]-'a']++;
            // comparison
            if(right-left+1 > s1.length()){
                // window size se bada hai
                freq2[s2[left]-'a']--;
                left++;
            }

            // comparison
            if(freq1 == freq2){
                return true;
            }
            right++;
        }
        return false;
    }
};
