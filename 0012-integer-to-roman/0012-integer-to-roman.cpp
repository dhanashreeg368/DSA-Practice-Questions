class Solution {
public:
    string intToRoman(int num) {
        map<int,string> mp;
        mp[1]="I" ; mp[5]="V" ; mp[10]="X";
        mp[50]="L" ; mp[100]="C" ; mp[500]="D"; mp[1000]="M";
        mp[4]="IV" ; mp[9]="IX";
        mp[40]="XL" ; mp[90]="XC";
        mp[400]="CD" ; mp[900]="CM";
        
        string str;
        auto itr = mp.end();
        itr--;
        while(itr!=mp.begin()){
            int times = num/itr->first;
            while(times--)
                str += itr->second;
            num %= itr->first;
            itr--;
        }
        if (num!=0){
            while(num--)
                str += "I";
        }
        return str;
    }
};