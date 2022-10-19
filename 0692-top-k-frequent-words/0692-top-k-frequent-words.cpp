class Solution {
public:
    // Comparator for increasing frequency and lexicographical order.
    static bool comparator(pair<string,int> a,pair<string,int> b){
        if(a.second==b.second){
            return a.first<b.first; // lexicographic
        }
        return a.second>b.second; // frequency
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
        unordered_map<string,int> hashmap;
        for(int i=0;i<n;i++){  // frequency of unique words
            hashmap[words[i]]++;
        }
        vector<pair<string,int>> freq; // using freq array for sorting
        for(auto itr : hashmap){  
            freq.push_back(make_pair(itr.first,itr.second));
        }
        sort(freq.begin(),freq.end(),comparator);  //sort here
        vector<string> ans;
        for(int i=0;i<k;i++){  // add top k elements to ans.
            ans.push_back(freq[i].first);
        }
        
        return ans;
    }
};