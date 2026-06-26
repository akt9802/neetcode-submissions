class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // without sorting

        string prefix = strs[0];
        for(int i=1;i<strs.size();i++){
            int j = 0;
            int k = 0;
            while(j < strs[i].length()){
                if(prefix[k]==strs[i][j]){
                    k++;
                    j++;
                }else{
                    break;
                }
            }
            prefix = "";
            for(int n=0;n<j;n++){
                prefix += strs[i][n];
            }
        }
        return prefix;
    }
};