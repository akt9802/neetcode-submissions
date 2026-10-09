class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // we can use maxHeap
        priority_queue<int> pq;
        for(int i=0;i<stones.size();i++){
            // push -> O(log n) because pq is using Heap 
            // and Heap is complete binary tree
            pq.push(stones[i]);
        }

        while(pq.size()>1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            if(x<y){
                pq.push(y-x);
            }else if(x>y){
                pq.push(x-y);
            }
        }
        if(pq.size() == 0){
            return 0;
        }
        return pq.top();
    }
};
