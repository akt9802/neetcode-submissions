class Solution {
public:
    string minWindow(string s, string t) {

        // edge case
        if(t.length() > s.length()){
            return "";
        }

        vector<int>freq1(256,0);    // current window
        vector<int>freq2(256,0);    // for string t

        for(auto ch:t){
            freq2[ch]++;
        }

        int left = 0;
        int right = 0;

        int minLength = INT_MAX;
        int start = 0;

        while(right < s.length()){

            // Add current character
            freq1[s[right]]++;

            // Check whether current window is valid
            bool flag = true;

            for(int i = 0; i < 256; i++){
                if(freq1[i] < freq2[i]){
                    flag = false;
                    break;
                }
            }

            // If window is valid, try shrinking from left
            while(flag == true){

                // Current window is valid
                int length = right - left + 1;

                // Save smallest window
                if(length < minLength){
                    minLength = length;
                    start = left;
                }

                // Remove left character
                freq1[s[left]]--;
                left++;

                // Check again whether window is valid
                flag = true;

                for(int i = 0; i < 256; i++){
                    if(freq1[i] < freq2[i]){
                        flag = false;
                        break;
                    }
                }
            }

            // Continue expanding
            right++;
        }

        if(minLength == INT_MAX){
            return "";
        }

        string result = "";

        for(int i = start; i < start + minLength; i++){
            result += s[i];
        }

        return result;
    }
};