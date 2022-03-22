class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n,'a'); //initialze string with all a 
        k-=n; //decrease the value of k
        while(k>0) //iterate till k greater than zero
        {
            ans[--n]+=min(25,k); //place higher number at last index and so on 
            k-=min(25,k); //decrement k everytime
        }
        return ans; //return final string
    }
};