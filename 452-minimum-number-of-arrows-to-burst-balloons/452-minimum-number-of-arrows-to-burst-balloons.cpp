// comparator function for sorting 2D vector
bool comp(vector<int> &x, vector<int> &y){
    return x[1] < y[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0) return 0; 
        sort(points.begin(), points.end(), comp);
        int arrows = 1;
        int end = points[0][1];
        
        for(int i = 1; i < points.size(); i++){
            if(points[i][0] > end){
                arrows++;
                end = points[i][1];
            }
        }
        return arrows;
    }
};