class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(const string& detail : details) {
            int start = 11;
            int length= 2;
            string ageString = detail.substr(start, length);
            int ageNumber = stoi(ageString);
            if (ageNumber>60) {
                count+=1;
            }
        }
        return count;
    }
};