class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int mx=-1;
        while(i<j)
        {
            mx=max(mx,min(height[i],height[j])*(j-i));
            if (height[i]<height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return mx;
    }
};