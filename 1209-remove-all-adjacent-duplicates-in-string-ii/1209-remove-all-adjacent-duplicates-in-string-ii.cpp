class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> st; //make stack for character and cnt
        for(auto c:s) //for iterating c in s
        {
            if(st.size()==0 || st.back().first!=c) //if stack is empty or top element is not matching with current then push new element in stack
            {
                st.push_back({c,1}); //insert first character then
                    
            }
            else
            {
                st.back().second++;
            }
            if(st.back().second==k) //if k elements are equal
            {
                st.pop_back(); //then pop
            }
        }
        string ans;
        for(auto x:st)
        {
            ans.append(x.second,x.first);
        }
        return ans;
    }
    
};