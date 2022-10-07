class MyCalendarThree {
public:
    map<int, int> mp;
    
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int maxi = 0;
        int sum = 0;
        for(auto i : mp) {
            sum += i.second;
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */