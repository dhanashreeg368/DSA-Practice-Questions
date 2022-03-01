class Solution {
public:
    vector<int> countBits(int n) {
        vector <int> l; //for answer 
        l.push_back(0); //initially zero
        for(int i=1;i<n+1;i++) //iterating through elements 
        {
            if (i%2==0) //even
            {
                l.push_back(l[i/2]);
            }
            else //odd
            {
                l.push_back(l[i/2] + 1);             
            }
        }
        return l;
    }
};