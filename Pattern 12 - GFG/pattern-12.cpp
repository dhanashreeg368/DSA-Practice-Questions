//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        // spaces
        int spaces = 2*(n-1);
        
        for(int i=1;i<=n;i++) { //for rows
        
            //for printing number in rows - left side
            for(int j=1;j<=i;j++) {
                cout<<j<<" ";
            }
            
            //for printing spaces
            for(int j=1;j<=spaces;j++) {
                cout<<" "<<" ";
            }
            
            //for printing numbers
            for(int j=i;j>=1;j--) {
                cout<<j<<" ";
            }
            
            //next row
            cout<<endl;
            
            //after every row dec spaces
            spaces-=2;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends