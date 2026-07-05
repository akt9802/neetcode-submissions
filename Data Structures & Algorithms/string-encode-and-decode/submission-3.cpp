class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString = "";
        for(int i=0;i<strs.size();i++){
            string temp = strs[i];

            int len = temp.length();
            encodedString += to_string(len);
            encodedString += '#';
            encodedString +=  temp;
        }
        return encodedString;
    }

    vector<string> decode(string s) {
        // decode part and also most difficult part
        int i = 0;
        vector<string> ans;
        while(i<s.length()){
            int j = i;
            while(s[j]!='#'){
                j++;
            }
            int len = stoi(s.substr(i,j-i));
            string word = s.substr(j+1,len);
            ans.push_back(word);
            i = j+len+1;
        }
        return ans;
    }
};
