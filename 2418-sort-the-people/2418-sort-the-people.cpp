class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string, greater<int>> mp;
        vector<string> ans;
        for(int i=0; i<heights.size(); i++) {
            mp[heights[i]]=names[i];
        }
        for(auto it: mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};