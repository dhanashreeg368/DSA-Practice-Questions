class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        multiset<int> st;
        map<int, vector<int> > mp;
        
        for(auto &b: buildings){
            mp[b[0]].push_back(b[2]);
            mp[b[1]].push_back(-b[2]);
        }
        
        vector<vector<int> > ans;
        
        for(auto& [c,vec] : mp){
            for(auto &x: vec){
                if(x > 0){
                    st.insert(x);
                }
                else{
					//we can't erase the value directly because this would erase all copies of this value in the multiset. 
					//Instead we need to erase it by using a pointer to it. 
					// It is guaranteed that at least one copy of this value exists as we erase it. 
                    st.erase(st.lower_bound(-x)); 	
                }
            }

            
            int val = st.empty() ? 0 : *st.rbegin();
            
            if(ans.empty() || (ans.size() && ans.back()[1] != val)){
                ans.push_back({c, val});
            }
        }
        return ans;
    }
};