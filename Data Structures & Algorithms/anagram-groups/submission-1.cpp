class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // without sorting 
        // using freq array 

        unordered_map<string,vector<string>> mpp;

        for(int i=0;i<strs.size();i++){
            vector<int> freq(26,0);

            for(char ch: strs[i]){
                freq[ch-'a']++;
            }

            // build unique string(aka key)
            string key = "";
            for(auto x : freq){
                if(x != 0){
                    key += x;
                }else{
                    key += '#';
                }
            }


            mpp[key].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto pair:mpp){
            ans.push_back(pair.second);
        }
        return ans;

    }
};
