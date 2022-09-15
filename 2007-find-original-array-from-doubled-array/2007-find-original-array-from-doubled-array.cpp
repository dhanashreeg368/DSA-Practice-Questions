class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()%2==1) return {};
        sort(changed.begin(), changed.end());
        unordered_map<int,int> map;
        vector<int> v;
        for(auto &el: changed) {
            if(map[el*2]) map[el*2]--, v.push_back(el);
            else if(el%2==0 && map[el/2]) map[el/2]--, v.push_back(el/2);
            else map[el]++;
        }
        for(auto &pair:map) if(pair.second != 0) return {};
        return v;
    }
};