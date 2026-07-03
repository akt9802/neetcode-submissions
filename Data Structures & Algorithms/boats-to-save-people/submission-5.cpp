class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i = 0;
        int j = people.size()-1;
        int requiredBoats = 0;
        while(i<=j){
            if(people[i]+people[j]<=limit){
                // both will go together
                i++;
                j--;
            }
            else if(people[i]>=people[j]){
                // i will go alone 
                i++;
            }
            else if(people[i]<people[j]){
                // j will go alone
                j--;
            }
            requiredBoats++;
        }
        return requiredBoats;
    }
};