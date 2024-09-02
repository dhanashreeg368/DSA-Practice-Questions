class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long  totalchalk=0;
        for(int i=0; i<chalk.size(); i++) {
            totalchalk=totalchalk+chalk[i];
        }
        k= k % totalchalk;
        for(int i=0;i<chalk.size();i++) {
            if(k<chalk[i]) {
                return i;
            }
            k=k-chalk[i];
        }
        return 0; 
    }
};