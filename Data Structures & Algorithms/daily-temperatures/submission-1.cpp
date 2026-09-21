class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        // O(n*n) for brute force : will not work
        // daily temperature

        vector<int> ans(arr.size(),0);
        stack<pair<int,int>> st;
        for(int i=0;i<arr.size();i++){
            int temp = arr[i];
            while(st.empty()==false && temp>st.top().first){
                auto pair = st.top();
                st.pop();
                ans[pair.second] = i-pair.second;
            }
            st.push({arr[i],i});
        }
        return ans;
    }
};
