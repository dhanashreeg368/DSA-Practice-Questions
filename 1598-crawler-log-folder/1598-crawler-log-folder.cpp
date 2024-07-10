class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt =0;
        for (int i=0; i<logs.size(); i++) {
            string operation=logs[i];
            if (operation == "../") {
                cnt = cnt - 1;
            } else if (operation == "./") {
                continue;
            }
            else {
                cnt = cnt+1;
            }
            if (cnt<0) {
                cnt=0;
            }
        }
        return cnt;
    }
};