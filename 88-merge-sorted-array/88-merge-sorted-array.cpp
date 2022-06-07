class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        if (m==0)
        {
           nums1=nums2;
        }
        while(i>=0 && j>=0)
        {
            if(nums1[i]>=nums2[j]) //put greater element in nums1
            {
                nums1[k]=nums1[i];
                k--;
                i--;
            }
            else
            {
                nums1[k]=nums2[j]; //put greater element in nums1
                k--;
                j--;
            }
        }
        while(i>=0) //if elements in i are remaining add to nums1
        {
            nums1[k]=nums1[i];
            k--;
            i--;
        }
        while(j>=0) //if elements in j are remaining add to nums2
        {
            nums1[k]=nums2[j];
            k--;
            j--;
        }
    }
};