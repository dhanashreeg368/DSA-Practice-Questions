class Solution {
public:
    int fib(int n) {
        //base case
        if(n==1 || n==0) {
            return n;
        }
        
        int re1=fib(n-1);
        int re2=fib(n-2);
        
        return re1+re2;
    }
};