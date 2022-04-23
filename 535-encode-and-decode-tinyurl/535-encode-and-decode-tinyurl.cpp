class Solution {
public:
    map<string, string> mp; //map to store long and short url;
    int num=0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        num++; //increment number 
        string addon=to_string(num); //addon to short url- unique number 
        string ans="http://tinyurl.com/";
        ans+=(string)addon; //add addon to short url
        mp[ans]=longUrl; //store longurl
        return ans;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));