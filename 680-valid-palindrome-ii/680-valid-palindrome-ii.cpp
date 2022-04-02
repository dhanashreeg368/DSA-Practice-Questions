class Solution {
public:
    bool validPalindrome(string s) {
        //can be solved using 2 pointers 
       int start=0; //start
       int end=s.size()-1; //end
       int cnt=0;
       while(start<end)
       {
           if (s[start] == s[end])
           {
               start++;
               end--;
           }
           else
           {
               cnt++;
               start++;
           }
           if (cnt>1)
           {
               break;
           }
       }
       
       //reinitialze pointer
       start=0;
       end=s.size()-1;
       int cnt1=0;
       while(start<end)
       {
           if (s[start] == s[end])
           {
               start++;
               end--;
           }
           else
           {
               cnt1++;
               end--;
           }
           if (cnt1>1)
           {
               break;
           }
       }  
        
       if (cnt==1 || cnt1==1) //deleting atmost one char 
       {
           return true;
       }
       if (cnt==0 || cnt1==0) //palindrome
       {
           return true;
       } 
       return false;
    }
};