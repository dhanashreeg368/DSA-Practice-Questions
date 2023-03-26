//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        
        //first row starts by printing a single one
        int start = 1; 
        
        //iterating through rows
        for(int i=0;i<n;i++) {  
            if (i%2==0) {   //if even row
                start = 1;  //start by printing 1
            }
            else {  //odd row start by printing 0
                start = 0;
            }
            
            //for printing cols in a specific row
            for(int j=0;j<=i;j++) { 
                cout<<start<<" ";    //print
                start=1-start;  //decrement start value to zero
            }
            cout<<endl;
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