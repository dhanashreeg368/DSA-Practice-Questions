class Solution {
using Window = array<int,5>;
    bool isIntervalValid( const Window& w ){
        // If interval is valid, w should satisfy w[0] < w[1] < w[2] > w[3] > w[4].
        return w[1] <= w[2] && w[3] <= w[2] &&
               w[0] <= w[1] && w[4] <= w[3] &&
        // w[3] + w[0] < w[2] will cause subsequence length < 2.
        // w[1] + w[4] < w[2] will cause subsequence length < 2.
               w[1] + w[4] >= w[2] && w[0] + w[3] >= w[2] ;
    }
public:
    bool isPossible(vector<int>& nums) {
        auto size{nums.size()};
        if ( size < 3 ) return false;
        int pivot{nums[0]};
        Window counts{0,0,0,0,0};
        for ( auto n : nums ){
            switch ( n - pivot ){
                case 0 :
                    ++counts[4];
                    continue;
                case 1 :
                    if ( counts[3] < counts[2] ){
                        if ( min( counts[0], counts[1] ) < counts[2] - counts[3] )
                            return false;
                        counts[1] -= counts[2] - counts[3];
                        counts[2] = counts[3];
                    }
                    rotate( counts.begin(), counts.begin()+1, counts.end() );
                    break;
                default :
                    if ( !isIntervalValid(counts) )
                        return false;
                    counts.fill(0);
            }
            counts[4] = 1;
            pivot = n;
        }
        return isIntervalValid(counts);
    }
};