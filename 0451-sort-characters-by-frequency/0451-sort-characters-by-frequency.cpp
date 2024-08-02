class Solution {
public:
    string frequencySort(string s) {
        string ans;
        priority_queue<pair<int, char>> pq; // max-heap to store in dec order
        unordered_map<char, int> mp; // map to store freq
        
        // add char and its frequency in map
        for(char ch: s) {
            mp[ch]++;
        }
        
        // add pairs in max-heap (stores in decreasing order )
        for(auto it: mp) {
            pq.push({it.second, it.first}); 
        }
        
        // while max heap is not empty, remove one by one put in ans
        while(!pq.empty()) {
            auto it = pq.top();
            char ch = it.second;
            int freq = it.first;
            
            pq.pop();
            
            while(freq>0) {
                ans+=ch;
                freq--;
            }
        }
        return ans;
    }
};