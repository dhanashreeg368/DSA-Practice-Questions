class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end()); //sort the vector
        int i=0,j=people.size()-1; //i for light person and j for heavy person
        int cnt=0; //cnt is zero
        while(i<=j)
        {
            if(people[i]+people[j]<=limit)
            {
                i++;
                j--;
            }
            else
            {
                j--;
            }
            cnt++;
        }
        return cnt;        
    }
};