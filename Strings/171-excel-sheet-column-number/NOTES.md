Approach:
Similar to binary to decimal conversion keeping base as 26
​
To convert ABC:
Eg. ABC
A => (1)(26^2)
B => (2)(26^1)
C => (3)(26^0)
Result => ( Ans of A + Ans of B + Ans of C)
=> 676 + 52 + 3
=> 731
​
C++ Easy Solution
```
class Solution {
public:
int titleToNumber(string columnTitle) {
// This process is similar to binary-to-decimal conversion
int res = 0;
for (const auto& c : columnTitle)
{
res *= 26;
res += c  - 'A' + 1;
}
return res;
}
};
```
​
​