class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // task scheduler
        // cooldown period/CPU -> (n)

        vector<int>freq(26,0);

        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
        }

        int maxElementCount = 0;
        for(int i=0;i<26;i++){
            maxElementCount = max(maxElementCount,freq[i]);
        }

        int maxCount = 0;
        for(int i=0;i<26;i++){
            if(freq[i]==maxElementCount){
                maxCount++;
            }
        }
        int formula = (maxElementCount-1)*(n+1) + maxCount;
        return max((int)tasks.size(),formula);
    }
};
