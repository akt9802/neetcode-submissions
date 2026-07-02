class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n = people.size();
        int count = 0;
        // try to pair heaviest with lightest
        int i=0;
        int j=n-1;
        while(i<=j){
            if(people[i]+people[j]<=limit){
                // both will go together
                i++;
                j--;
            }else if(people[i]>=people[j]){
                // i will go alone
                i++;
            }else if(people[i]<people[j]){
                // j will go alone
                j--;
            }
            count++;
        }
        return count;
    }
};