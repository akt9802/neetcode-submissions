class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // edge case
        if(s1.length() > s2.length()){
            return false;
        }

        // we can try for sliding window
        // we can take 2 freq array
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);

        for(auto ch:s1){
            freq1[ch-'a']++;
        }

        int left = 0;
        int right = 0;
        while(right<s2.length()){
            freq2[s2[right]-'a']++;
            // we have to maintain fixed window size of s1 length
            if(right-left+1 > s1.length()){
                freq2[s2[left]-'a']--;
                left++;
            }

            // now matching part
            if(right-left+1 == s1.length()){
                // we have to match both freq array
                bool flag = true;
                for(int i=0;i<26;i++){
                    if(freq1[i]!=freq2[i]){
                        flag = false;
                    }
                }
                if(flag == true){
                    return true;
                }
            }
            right++;
        }
        return false;
    }
};
