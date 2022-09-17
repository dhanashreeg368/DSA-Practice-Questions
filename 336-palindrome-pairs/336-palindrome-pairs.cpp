class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string_view, int> m;
        for (int i = 0; i < size(words); i++) m[words[i]] = i;
        for (int i = 0; i < size(words); i++) {
            string rw = {rbegin(words[i]), rend(words[i])};
            string_view sv = words[i], rsv = rw;
            for (int len = 0; len <= size(sv); len++) {
                auto prefix = sv.substr(0, len), suffix = sv.substr(len);
                if (equal(begin(prefix), begin(prefix)+size(prefix)/2, rbegin(prefix))) {
                    auto it = m.find(rsv.substr(0, size(rsv)-len));
                    if (it != end(m) && it->second != i)
                        ans.push_back({it->second, i});
                }
                if (suffix.empty()) continue;
                if (equal(begin(suffix), begin(suffix)+size(suffix)/2, rbegin(suffix))) {
                    auto it = m.find(rsv.substr(size(rsv)-len));
                    if (it != end(m) && it->second != i)
                        ans.push_back({i, it->second});
                }
            }
        }
        return ans;
    }
};