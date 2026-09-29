class Solution {
public:
    struct Task{
        long long enqueueTime;
        long long processingTime;
        int index;
    };

    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> ans;
        int n = tasks.size();
        vector<Task> sortedTasks;
        for(int i=0;i<n;i++){
            sortedTasks.push_back({tasks[i][0],tasks[i][1],i});
        }

        // lets sort this on basis of enqueueTime
        // this is custome comparator 
        sort(sortedTasks.begin(),sortedTasks.end(),[](Task& a,Task& b){
            return a.enqueueTime < b.enqueueTime;
        });

        // now we have sorted Task
        // lets define priority queue(min Heap)
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        long long time = 0;
        int i = 0;
        while(i<n || !pq.empty()){
            
            // if pq.empty() hai
            while(pq.empty() && time<sortedTasks[i].enqueueTime){
                time = sortedTasks[i].enqueueTime;
            }

            // add all task that have arrived
            while(i<n && sortedTasks[i].enqueueTime <= time){
                pq.push({
                    sortedTasks[i].processingTime,sortedTasks[i].index
                });
                i++;
            }
            // now get time with smallest processing time from minHeap 
            long long processingTime = pq.top().first;
            long long index = pq.top().second;
            pq.pop();
            ans.push_back(index);
            time += processingTime;
        }
        return ans;
    }
};