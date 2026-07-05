class Solution {
public:
    bool isAnagram(string s, string t) {
        // edge case
        if(s.length() != t.length()){
            return false;
        }

        vector<int> freq1(26,0);
        vector<int> freq2(26,0);

        for(auto ch:s){
            freq1[ch-'a']++;
        }

        for(auto ch:t){
            freq2[ch-'a']++;
        }

        for(int i=0;i<26;i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }
};
