// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    
    static bool comp(pair<int,int> a,pair<int,int> b)
    {
        if(a.second==b.second) return a.first<b.first;
        return a.second<b.second;
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int> > v(n); //vector for storing pairs
        for(int i=0;i<n;i++) 
        v[i]={start[i],end[i]}; //made a vector as start and end
        sort(v.begin(),v.end(),comp); //sort using comparator
        int i=0;
        int j=1;
        int cnt=1; //because last will always be included so include cnt=1
        while(j<n) //iterate till last
        {
            if (v[i].second<v[j].first)
            {
                i=j;
                j++;
                cnt+=1;
            }
            else
            {
                j++;
            }
        }
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends