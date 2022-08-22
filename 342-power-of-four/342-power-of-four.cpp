class Solution {
public:
    bool isPowerOfFour(int n) {
        double x=log(n)/log(4);
        if(n>0 && x==int(x)) {
            return true;
        } else {
            return false;
        }
    }
};