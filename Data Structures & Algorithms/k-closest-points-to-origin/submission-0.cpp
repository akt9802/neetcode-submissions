class Solution {
public:
    int findDistance(vector<int> point){
        int dis = (point[0]*point[0]) + (point[1]*point[1]);
        return dis;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // we can use heap -> maxHeap
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<points.size();i++){
            int distance = findDistance(points[i]);
            // now we have distance
            pq.push({distance,{points[i][0],points[i][1]}});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        for(int i=0;i<k;i++){
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};
