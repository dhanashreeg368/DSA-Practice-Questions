class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans; // stores ans
        
        // sort both the arrays
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int start1=0;
        int start2=0;
        
        while(start1!=nums1.size() && start2!=nums2.size()) {
            if (nums1[start1]==nums2[start2]) { // if both equal - put them in vector and fwd both ptrs 
                ans.push_back(nums1[start1]);
                start1+=1;
                start2+=1;
            }else if (nums1[start1]<nums2[start2]) { 
                start1+=1;
            }
            else {
                start2+=1;
            }
        }
        return ans;
    }
};