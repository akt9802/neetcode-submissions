class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_str = "";
        for(int i=0;i<strs.size();i++){
            string temp = strs[i];
            int size = temp.length();
            string ans = "";
            ans += to_string(size);
            ans += '#';
            ans += temp;
            encoded_str += ans;
        }
        return encoded_str;
    }

    vector<string> decode(string s) {
        int i=0;
        vector<string> ans;
        while(i<s.length()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }

            int len = stoi(s.substr(i, j-i));  
            string word = s.substr(j+1, len);  
            ans.push_back(word);
            i = j+1+len;  
        }
        return ans;
    }
};
