This question can be solved using iterative and recursive approach.
​
**Iterative approch**:
Eg. [1,2,3]
Ans:
for 1: [],[1]
for 2: [],[1],[2],[1,2]
for 3: [],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]
​
This can be done iteratively till n
```
class Solution {
public:
vector<vector<int>> subsets(vector<int>& nums) {
if(nums.empty()) return {{}}; //if empty return {}
vector<vector<int>> result={{}}; //result for all subset
for(int x:nums)
{
int n=result.size();
for(int i=0;i<n;i++)
{
vector<int> r=result[i]; //store current subset
r.push_back(x);
result.push_back(r);
}
}
return result;
}
};
```
​
​