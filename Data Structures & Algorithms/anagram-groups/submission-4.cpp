class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mpp;
        vector<vector<string>> ans;
        for(int i=0;i<strs.size();i++){

            string temp = strs[i];
            sort(temp.begin(),temp.end());
            mpp[temp].push_back(strs[i]);
        }
        for(auto mp : mpp){
            ans.push_back(mp.second);
        }

        return ans;
    }
};
