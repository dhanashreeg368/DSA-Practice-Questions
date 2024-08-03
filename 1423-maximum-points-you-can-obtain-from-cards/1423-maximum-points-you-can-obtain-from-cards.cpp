class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0; // calculate left sum
        int rsum = 0; // calculate right sum 
        int maxSum = 0; // calculates maximum sum
        int n = cardPoints.size(); // size of array
        
        for(int i=0; i<k; i++) { // sum of first k left numbers 
            lsum = lsum + cardPoints[i];
            maxSum = lsum; // max will be leftsum initially
        }
        
        int rindex = n-1; // right index at last pos
        // now we will be shrinking elements one by one from left and adding one by one from right
        for (int i=k-1; i>=0; i--) { // for index - (k=4) 0, 1, 2 ,3
            lsum = lsum - cardPoints[i]; // remove from lsum
            rsum = rsum + cardPoints[rindex]; // add in rsum
            
            maxSum = max(maxSum, lsum + rsum); // find max sum
            rindex = rindex - 1; // dec rindex for every iteration
        }
        return maxSum;
    }
};