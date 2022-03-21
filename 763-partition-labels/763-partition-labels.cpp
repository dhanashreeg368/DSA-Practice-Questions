class Solution {
public:
    vector<int> partitionLabels(string s) {
       unordered_map<char,int> mp; //map to store occurrences of character
       for(int i=0;i<s.size();i++)
       {
           char ch=s[i]; //store char
           mp[ch]=i; //store index(occurence)
       }   
       vector<int> ans; //to store ans
       int prev=-1; //starting occurence of letter
       int maxi=0; //max occurence of letter
       for(int i=0;i<s.size();i++)
       {
        maxi=max(maxi,mp[s[i]]);
        if (maxi==i) //if max occurence found
           {
                ans.push_back(maxi-prev); //push length
                prev=maxi; // max  becomes prev
           }    
       }
       return ans;               
    }
};