class Solution {
public:
    bool check(string s,int left,int right){
        while(left <= right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        // valid palindrome 2
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return check(s,i+1,j) || check(s,i,j-1);
            }
            i++;
            j--;
        }
        return true;
    }
};