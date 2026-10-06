class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(int i=0;i<s.length();i++){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
                temp += s[i];
            }else if((s[i]>='A' && s[i]<='Z')){
                temp += s[i]-'A'+'a';
            }
        }
        int i=0;
        int j=temp.length()-1;
        while(i<=j){
            if(temp[i]!=temp[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
