class Solution {
public:
    int minimumPushes(string word) {
        
        if (word.length() < 8) { // if word is less than 8, return same
            return word.length();
        }
        vector<int> freqMap(26, 0); // freqMap to store frequency of every char
        
        for (char c: word) {
            freqMap[c - 'a']++; 
        }
        
        sort(freqMap.begin(), freqMap.end(), greater<int>()); // sort in desc order
        
        int totalPushes = 0;
        for(int i =0; i<26; i++) { 
            if (freqMap[i] == 0) { // if freq is zero, no char is present
                break;
            }
            totalPushes+=( i/8 + 1 )*freqMap[i]; // calculate total pushes
        }
        
        return totalPushes;
    }
};