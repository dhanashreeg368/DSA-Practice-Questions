class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        //check if minHeap size exceeds given K
        if(minHeap.size()>k) {
            minHeap.pop();
        }
        //return top element which is the k-th largest element
        return minHeap.top();
    }
private:
    int k;
    priority_queue<int,vector<int>,greater<int>> minHeap; // minHeap will store the stream 
};


/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */