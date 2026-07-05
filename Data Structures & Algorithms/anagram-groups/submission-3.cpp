class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        // given : strs[i] made up of lower case english letter
        map<string,vector<string>> mpp;
        for(int i=0;i<strs.size();i++){
            string temp = strs[i];
            // sort(temp.begin(),temp.end());
            // without sorting lets try
            vector<int> freq(26,0);
            for(auto ch:temp){
                freq[ch-'a']++;
            }
            string tempWithHash = "";
            for(auto it:freq){
                if(it != 0){
                    tempWithHash += it;
                }else{
                    tempWithHash += '#';
                }
            }
            mpp[tempWithHash].push_back(strs[i]);
        }

        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
