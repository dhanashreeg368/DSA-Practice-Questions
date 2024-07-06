class Solution {
public:
    int passThePillow(int n, int time) {
        int cycleLength = 2 * n - 2;
        int t = time % cycleLength;
        return (t < n) ? (t + 1) : (2 * n - 1 - t);      
    }
};