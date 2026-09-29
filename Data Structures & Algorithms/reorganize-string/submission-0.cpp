class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";
        vector<int> freq(26,0);
        for(auto ch:s){
            freq[ch-'a']++;
        }
        // now we have count 
        // we have use heap (maxHeap)
        vector<pair<int,char>> temp;
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                temp.push_back({freq[i],'a'+i});
            }
        }
        priority_queue<pair<int,char>> pq;
        for(int i=0;i<temp.size();i++){
            pq.push({temp[i].first,temp[i].second});
        }

        // we have priority queue
        while(!pq.empty()){
            int count1 = pq.top().first;
            char ch1 = pq.top().second;
            pq.pop();
            ans += ch1;
            count1--;
            if(!pq.empty()){
                int count2 = pq.top().first;
                char ch2 = pq.top().second;
                pq.pop();
                ans += ch2;
                count2--;
                if(count2>0){
                    pq.push({count2,ch2});
                }
            }else if(pq.empty() && count1>0){
                return "";
            }
            if(count1>0){
                pq.push({count1,ch1});
            }
        }
        if(s.length() != ans.length()){
            return "";
        }else{
            return ans;
        }
    }
};