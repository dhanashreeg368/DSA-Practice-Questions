class Solution {
public:
    bool Checkcommon(bitset<26> &a, bitset<26> &b)
    {
        for(int i=0;i<26;i++)
        {
            if (a[i] && b[i])
                return true;
        }
        return false;
    }
    int maxProduct(vector<string>& words) {
        int n=words.size(); //size of array
        int ans=0; //initialise answer 
        vector<bitset<26>> chars(n); //bitset for storing letters 
        for (int i=0;i<n;i++) //iterate over all words 
        {
            for(auto &ch:words[i]) //iterate over all characters in words[i]
            {
                chars[i][ch-'a']=1; //set bitset to 1 
            }
            for (int j=0;j<i;j++) //check with other words 
            {
                if(!Checkcommon(chars[i],chars[j]))
                {
                    ans=max(ans, (int)words[i].size()*(int)words[j].size());
                }
            }
        }
        return ans;
    }
};